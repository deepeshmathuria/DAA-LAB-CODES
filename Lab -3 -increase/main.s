	.file	"main.c"
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
	.align 8
.LC0:
	.ascii "Enter the no. of test-cases  to be generated: \0"
.LC1:
	.ascii "%d\0"
.LC2:
	.ascii "w+\0"
.LC3:
	.ascii "inputs.txt\0"
.LC4:
	.ascii "%d\11\0"
.LC5:
	.ascii "r\0"
	.align 8
.LC6:
	.ascii "Length of the largest strictly increasing monotone is %d\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$64, %rsp
	.seh_stackalloc	64
	.seh_endprologue
	call	__main
	movl	$0, %ecx
	call	time
	movl	%eax, %ecx
	call	srand
	leaq	.LC0(%rip), %rcx
	call	printf
	leaq	-28(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC1(%rip), %rcx
	call	scanf
	leaq	.LC2(%rip), %rdx
	leaq	.LC3(%rip), %rcx
	call	fopen
	movq	%rax, -16(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L2
.L3:
	call	rand
	movl	%eax, %ecx
	movl	$1717986919, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$3, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$2, %eax
	subl	%eax, %ecx
	movl	%ecx, %edx
	addl	$1, %edx
	movq	-16(%rbp), %rax
	movl	%edx, %r8d
	leaq	.LC4(%rip), %rdx
	movq	%rax, %rcx
	call	fprintf
	addl	$1, -4(%rbp)
.L2:
	movl	-28(%rbp), %eax
	cmpl	%eax, -4(%rbp)
	jl	.L3
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	fclose
	leaq	.LC5(%rip), %rdx
	leaq	.LC3(%rip), %rcx
	call	fopen
	movq	%rax, -16(%rbp)
	movl	-28(%rbp), %eax
	cltq
	salq	$2, %rax
	movq	%rax, %rcx
	call	malloc
	movq	%rax, -24(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L4
.L5:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rax, %rdx
	movq	-16(%rbp), %rax
	movq	%rdx, %r8
	leaq	.LC1(%rip), %rdx
	movq	%rax, %rcx
	call	fscanf
	addl	$1, -4(%rbp)
.L4:
	movl	-28(%rbp), %eax
	cmpl	%eax, -4(%rbp)
	jl	.L5
	movl	-28(%rbp), %edx
	movq	-24(%rbp), %rax
	movq	%rax, %rcx
	call	sequence
	movl	%eax, %edx
	leaq	.LC6(%rip), %rcx
	call	printf
	movl	$0, %eax
	addq	$64, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (tdm64-1) 5.1.0"
	.def	time;	.scl	2;	.type	32;	.endef
	.def	srand;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	scanf;	.scl	2;	.type	32;	.endef
	.def	fopen;	.scl	2;	.type	32;	.endef
	.def	rand;	.scl	2;	.type	32;	.endef
	.def	fprintf;	.scl	2;	.type	32;	.endef
	.def	fclose;	.scl	2;	.type	32;	.endef
	.def	malloc;	.scl	2;	.type	32;	.endef
	.def	fscanf;	.scl	2;	.type	32;	.endef
	.def	sequence;	.scl	2;	.type	32;	.endef
