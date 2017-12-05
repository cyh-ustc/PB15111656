## h12

#### c程序代码
```c
int fact()
{
	static int i = 5;
	if(i==0)
		return 1;
	else
	{
		i = i - 1;
        return ((i + 1) * fact());
        //return ((i + abs(1)) * fact());
	}
}
main()
{
	printf("factor of 5=%d\n", fact());
}

```

#### 运行结果
这段代码在x86-64/linux机器上使用gcc与clang编译执行结果都为120

#### 相应汇编与解释
与结果为1还是120密切相关的语句为

`return ((i + 1) * fact());`

这条语句及附件相应的汇编代码如下
```assembly
	movl	fact.i, %eax
	subl	$1, %eax
	movl	%eax, fact.i
	movl	fact.i, %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)          # 4-byte Spill
	callq	fact
	movl	-8(%rbp), %ecx          # 4-byte Reload
	imull	%eax, %ecx
	movl	%ecx, -4(%rbp)
.LBB0_3:
	movl	-4(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	retq
```
在调用`fact()`前，先在-8(%rbp)把静态变量i存放，在调用`fact()`后恢复了这个值（尽管静态变量i可能已经改变），最后与返回值做乘法的是存好的值（调用`fact()`前静态变量i的值），因而结果是120。
至于abs，在编译时就已经被省去了。


在某些机器结果为1，可能的原因是，计算`((i + 1) * fact())`时，没有在调用fact()前保存i的值，以致`fact()`调用后i的值改变；而使用abs后，在调用`fact()`前，存放了`i+abs(1)`的值。

#### 编译时的警告
有三种警告
* main返回值设为默认int
原因：没有声明main的类型
* implicit declaration of function ‘printf’
原因：没有include stdio
* implicit declaration of function ‘abs’
原因：没有定义abs或者include math

#### 补充程序
* 代码

```c
int main()
{
	long i;
	i = 0;
	printf("%ld\n", ++i+(++i)+(++i));
	i = 0;
	printf("%ld\n", ++i+((++i)+(++i)));
}
```

```c
long i;
int main()
{
	i = 0;
	printf("%ld\n", ++i+(++i)+(++i));
	i = 0;
	printf("%ld\n", ++i+((++i)+(++i)));
}
```
* 运行结果
```
$ ./plusplus_gcc_in.out 
7
9
$ ./plusplus_clang_in.out 
6
6
$ ./plusplus_gcc_out.out 
6
6
$ ./plusplus_clang_out.out 
6
6
```
* 结果分析
i为局部变量时`printf("%ld\n", ++i+(++i)+(++i));`的相关汇编代码
gcc
```assembly
	movq	$0, -8(%rbp)
	addq	$1, -8(%rbp)
	addq	$1, -8(%rbp)
	movq	-8(%rbp), %rax
	leaq	(%rax,%rax), %rdx
	addq	$1, -8(%rbp)
	movq	-8(%rbp), %rax
	addq	%rdx, %rax
	movq	%rax, %rsi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
```
可以看出，首先在i上加1两次，存入%rax，
再将%rax+%rax存入%rdx
再在i上加1，存入%rax
最后将%rax加入%rdx
得到7（2+2+3）
而在clang中
```assembly
	movq	$0, -8(%rbp)
	movq	-8(%rbp), %rax
	addq	$1, %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rcx
	addq	$1, %rcx
	movq	%rcx, -8(%rbp)
	addq	%rcx, %rax
	movq	-8(%rbp), %rcx
	addq	$1, %rcx
	movq	%rcx, -8(%rbp)
	addq	%rcx, %rax
	movq	%rax, %rsi
	movb	$0, %al
	callq	printf
```
是从左向右做一次++运算，做一次+，最终得到6（1+2+3）


在long为全局变量时
gcc
```assembly
	movq	$0, i(%rip)
	movq	i(%rip), %rax
	addq	$1, %rax
	movq	%rax, i(%rip)
	movq	i(%rip), %rdx
	movq	i(%rip), %rax
	addq	$1, %rax
	movq	%rax, i(%rip)
	movq	i(%rip), %rax
	addq	%rax, %rdx
	movq	i(%rip), %rax
	addq	$1, %rax
	movq	%rax, i(%rip)
	movq	i(%rip), %rax
	addq	%rdx, %rax
	movq	%rax, %rsi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
```
这段代码与上一段类似，是从左向右做一次++运算，做一次+，最终得到6（1+2+3）（还保存回i）
clang与gcc基本一样略

* 解释
