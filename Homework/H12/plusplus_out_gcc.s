	.file	"plusplus_out.c"
	.comm	i,8,8
	.section	.rodata
.LC0:
	.string	"%ld\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
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
	movq	$0, i(%rip)
	movq	i(%rip), %rax
	addq	$1, %rax
	movq	%rax, i(%rip)
	movq	i(%rip), %rax
	movq	i(%rip), %rdx
	addq	$1, %rdx
	movq	%rdx, i(%rip)
	movq	i(%rip), %rcx
	movq	i(%rip), %rdx
	addq	$1, %rdx
	movq	%rdx, i(%rip)
	movq	i(%rip), %rdx
	addq	%rcx, %rdx
	addq	%rdx, %rax
	movq	%rax, %rsi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.2.0-8ubuntu3) 7.2.0"
	.section	.note.GNU-stack,"",@progbits
