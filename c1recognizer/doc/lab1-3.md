## lab1-3 bulid ast

PB15111656
陈翊辉

#### 实验分析与设计

本次实验需要使用antlr4生成的cpp代码上添加，最终可以生成c1语言的ast。

首先需要改写文法，来支持缺省int的const定义。只需在Int后加？即可

在lab1-2中，文法书写比较自由（只要符合antlr4即可），而本实验需要改到尽可能简单。
比如在lab1-2中，我对于compilationUnit虽然符合antlr4，但对于构建ast树十分麻烦。
```
compilationUnit:  (decl | funcdef) compilationUnit_;


compilationUnit_:
    (decl | funcdef)compilationUnit_
    |
;
```
因而改成更简单的
```
compilationUnit:  (decl | funcdef)+;
```

对于
```
Decl  → ConstDecl | VarDecl
ConstDecl   → const int ConstDef { , ConstDef } ';'
ConstDef    → ident '=' Exp | ident '[' [ Exp ] ']' '=' '{' Exp { ',' Exp } '}'
VarDecl     → int Var { , Var } ';'
Var         → ident | ident '[' Exp ']' | ident '=' Exp
            | ident '[' [ Exp ] ']' '=' '{' Exp { ',' Exp } '}'
```
这部分内容，由于ast树的数据结构没有明确要求constdecl、vardecl和decl的形式；为了方便和减少大量赋值，直接在compunit和block中完成这部分语法树的构建
因而，对于const缺省int的warning也需要放在compunit和block的visit中完成。
#### antlr编程接口与文法之间的关系

由antlr4根据文法文件生成的cpp代码主要在`build\antlr4cpp_generated_src`中
其中*Lexer.*为词法分析有关，*Parser*.*与文法有关
*Visitor.*则和访问者模式有关。

在Praser.*中
```cpp
class  某些Context : public antlr4::ParserRuleContext
```
antlr为每个非终结符声明了一个类，这些类的成员和文法产生式一一对应，通过这个类可以访问每个非终结符产生式中的终结符和非终结符。


在Visitor.*中
定义了各个类的虚拟访问函数，通过实现这些访问函数，并通过Context中的成员的关系，即可生成出ast树。

#### 关于ATN

全称  augmented transition networks

扩充转移网络文法ATN，就是用上下文无关文法的扩充来实现上下文相关文法。ATN用一组寄存器存放语法分析信息，每走一步都要测试一下当前情况，并根据测试结果决定做什么动作，最后把寄存器中的信息综合起来，即得到被分析句子的语法结构。

#### 关于SLL和ALL

* sll

sll代表了 strong leftmost left-to-right

sll是ll文法的子集。

对于任意两个A的产生式

$A→a$

$A→b$

有$FIRST_k(aFOLLOW(A))∩FIRST_k(bFOLLOW(A))=∅$

则这个文法为strong文法。LL文法见书上。

* ALL(*) 

ANTLR从4.0开始生成的是ALL(*)解析器，其中A是自适应（Adaptive）的意思。ALL(*)解析器是由Terence Parr、Sam Harwell与Kathleen Fisher共同研发的，对传统的LL(*)解析器有很大的改进，ANTLR是目前唯一可以生成ALL(*)解析器的工具。 



#### Recursion
了解并总结enterRecursionRule、unrollRecursionContexts、adaptivePredict函数的作用、接口和主要处理流程。



#### 错误处理机制


