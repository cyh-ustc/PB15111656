## clang static analyzer

### 3 学习现有的checker

#### 3.1 对程序绘制AST、CFG和exploded graph

5 简要说明test.c、AST.svg、CFG.svg和ExplodedGraph.svg之间的联系与区别

test.c: 程序代码

AST: 抽象语法树

CFG: 控制流图

exploded graph: The analyzer core performs symbolic execution of the given program. All the input values are represented with symbolic values; further, the engine deduces the values of all the expressions in the program based on the input symbols and the path. The execution is path sensitive and every possible path through the program is explored. The explored execution traces are represented with ExplodedGraph object. Each node of the graph is ExplodedNode, which consists of a ProgramPoint and a ProgramState. 

联系：
ast通过程序代码构建，cfg通过ast构建，exploded graph通过对cfg路径访问构建；

区别：
ast是抽象语法层级，对路径不敏感；cfg对程序路径敏感，包含了程序点；exploded graph是路径敏感的并包含所有可能的路径，包含程序点和状态

#### 3.2 Static Analyzer Overview

1. Checker 对于程序的分析主要在 AST 上还是在 CFG 上进行?

主要在CFG上进行

2. Checker 在分析程序时需要记录程序状态,这些状态一般保存在哪里?

Checkers often need to keep track of information specific to the checks they perform. However, since checkers have no guarantee about the order in which the program will be explored, or even that all possible paths will be explored, this state information cannot be kept within individual checkers. Therefore, if checkers need to store custom information, they need to add new categories of data to the ProgramState. The preferred way to do so is to use one of several macros designed for this purpose. 

3. 简要解释分析器在分析下面程序片段时的过程,在过程中产生了哪些symbolic values? 它们的关系是什么?

```cpp
int x = 3, y = 4;
int *p = &x;
int z = *(p + 1);
```

symbolic value:
$0:x(第二个x)
$1:&x
$2:p
$3:p + 1
$4:*(p + 1)
它们的关系:
$1为$0取址
$3为$2左值转为右值+1
$4为$3取值

#### 3.3

1. 
Smart pointers：

* unique_ptr(C++11)
 
std::unique_ptr is a smart pointer that owns and manages another object through a pointer and disposes of that object when the unique_ptr goes out of scope.



* shared_ptr(C++11)
 
std::shared_ptr is a smart pointer that retains shared ownership of an object through a pointer. Several shared_ptr objects may own the same object. 

* weak_ptr(C++11)
 
weak reference to an object managed by std::shared_ptr 

（llvm里没找到weak_ptr）

2.
In an effort to reduce code and executable size, LLVM does not use RTTI (e.g. dynamic_cast<>;) or exceptions. These two language features violate the general C++ principle of “you only pay for what you use”, causing executable bloat even if exceptions are never used in the code base, or if RTTI is never used for a class. Because of this, we turn them off globally in the code.
That said, LLVM does make extensive use of a hand-rolled form of RTTI that use templates like isa<>, cast<>, and dyn_cast<>. This form of RTTI is opt-in and can be added to any class. It is also substantially more efficient than dynamic_cast<>.

3.

用arrayref和stringref

The llvm::ArrayRef class is the preferred class to use in an interface that accepts a sequential list of elements in memory and just reads from them. By taking an ArrayRef, the API can be passed a fixed size array, an std::vector, an llvm::SmallVector and anything else that is contiguous in memory.


The StringRef data type represents a reference to a constant string (a character array and a length) and supports the common operations available on std::string, but does not require heap allocation.

It can be implicitly constructed using a C style null-terminated string, an std::string, or explicitly with a character pointer and length. For example, the StringRef find function is declared as:

iterator find(StringRef Key);

4.

Anonymous namespaces are a great language feature that tells the C++ compiler that the contents of the namespace are only visible within the current translation unit, allowing more aggressive optimization and eliminating the possibility of symbol name collisions. Anonymous namespaces are to C++ as “static” is to C functions and global variables. While “static” is available in C++, anonymous namespaces are more general: they can make entire classes private to a file.

