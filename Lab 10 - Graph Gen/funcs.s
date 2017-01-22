	.file	"funcs.c"
	.text
	.globl	transform
	.def	transform;	.scl	2;	.type	32;	.endef
	.seh_proc	transform
transform:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L2
.L9:
	movl	$0, -8(%rbp)
	jmp	.L3
.L8:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	-8(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rdx, %rax
	movl	(%rax), %eax
	cmpl	$1, %eax
	jg	.L4
	movl	-4(%rbp), %eax
	cmpl	-8(%rbp), %eax
	je	.L4
	movl	$0, -12(%rbp)
	jmp	.L5
.L7:
	movl	-8(%rbp), %eax
	cmpl	-12(%rbp), %eax
	je	.L6
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	-12(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rdx, %rax
	movl	(%rax), %eax
	testl	%eax, %eax
	je	.L6
	movl	-12(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	-8(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rdx, %rax
	movl	(%rax), %eax
	testl	%eax, %eax
	jle	.L6
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	-8(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rdx, %rax
	movl	$0, (%rax)
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	-12(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rdx, %rax
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	leaq	0(,%rdx,8), %rcx
	movq	16(%rbp), %rdx
	addq	%rcx, %rdx
	movq	(%rdx), %rdx
	movl	-12(%rbp), %ecx
	movslq	%ecx, %rcx
	salq	$2, %rcx
	addq	%rcx, %rdx
	movl	(%rdx), %edx
	addl	$1, %edx
	movl	%edx, (%rax)
	jmp	.L4
.L6:
	addl	$1, -12(%rbp)
.L5:
	movl	-12(%rbp), %eax
	cmpl	24(%rbp), %eax
	jl	.L7
.L4:
	addl	$1, -8(%rbp)
.L3:
	movl	-8(%rbp), %eax
	cmpl	24(%rbp), %eax
	jl	.L8
	addl	$1, -4(%rbp)
.L2:
	movl	-4(%rbp), %eax
	cmpl	24(%rbp), %eax
	jl	.L9
	nop
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC0:
	.ascii "%c -->\0"
.LC1:
	.ascii " %c  \0"
	.align 8
.LC2:
	.ascii "\12\12After applying transform function\0"
	.align 8
.LC3:
	.ascii "\12 No. of edges-> before transform: %d after transform: %d \0"
	.text
	.globl	generateGraph
	.def	generateGraph;	.scl	2;	.type	32;	.endef
	.seh_proc	generateGraph
generateGraph:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$72, %rsp
	.seh_stackalloc	72
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	movl	%ecx, -32(%rbp)
	movl	-32(%rbp), %eax
	cltq
	salq	$3, %rax
	movq	%rax, %rcx
	call	malloc
	movq	%rax, -88(%rbp)
	movl	$0, -68(%rbp)
	jmp	.L11
.L12:
	movl	-68(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-88(%rbp), %rax
	leaq	(%rdx,%rax), %rbx
	movl	-32(%rbp), %eax
	cltq
	salq	$2, %rax
	movq	%rax, %rcx
	call	malloc
	movq	%rax, (%rbx)
	addl	$1, -68(%rbp)
.L11:
	movl	-68(%rbp), %eax
	cmpl	-32(%rbp), %eax
	jl	.L12
	movl	$0, -68(%rbp)
	jmp	.L13
.L18:
	movl	$0, -72(%rbp)
	jmp	.L14
.L17:
	movl	-68(%rbp), %eax
	cmpl	-72(%rbp), %eax
	je	.L15
	movl	-68(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-88(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	-72(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rdx, %rax
	movl	$1, (%rax)
	jmp	.L16
.L15:
	movl	-68(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-88(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	-72(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rdx, %rax
	movl	$0, (%rax)
.L16:
	addl	$1, -72(%rbp)
.L14:
	movl	-72(%rbp), %eax
	cmpl	-32(%rbp), %eax
	jl	.L17
	addl	$1, -68(%rbp)
.L13:
	movl	-68(%rbp), %eax
	cmpl	-32(%rbp), %eax
	jl	.L18
	movl	$0, -68(%rbp)
	jmp	.L19
.L23:
	movl	-68(%rbp), %eax
	addl	$65, %eax
	movl	%eax, %edx
	leaq	.LC0(%rip), %rcx
	call	printf
	movl	$0, -72(%rbp)
	jmp	.L20
.L22:
	movl	-68(%rbp), %eax
	cmpl	-72(%rbp), %eax
	je	.L21
	movl	-72(%rbp), %eax
	addl	$65, %eax
	movl	%eax, %edx
	leaq	.LC1(%rip), %rcx
	call	printf
.L21:
	addl	$1, -72(%rbp)
.L20:
	movl	-72(%rbp), %eax
	cmpl	-32(%rbp), %eax
	jl	.L22
	movl	$10, %ecx
	call	putchar
	addl	$1, -68(%rbp)
.L19:
	movl	-68(%rbp), %eax
	cmpl	-32(%rbp), %eax
	jl	.L23
	leaq	.LC2(%rip), %rcx
	call	puts
	movq	-88(%rbp), %rax
	movl	-32(%rbp), %edx
	movq	%rax, %rcx
	call	transform
	movl	$0, -76(%rbp)
	movl	$0, -68(%rbp)
	jmp	.L24
.L28:
	movl	-68(%rbp), %eax
	addl	$65, %eax
	movl	%eax, %edx
	leaq	.LC0(%rip), %rcx
	call	printf
	movl	$0, -72(%rbp)
	jmp	.L25
.L27:
	movl	-68(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-88(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	-72(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rdx, %rax
	movl	(%rax), %eax
	testl	%eax, %eax
	je	.L26
	movl	-72(%rbp), %eax
	addl	$65, %eax
	movl	%eax, %edx
	leaq	.LC1(%rip), %rcx
	call	printf
	addl	$1, -76(%rbp)
.L26:
	addl	$1, -72(%rbp)
.L25:
	movl	-72(%rbp), %eax
	cmpl	-32(%rbp), %eax
	jl	.L27
	movl	$10, %ecx
	call	putchar
	addl	$1, -68(%rbp)
.L24:
	movl	-68(%rbp), %eax
	cmpl	-32(%rbp), %eax
	jl	.L28
	movl	-32(%rbp), %eax
	subl	$1, %eax
	imull	-32(%rbp), %eax
	movl	-76(%rbp), %edx
	movl	%edx, %r8d
	movl	%eax, %edx
	leaq	.LC3(%rip), %rcx
	call	printf
	nop
	addq	$72, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (tdm64-1) 5.1.0"
	.def	malloc;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	putchar;	.scl	2;	.type	32;	.endef
	.def	puts;	.scl	2;	.type	32;	.endef
