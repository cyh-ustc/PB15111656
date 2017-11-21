## H10
<p align = right>陈翊辉</p>
<p align = right>PB1511656</p>
#### problem1
以下是两段c语言代码：
###### bar6.c
```C
#include <stdio.h>
char main;

void p2()
{
	printf("0x%x\n", main);
}
```
###### foo6.c
```C
void p2(void);
int main()
{
	p2();
	return 0;
}
```
##### a) 分析输出结果及原因
在x86-64/Linux环境下，使用gcc编译
`gcc foo6.c bar6.c -o p1_m64.out`
为何没有对main赋值也会输出0x55
##### b) 分析输出结果及原因
在x86-64/Linux环境下，使用gcc编译
`gcc foo6.c bar6.c -m32 -o p1_m64.out`
为何没有对main赋值也会输出0xffffff8d

#### problem1 answer
本题考察符号表、作用域等知识

a) 链接两个目标代码时，main函数的强声明盖过了char main的声明，在打印时，传入的值为main函数的开头4个字节的值0x55（`pushl %rbp`）

b) 类似)但此时main的第一条指令为（`pushl %ebp`）

#### problem2

编写一段C语言代码，推测运行机器体系结构为大端还是小端。

#### problem2 answer

考察内存组织

```c
#include <stdio.h>
int main()
{
	int i = 0xaabbccdd;
	char *a = (char *)&i;
	printf("%s Endian",*a==0xaa?"Big":"Little");
	return 0;
}
```