## H10
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
a) 链接两个目标代码时，main函数的强声明盖过了char main的声明，在打印时，传入的值为main函数的开头4个字节的值0x55（`pushl %rbp`）
b) 类似)但此时main的第一条指令为（`pushl %ebp`）