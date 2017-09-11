## H1 练习使用GCC/Clang

### PB15111656

* 源代码(sum.c)

```c
/*求1到n的和，n>0*/
int sum(int n)
{
	int i,sum;
	for(i=0;i<n;++i)
		sum+=i;
	return sum;
}
```

* clang预处理

```sh
clang sum.c -E -o sum_clang_E.txt
```

结果如下

```c
# 1 "sum.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 317 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "sum.c" 2

int sum(int n)
{
 int i,sum;
 for(i=0;i<n;++i)
  sum+=i;
 return sum;
}
```

clang输出汇编码(32位)

```sh
clang sum.c -S -m32 -o sum_clang_S_m32.asm
```

结果如下

```assembly
	.text
	.file	"sum.c"
	.globl	sum
	.p2align	4, 0x90
	.type	sum,@function
sum:                                    # @sum
# BB#0:
	pushl	%ebp                    #将%ebp压栈（存好原来栈指针备份）
	movl	%esp, %ebp              #将%esp备份在#ebp里
	subl	$12, %esp               #%esp减去12（用来放i，n，sum）
	movl	8(%ebp), %eax           #把-8(%ebp)（i）放到%eax里（不能直接放到-4(%ebp)）
	movl	%eax, -4(%ebp)          #把%eax（i）放到-4(%ebp)里
	movl	$0, -8(%ebp)            #-8(%ebp) （循环变量i） 置零
.LBB0_1:                                # =>This Inner Loop Header: Depth=1
	movl	-8(%ebp), %eax          #把-8(%ebp)（i）放到%eax里（不能直接对-8(%ebp)和-4(%ebp)比较）
	cmpl	-4(%ebp), %eax          #比较-4(%ebp)和%eax（i和n）置flag
	jge	.LBB0_4                 #当i≥n时，跳到.LBB0_4(结束循环)
# BB#2:                                 #   in Loop: Header=BB0_1 Depth=1
	movl	-8(%ebp), %eax          #把i放到%eax里（不能直接加到sum里）
	addl	-12(%ebp), %eax         #sum+=i
	movl	%eax, -12(%ebp)         #把sum存回去
# BB#3:                                 #   in Loop: Header=BB0_1 Depth=1
	movl	-8(%ebp), %eax          #把i放到%eax里
	addl	$1, %eax                #i++
	movl	%eax, -8(%ebp)          #存回i
	jmp	.LBB0_1                 #跳到LBB0_1（循环）
.LBB0_4:
	movl	-12(%ebp), %eax         #把sum存在%eax里（用于返回）
	addl	$12, %esp               #%esp加12（释放掉i，n，sum）
	popl	%ebp                    #恢复最初保存的%ebp
	retl                            #返回
.Lfunc_end0:
	.size	sum, .Lfunc_end0-sum


	.ident	"clang version 4.0.0-1ubuntu1 (tags/RELEASE_400/rc1)"
	.section	".note.GNU-stack","",@progbits
```

clang输出汇编码(64位)

```sh
clang sum.c -S -m64 -o sum_clang_S_m64.asm
```

结果如下

```assembly
	.text
	.file	"sum.c"
	.globl	sum
	.p2align	4, 0x90
	.type	sum,@function
sum:                                    # @sum
	.cfi_startproc
# BB#0:
	pushq	%rbp                    #备份%rbp
.Lcfi0:
	.cfi_def_cfa_offset 16
.Lcfi1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp              #备份%rsp
.Lcfi2:
	.cfi_def_cfa_register %rbp
	movl	%edi, -4(%rbp)          #放n在-4(%rbp)
	movl	$0, -8(%rbp)            #i = 0
.LBB0_1:                                # =>This Inner Loop Header: Depth=1
	movl	-8(%rbp), %eax          #当i≥n时结束
	cmpl	-4(%rbp), %eax
	jge	.LBB0_4
# BB#2:                                 #   in Loop: Header=BB0_1 Depth=1
	movl	-8(%rbp), %eax          #sum+=i
	addl	-12(%rbp), %eax
	movl	%eax, -12(%rbp)
# BB#3:                                 #   in Loop: Header=BB0_1 Depth=1
	movl	-8(%rbp), %eax          #i++
	addl	$1, %eax
	movl	%eax, -8(%rbp)
	jmp	.LBB0_1                 #循环
.LBB0_4:
	movl	-12(%rbp), %eax         #返回sum
	popq	%rbp                    #恢复%rbp
	retq                            #返回sum
.Lfunc_end0:
	.size	sum, .Lfunc_end0-sum
	.cfi_endproc


	.ident	"clang version 4.0.0-1ubuntu1 (tags/RELEASE_400/rc1)"
	.section	".note.GNU-stack","",@progbits
```



