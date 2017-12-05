	.text
	.file	"fact_1.c"
	.globl	fact
	.p2align	4, 0x90
	.type	fact,@function
fact:                                   # @fact
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
	cmpl	$0, fact.i
	jne	.LBB0_2
# BB#1:
	movl	$1, -4(%rbp)
	jmp	.LBB0_3
.LBB0_2:
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
.Lfunc_end0:
	.size	fact, .Lfunc_end0-fact
	.cfi_endproc

	.globl	main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:
	pushq	%rbp
.Lcfi3:
	.cfi_def_cfa_offset 16
.Lcfi4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Lcfi5:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	callq	fact
	movabsq	$.L.str, %rdi
	movl	%eax, %esi
	movb	$0, %al
	callq	printf
	xorl	%esi, %esi
	movl	%eax, -4(%rbp)          # 4-byte Spill
	movl	%esi, %eax
	addq	$16, %rsp
	popq	%rbp
	retq
.Lfunc_end1:
	.size	main, .Lfunc_end1-main
	.cfi_endproc

	.type	fact.i,@object          # @fact.i
	.data
	.p2align	2
fact.i:
	.long	5                       # 0x5
	.size	fact.i, 4

	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"factor of 5=%d\n"
	.size	.L.str, 16


	.ident	"clang version 4.0.1-6 (tags/RELEASE_401/final)"
	.section	".note.GNU-stack","",@progbits
