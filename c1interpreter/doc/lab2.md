##Lab2 C1 interpreter实验报告

<p align = right>PB15111656</p>
<p align = right>陈翊辉</p>

#### 实验分析

在本实验中,将通过实现一个syntax tree visitor，为C1语言构建LLVM IR代码生成器。

而syntax tree visitor的实现——assembly builder的成员已经给定，需要做的只是实现各个node的visit方法。

在visit各个node时，除了生成代码，还需要维护符号表、类型检查和出错恢复等。


#### 简要设计

###### 代码生成

llvm ir使用寄存器式的ssa，翻译比较容易。先写出语法制导定义或翻译方案，在对应visit函数中调用llvm ir builder的相应函数翻译即可。

syntax_tree的语法树结构如下

```
syntax_tree_node
├───assembly
├───global_def_syntax
│   ├───func_def_syntax
│   ├───var_def_stmt_syntax
├───stmt_syntax
│   ├───assign_stmt_syntax
│   ├───func_call_stmt_syntax
│   ├───block_syntax
│   ├───if_stmt_syntax
│   ├───while_stmt_syntax
│   └───empty_stmt_syntax
├───cond_syntax
└───expr_syntax
    ├───binop_expr_syntax
    ├───unaryop_expr_syntax
    ├───lval_syntax
    └───literal_syntax
```

其中global_def_syntax、stmt_syntax和expr_syntax不是具体的类，需要实现的是具体的类的visit。

* `assembly`


初始化bb_count；

依次访问各个global_def_syntax（包含func_def_syntax和var_def_stmt_syntax）

* `func_def_syntax`


置in_global为false；

创建block，设之为插入点；

访问函数体

* `var_def_stmt_syntax`

`var_def_stmt_syntax`的翻译可以分成4类

| 创建；初值 | 全局                             | 局部                     |
| ----- | ------------------------------ | ---------------------- |
| 数组    | new GlobalVariable；initializer | CreateAlloca；GEP，Store |
| 整形    | new GlobalVariable；initializer | CreateAlloca；Store     |

其中全局变量如果没有赋初始值，则需要初始化成0。

其中全局变量的初始化值，数组长度都需要为编译时常数，即访问这些量前需置constexpr_expected为true

* `assign_stmt_syntax`


置lval_as_rval为false；

访问左值；

置lval_as_rval为true；

访问右值；

创建将右值存入左值的指令

* `func_call_stmt_syntax`


创建一条调用相关函数的指令

* `block_syntax`


enter_scope();

依次访问代码块的内容

exit_scope();

* `if_stmt_syntax`


访问条件；

创建3个block：bbtrue、bbfalse和bbfinish；

创建条件跳转指令，若真则跳至bbtrue，否则bbfalse；

设插入点为bbtrue；

访问then_body；

创建无条件跳转指令，跳至bbfinish；

设插入点为bbfalse；

访问else_body；

创建无条件跳转指令，跳至bbfinish；

设插入点为bbfinish

* `while_stmt_syntax`


创建3个block：bbtest、bbtrue和bbfinish；

创建无条件跳转指令，跳至bbtest；

设插入点为bbtest；

访问条件；

创建条件跳转指令，若真则跳至bbtrue，否则bbfinish；

设插入点为bbtrue；

访问循环体；

创建无条件跳至指令，跳至bbtest；

设插入点为bbfinish

* `empty_stmt_syntax`


不处理

* `binop_expr_syntax`


若需要常数值：

访问左表达式，访问右表达式，计算后放入const_result；

否则：

访问左表达式，访问右表达式，创建对应计算指令放入value_result；

* `unaryop_expr_syntax`


若需要常数值：

访问表达式，计算后放入const_result；

否则：

访问表达式，创建对应计算指令放入value_result；

* `lval_syntax`


分为4种情况，结果都放在value_result

|      | 数组                                       | 整形     |
| ---- | ---------------------------------------- | ------ |
| 作为左值 | 置lval_as_rval为true，访问下标，恢复lval_as_rval，取元素地址 | 地址     |
| 作为右值 | 置lval_as_rval为true，访问下标，恢复lval_as_rval，取元素地址，创建载入指令 | 创建载入指令 |



* `literal_syntax`


若需要常数，在const_result放入字面量；

否则，创建常数放入value_result


###### 错误处理

本实验中考虑实现以下种错误的处理：

* 重复定义
* 未定义的使用
* 对常量赋值
* 数组当作整形使用
* 整形当作数组使用
* 数组声明长度与初始化长度不匹配
* 编译时非常量
* 除以0
* 溢出（如$-2^{31}/-1$和$-2^{31}\%-1$）

对于数组长度为负这一错误，隐含在数组声明长度与初始化长度不匹配里面

#### 测试例子

测试例子在test/下，有计算素数，求和，斐波那契，排序和错误例子等

经测试，在这些测试例子下输出比较符合预期。

#### 问题与解决

1 无法通过父类指针知道子类类型而调用相应visit函数。

解决：无需指定visit函数，调用子类的accept方法即可。

2 无法通过数组（llvm ir里的数组）的指针，获取数组的类型（在llvm ir里的类型），而无法调用`GEP()`

解决：调用不需要类型参数的`GEP()`，llvm builder知道它的类型。

3 对于-2147483648程序会崩溃

解决：无视，根据c1的文法描述，字面量都是正整数，-2147483648解释为一元运算符-和字面量2147483648，不属于支持范围。

4 int a[3/0]程序会崩溃

解决：增加常量表达式除以0的判断和出错处理
