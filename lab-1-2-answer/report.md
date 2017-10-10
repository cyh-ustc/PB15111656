## ANTLR左递归支持分析
<p align="right">PB15111656</p>
<p align="right">陈翊辉</p>

#### ANTLR容许哪些类型的左递归？
ANTLR容许直接左递归。
如例子MultFirst.g4 PlusFirst.g4中文法e都为直接左递归。

##### ANTLR左递归消除的策略
* 包含能一个代替第一个和最后一个可选元素的递归定义的二元表达式
* 后缀表达式包含对规则的递归调用，作为替代的第一个元素，但不作为最后一个元素
* 前缀表达式包含对规则的递归调用，作为替代的最后一个元素，而不是第一个元素
>https://github.com/antlr/antlr4/blob/master/doc/left-recursion.md
#### ANTLR 对所支持的左递归如何处理？

ANTLR通过比较当前运算符的优先级与先前运算符的优先级来解决模糊。
在二元表达式内先出现的优先级高（没有一个“三元”表达的东西 - 它们只是伪装的二元表达式。）

如：
* e : e '*' e # Add | e '+' e # Mult | INT # Int ;
* e : e '+' e # Add | e '*' e # Mult | INT # Int ;
  测试结果如下：
  （以1+2*3为例）
```
Please enter an expression: 1+2*3
MultFirstParser:
	Tree: + [1] [* [2] [3]]
	Result: 7
PlusFirstParser:
	Tree: * [+ [1] [2]] [3]
	Result: 9
```
很明显，e '*' e在e '+' e前时，乘法优先级较高；
反过来则加法优先级较高。
#### ANTLR不支持的左递归文法

* 不支持的例子：
  * (1)    `S: A 'a'|'b';    A: S 'd'|;`
  * (2)    `E: E?'a';`(`E: E 'a' | 'a';`)
* 原因分析：
  * 对于(1)无法消除的原因可能为将A代入S或S代入A中时产生了无穷循环
  * 对于(2)`E: E? 'a';`等价于`E: E 'a' | 'a';`其中`E 'a'`中`'a'`和`'a'`相同