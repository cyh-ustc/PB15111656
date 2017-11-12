## lab2预热实验报告

PB15111656

陈翊辉

#### 实验分析

本实验分为两个部分，第一部分比较容易，将一段c代码人工翻译成llvm IR；第二部分要求使用llvm IR bulider来构建第一部分的llvm IR。

llvm IR是中间代码，翻译时，首先考虑将代码划分成block，再将各个block中的代码翻译成3地址代码即可。

由于第一部分的llvm IR已经固定，使用llvm IR bulider构建第一部分的llvm IR时，先构造func，其次构造各个block，最终按顺序在各个block中插入代码。

#### 实验过程

######人工翻译llvm IR

对于fib函数，可以分为5个block：

* entry：判断是否为0
* Equal0：返回0
* NotEqual0：判断是否为1
* Equal1：返回1
* NotEqual1：返回fib(n-1)+fib(n-2)

对于main，可以分为4个block：

* entry：初始化，进入循环
* forcond：判断循环条件
* forexpr：执行循环体
* firfini：返回

###### 通过llvm ir builder构建llvm IR

使用llvm ir builder来构建固定的llvmIR基本就是按顺序根据每条指令调用对应的create函数，最终打印。

为了打印出的llvm ir接近手写的llvm ir，对于每个变量，都尽量配上名字。需要注意的是。在llvm ir里，不同func中可以有相同名字的临时变量，而用cpp的llvm irbuilder构建时若直接在main中定义需要用不同的id。

通常对于常数可以使用map来记录和复用相同的常数。这里的常数有0，1，2，10等，出现较少，因此就不用map记录了。

#### 问题与解决

llvm ir builder的function的参数（args）没有提供[]方式访问，而提供了迭代器的访问。在各个使用参数的指令中使用比较麻烦。

这里用一个指针记下。

```cpp
Value *V;
for (auto &Arg : func->args())
	V = &Arg;
```

（也可以直接用args_begin()等）

#### 编译及运行方法

使用makefile编译，运行直接打印llvmir到终端

```sh
make
./fib_gen
```

```sh
make
./fib_gen > f.ll
lli f.ll
echo $?
```

可以看到返回值为88