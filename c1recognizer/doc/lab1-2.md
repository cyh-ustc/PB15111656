## Lab1-2. C1 的语法分析

PB15111656

陈翊辉

#### 实验分析

​	此次试验在欲使用antlr4生成C1语言的语法分析器并测试，而C1语言的文法已用EBNF表示。因而只需将EBNF改写成antlr4合法的文法文件并测试即可。

​	EBNF与antlr4文法文件和课本中文法格式等十分类似。改写时首先需将EBNF中[]改成()?，{}改成()+等；又因语法分析与词法分析结合，再将EBNF中使用''直接表示的符号改成词法记号。

​	尔后需要保证写出的文法文件符合antlr4要求。显然，在C1的EBNF定义中，CompUnit和Exp都有直接左递归，关于antlr4对左递归的处理将在其他报告中说明。

​	测试文件需要将每一个文法都测试到，重点需要测试左递归的文法和优先级的处理等；并且需要测试错误的例子。



#### 遇到的问题

将EBNF按上文方法改写成antlr4后，antlr4无法处理compilationUnit

```
compilationUnit: compilationUnit? (decl | funcdef);
```

提示The following sets of rules are mutually left-recursive [compilationUnit]

`compilationUnit: compilationUnit? (decl | funcdef);`等价于

```
compilationUnit: 
	compilationUnit (decl | funcdef)
	| (decl | funcdef)
;

```

使用课本上消除直接左递归的方法改写

```
compilationUnit:  (decl | funcdef) compilationUnit_;

compilationUnit_:
    (decl | funcdef)compilationUnit_
    |
;
```

#### 实验测试

* par_1.c1测试基本的语法分析
* par_2.c1测试if else结合
* par_3.c1测试运算符的优先级
* par_4.c1错误的例子