make anonymous namespaces as small as possible, and only use them for class declarations.

#### 3.4


1. 这个 checker 对于什么对象保存了哪些状态?保存在哪里?

对FileDesc保存StreamState，通过宏保存在ProgramState里
 

`REGISTER_MAP_WITH_PROGRAMSTATE(StreamMap, SymbolRef, StreamState)`


2. 状态在哪些时候会发生变化?

`checkPostCall`时

`State = State->set<StreamMap>(FileDesc, StreamState::getOpened());`

`checkPreCall`时

`State = State->set<StreamMap>(FileDesc, StreamState::getClosed());`

`checkDeadSymbols`时

`State = State->remove<StreamMap>(Sym);`

`checkPointerEscape`时
`State = State->remove<StreamMap>(Sym);`

3. 在哪些地方有对状态的检查?

`checkPreCall`中
```cpp
const StreamState *SS = State->get<StreamMap>(FileDesc);
  if (SS && SS->isClosed()) {
    reportDoubleClose(FileDesc, Call, C);
    return;
```

`checkDeadSymbols`中
```cpp
 StreamMapTy TrackedStreams = State->get<StreamMap>();
  for (StreamMapTy::iterator I = TrackedStreams.begin(), E = TrackedStreams.end(); I != E; ++I) {
    SymbolRef Sym = I->first;
    bool IsSymDead = SymReaper.isDead(Sym);
```
4. 函数SimpleStreamChecker::checkPointerEscape的逻辑是怎样的?实现了什么功能?用在什么地方?

当PointerEscapeKind为PSK_DirectEscapeOnCall并且call cannot close a file时，不能做什么；
不然就把Escaped在状态中StreamMap清空

5. 根据以上认识,你认为这个简单的checker能够识别出怎样的bug?又有哪些局限性?请给出测试程序及相关的说明。

能够识别出：
* 打开文件前使用
* 关闭文件后使用
* 多次关闭一个文件指针

测试例在`sa/test/ssc/`下

局限性的一个例子：

```c
int main()
{
	FILE *f = fopen("1.c","r");
	FILE *k;
	fclose(k);
	FILE *g = fopen("2.c","r");
	fclose(f);
	f = g + 1;
	fclose(f);
}
```

对于未open就close的k可以识别；但对于g+1赋值给f后close并不会报错

#### 3.5

1. 增加一个checker需要增加哪些文件?需要对哪些文件进行修改?

* 需要编写checker的程序文件在`lib/StaticAnalyzer/Checkers`
* 需要在checker程序里面增加注册代码
* 需要修改checker的表格文件`include/clang/StaticAnalyzer/Checkers/Checkers.td`中相关section


2. clang_tablegen 函数的作用

根据checkers.td来生成相关make

3. .td文件的作用是什么?它是怎样生成C++头文件或源文件的?这个机制有什么好处?

.td文件为表格，如`Checkers.td`为checker的表格，作用是注册相关的部分和文件

通过DescFile指定文件

好处： 方便新增，删除，修改；与cmake分离，不需要直接修改cmake


### 4 扩展要求

#### 4.1 分析现有 checker 的缺陷

除了这些缺陷以外, clang静态分析器还有哪些缺陷?

Enhance CFG to model C++ temporaries properly.

There is an existing implementation of this, but it's not complete and is disabled in the analyzer. (Difficulty: Medium; current contact: Alex McCarthy)
Enhance CFG to model exception-handling properly.

Currently exceptions are treated as "black holes", and exception-handling control structures are poorly modeled (to be conservative). This could be much improved for both C++ and Objective-C exceptions. (Difficulty: Medium)
Enhance CFG to model C++ new more precisely.

The current representation of new does not provide an easy way for the analyzer to model the call to a memory allocation function (operator new), then initialize the result with a constructor call. The problem is discussed at length in PR12014. (Difficulty: Easy; current contact: Karthik Bhat)

……

还有很多，见`https://clang-analyzer.llvm.org/open_projects.html`