- gcc预处理

```sh
gcc -E sum.c -o sum_gcc_E.txt
```

结果如下

```c
# 1 "sum.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "sum.c"

int sum(int n)
{
 int i,sum;
 for(i=0;i<n;++i)
  sum+=i;
 return sum;
}
```

- gcc输出汇编码(32位)

```sh
gcc sum.c -S -m32 -o sum_gcc_S_m32.asm
```

结果如下

```asm
	.file	"sum.c"
	.text
	.globl	sum
	.type	sum, @function               
sum:
.LFB0:
	.cfi_startproc
	pushl	%ebp                        #将%ebp压栈
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp                  #将%esp放在#ebp里
	.cfi_def_cfa_register 5
	subl	$16, %esp              #%esp减去16（用来放i，n，sum）
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	movl	$0, -8(%ebp)               #-8(%ebp) （循环变量i） 置零
	jmp	.L2
.L3:
	movl	-8(%ebp), %eax
	addl	%eax, -4(%ebp)   #sum+=i
	addl	$1, -8(%ebp)        #++i 
.L2:
	movl	-8(%ebp), %eax      
	cmpl	8(%ebp), %eax   
	jl	.L3                    #i<n时循环
	movl	-4(%ebp), %eax     #把sum存在%eax里（用于返回）
	leave            #恢复最初保存的%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	sum, .-sum
	.section	.text.__x86.get_pc_thunk.ax,"axG",@progbits,__x86.get_pc_thunk.ax,comdat
	.globl	__x86.get_pc_thunk.ax
	.hidden	__x86.get_pc_thunk.ax
	.type	__x86.get_pc_thunk.ax, @function
__x86.get_pc_thunk.ax:
.LFB1:
	.cfi_startproc
	movl	(%esp), %eax
	ret
	.cfi_endproc
.LFE1:
	.ident	"GCC: (Ubuntu 6.3.0-12ubuntu2) 6.3.0 20170406"
	.section	.note.GNU-stack,"",@progbits
```

- gcc输出汇编码(64位)

```sh
gcc sum.c -S -m64 -o sum_gcc_S_m64.asm
```

结果如下

```assembly
	.file	"sum.c"
	.text
	.globl	sum
	.type	sum, @function
sum:
.LFB0:
	.cfi_startproc
	pushq	%rbp                  #备份%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp            #备份%rsp
	.cfi_def_cfa_register 6
	movl	%edi, -20(%rbp)
	movl	$0, -8(%rbp)          #i=0
	jmp	.L2
.L3:
	movl	-8(%rbp), %eax     
	addl	%eax, -4(%rbp)        #sum+=i
	addl	$1, -8(%rbp)         #i++
.L2:
	movl	-8(%rbp), %eax     
	cmpl	-20(%rbp), %eax       #当i<n时循环
	jl	.L3
	movl	-4(%rbp), %eax        #(当i≥n时结束)
	popq	%rbp                 #恢复%rbp 
	.cfi_def_cfa 7, 8 
	ret
	.cfi_endproc
.LFE0:
	.size	sum, .-sum
	.ident	"GCC: (Ubuntu 6.3.0-12ubuntu2) 6.3.0 20170406"
	.section	.note.GNU-stack,"",@progbits
```

