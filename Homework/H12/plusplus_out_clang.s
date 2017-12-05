	.text
	.file	"plusplus_out.c"
	.globl	main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:
	pushq	%rbp
.Lcfi0:
	.cfi_def_cfa_offset 16
.Lcfi1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Lcfi2:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movabsq	$.L.str, %rdi
	movq	$0, i
	movq	i, %rax
	addq	$1, %rax
	movq	%rax, i
	movq	i, %rcx
	addq	$1, %rcx
	movq	%rcx, i
	addq	%rcx, %rax
	movq	i, %rcx
	addq	$1, %rcx
	movq	%rcx, i
	addq	%rcx, %rax
	movq	%rax, %rsi
	movb	$0, %al
	callq	printf
	movabsq	$.L.str, %rdi
	movq	$0, i
	movq	i, %rcx
	addq	$1, %rcx
	movq	%rcx, i
	movq	i, %rsi
	addq	$1, %rsi
	movq	%rsi, i
	movq	i, %rdx
	addq	$1, %rdx
	movq	%rdx, i
	addq	%rdx, %rsi
	addq	%rsi, %rcx
	movq	%rcx, %rsi
	movl	%eax, -4(%rbp)          # 4-byte Spill
	movb	$0, %al
	callq	printf
	xorl	%r8d, %r8d
	movl	%eax, -8(%rbp)          # 4-byte Spill
	movl	%r8d, %eax
	addq	$16, %rsp
	popq	%rbp
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc

	.type	i,@object               # @i
	.comm	i,8,8
	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"%ld\n"
	.size	.L.str, 5


	.ident	"clang version 4.0.1-6 (tags/RELEASE_401/final)"
	.section	".note.GNU-stack","",@progbits
