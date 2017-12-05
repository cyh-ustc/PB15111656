	.text
	.file	"plusplus_in.c"
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
	movabsq	$.L.str, %rdi
	movq	$0, -8(%rbp)
	movq	-8(%rbp), %rcx
	addq	$1, %rcx
	movq	%rcx, -8(%rbp)
	movq	-8(%rbp), %rsi
	addq	$1, %rsi
	movq	%rsi, -8(%rbp)
	movq	-8(%rbp), %rdx
	addq	$1, %rdx
	movq	%rdx, -8(%rbp)
	addq	%rdx, %rsi
	addq	%rsi, %rcx
	movq	%rcx, %rsi
	movl	%eax, -12(%rbp)         # 4-byte Spill
	movb	$0, %al
	callq	printf
	xorl	%r8d, %r8d
	movl	%eax, -16(%rbp)         # 4-byte Spill
	movl	%r8d, %eax
	addq	$16, %rsp
	popq	%rbp
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc

	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"%ld\n"
	.size	.L.str, 5


	.ident	"clang version 4.0.1-6 (tags/RELEASE_401/final)"
	.section	".note.GNU-stack","",@progbits
