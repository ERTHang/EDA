	.file	"trabalho_eda_PDDE.c"
	.text
	.section	.rodata
.LC0:
	.string	"r"
.LC1:
	.string	"dados/entrada.txt"
.LC2:
	.string	"%c"
.LC3:
	.string	"Limite Linha: %zu\n"
.LC4:
	.string	"w+"
.LC5:
	.string	"dados/saida.txt"
	.text
	.globl	main
	.type	main, @function
main:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$96, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	.LC0(%rip), %rsi
	leaq	.LC1(%rip), %rdi
	call	fopen@PLT
	movq	%rax, -80(%rbp)
	movq	$0, -96(%rbp)
	movq	$0, -88(%rbp)
	leaq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	inicializar_descritor_matriz
.L8:
	leaq	-64(%rbp), %rdx
	movq	-80(%rbp), %rax
	leaq	.LC2(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_fscanf@PLT
	cmpl	$-1, %eax
	jne	.L2
	movq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	fclose@PLT
	leaq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	wrap_with_zeros
	pushq	-24(%rbp)
	pushq	-32(%rbp)
	pushq	-40(%rbp)
	pushq	-48(%rbp)
	call	print_matriz_desc
	addq	$32, %rsp
	leaq	-64(%rbp), %rcx
	leaq	-88(%rbp), %rdx
	leaq	-96(%rbp), %rsi
	leaq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	find_biggest_object
	movq	-96(%rbp), %rax
	movq	-64(%rbp), %rcx
	movq	-56(%rbp), %rdx
	pushq	-24(%rbp)
	pushq	-32(%rbp)
	pushq	-40(%rbp)
	pushq	-48(%rbp)
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	print_matriz_object_with_mass_center
	addq	$32, %rsp
	movq	-96(%rbp), %rax
	testq	%rax, %rax
	jne	.L3
	jmp	.L4
.L2:
	movzbl	-64(%rbp), %eax
	cmpb	$10, %al
	jne	.L5
	movq	-32(%rbp), %rax
	cmpq	$-1, %rax
	jne	.L8
	movq	-40(%rbp), %rax
	movq	%rax, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L8
.L5:
	movzbl	-64(%rbp), %eax
	movsbl	%al, %eax
	subl	$48, %eax
	movslq	%eax, %rdx
	leaq	-48(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	adiciona_matriz
	jmp	.L8
.L3:
	leaq	.LC4(%rip), %rsi
	leaq	.LC5(%rip), %rdi
	call	fopen@PLT
	movq	%rax, -72(%rbp)
	movq	-96(%rbp), %rdx
	movq	-72(%rbp), %rax
	pushq	-24(%rbp)
	pushq	-32(%rbp)
	pushq	-40(%rbp)
	pushq	-48(%rbp)
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	write_object_to_file
	addq	$32, %rsp
.L4:
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L10
	call	__stack_chk_fail@PLT
.L10:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	main, .-main
	.globl	inicializar_descritor_matriz
	.type	inicializar_descritor_matriz, @function
inicializar_descritor_matriz:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	$0, 8(%rax)
	movq	-8(%rbp), %rax
	movq	$0, (%rax)
	movq	-8(%rbp), %rax
	movq	$-1, 16(%rax)
	movq	-8(%rbp), %rax
	movq	$0, 24(%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	inicializar_descritor_matriz, .-inicializar_descritor_matriz
	.globl	adiciona_matriz
	.type	adiciona_matriz, @function
adiciona_matriz:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	je	.L13
	movq	-24(%rbp), %rax
	movq	8(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	16(%rax), %rax
	cmpq	%rax, %rdx
	jne	.L14
.L13:
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	adiciona_linha
.L14:
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	testq	%rax, %rax
	jne	.L15
	movq	-24(%rbp), %rax
	movq	24(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	salq	$3, %rax
	subq	$8, %rax
	leaq	(%rdx,%rax), %rbx
	movl	$8, %edi
	call	malloc@PLT
	movq	%rax, (%rbx)
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	leaq	1(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, 8(%rax)
	jmp	.L16
.L15:
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	leaq	1(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, 8(%rax)
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	leaq	0(,%rax,8), %rcx
	movq	-24(%rbp), %rax
	movq	24(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	salq	$3, %rax
	subq	$8, %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	-24(%rbp), %rdx
	movq	24(%rdx), %rsi
	movq	-24(%rbp), %rdx
	movq	(%rdx), %rdx
	salq	$3, %rdx
	subq	$8, %rdx
	leaq	(%rsi,%rdx), %rbx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, (%rbx)
.L16:
	movq	-24(%rbp), %rax
	movq	24(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	salq	$3, %rax
	subq	$8, %rax
	addq	%rdx, %rax
	movq	(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	salq	$3, %rax
	subq	$8, %rax
	addq	%rax, %rdx
	movq	-32(%rbp), %rax
	movq	%rax, (%rdx)
	nop
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	adiciona_matriz, .-adiciona_matriz
	.globl	adiciona_linha
	.type	adiciona_linha, @function
adiciona_linha:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	jne	.L18
	movl	$8, %edi
	call	malloc@PLT
	movq	%rax, %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, 24(%rax)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	leaq	1(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, (%rax)
	jmp	.L20
.L18:
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	leaq	1(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, (%rax)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	leaq	0(,%rax,8), %rdx
	movq	-8(%rbp), %rax
	movq	24(%rax), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	realloc@PLT
	movq	%rax, %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, 24(%rax)
	movq	-8(%rbp), %rax
	movq	$0, 8(%rax)
.L20:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	adiciona_linha, .-adiciona_linha
	.section	.rodata
	.align 8
.LC6:
	.string	"Objeto encontrado tem tamanho: %zu\n"
	.align 8
.LC9:
	.string	"Maior Objeto tem tamanho: %zu, label: %zu e mass center: (%zu, %zu)\n"
	.text
	.globl	find_biggest_object
	.type	find_biggest_object, @function
find_biggest_object:
.LFB9:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	addq	$-128, %rsp
	movq	%rdi, -88(%rbp)
	movq	%rsi, -96(%rbp)
	movq	%rdx, -104(%rbp)
	movq	%rcx, -112(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	$0, -56(%rbp)
	movq	$0, -48(%rbp)
	movq	$1, -40(%rbp)
	movl	$0, -72(%rbp)
	jmp	.L22
.L26:
	movl	$0, -68(%rbp)
	jmp	.L23
.L25:
	movq	-88(%rbp), %rax
	movq	24(%rax), %rax
	movl	-72(%rbp), %edx
	movslq	%edx, %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	-68(%rbp), %edx
	movslq	%edx, %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movq	(%rax), %rax
	cmpq	$1, %rax
	jne	.L24
	movq	$0, -64(%rbp)
	addq	$1, -40(%rbp)
	movl	-68(%rbp), %eax
	movslq	%eax, %rdx
	movl	-72(%rbp), %eax
	movslq	%eax, %rsi
	leaq	-32(%rbp), %r8
	movq	-40(%rbp), %rdi
	leaq	-64(%rbp), %rcx
	movq	-88(%rbp), %rax
	movq	%r8, %r9
	movq	%rdi, %r8
	movq	%rax, %rdi
	call	object_size
	movq	-64(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC6(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-64(%rbp), %rax
	cmpq	%rax, -56(%rbp)
	jnb	.L24
	movq	-64(%rbp), %rax
	movq	%rax, -56(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, -48(%rbp)
	movq	-32(%rbp), %rdx
	movq	-112(%rbp), %rax
	movq	%rdx, (%rax)
	movq	-24(%rbp), %rdx
	movq	-112(%rbp), %rax
	movq	%rdx, 8(%rax)
.L24:
	addl	$1, -68(%rbp)
.L23:
	movl	-68(%rbp), %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	16(%rax), %rax
	cmpq	%rax, %rdx
	jb	.L25
	addl	$1, -72(%rbp)
.L22:
	movl	-72(%rbp), %eax
	movslq	%eax, %rdx
	movq	-88(%rbp), %rax
	movq	(%rax), %rax
	cmpq	%rax, %rdx
	jb	.L26
	movq	-96(%rbp), %rax
	movq	-48(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	-104(%rbp), %rax
	movq	-56(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	-112(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -128(%rbp)
	fildq	-128(%rbp)
	testq	%rax, %rax
	jns	.L27
	fldt	.LC7(%rip)
	faddp	%st, %st(1)
.L27:
	movq	-104(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -128(%rbp)
	fildq	-128(%rbp)
	testq	%rax, %rax
	jns	.L28
	fldt	.LC7(%rip)
	faddp	%st, %st(1)
.L28:
	fdivrp	%st, %st(1)
	fstpl	-120(%rbp)
	movsd	-120(%rbp), %xmm0
	call	round@PLT
	ucomisd	.LC8(%rip), %xmm0
	jnb	.L29
	cvttsd2siq	%xmm0, %rax
	jmp	.L30
.L29:
	movsd	.LC8(%rip), %xmm1
	subsd	%xmm1, %xmm0
	cvttsd2siq	%xmm0, %rax
	movabsq	$-9223372036854775808, %rdx
	xorq	%rdx, %rax
.L30:
	movq	-112(%rbp), %rdx
	movq	%rax, (%rdx)
	movq	-112(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -128(%rbp)
	fildq	-128(%rbp)
	testq	%rax, %rax
	jns	.L31
	fldt	.LC7(%rip)
	faddp	%st, %st(1)
.L31:
	movq	-104(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -128(%rbp)
	fildq	-128(%rbp)
	testq	%rax, %rax
	jns	.L32
	fldt	.LC7(%rip)
	faddp	%st, %st(1)
.L32:
	fdivrp	%st, %st(1)
	fstpl	-120(%rbp)
	movsd	-120(%rbp), %xmm0
	call	round@PLT
	ucomisd	.LC8(%rip), %xmm0
	jnb	.L33
	cvttsd2siq	%xmm0, %rax
	jmp	.L34
.L33:
	movsd	.LC8(%rip), %xmm1
	subsd	%xmm1, %xmm0
	cvttsd2siq	%xmm0, %rax
	movabsq	$-9223372036854775808, %rdx
	xorq	%rdx, %rax
.L34:
	movq	-112(%rbp), %rdx
	movq	%rax, 8(%rdx)
	movq	-112(%rbp), %rax
	movq	8(%rax), %rsi
	movq	-112(%rbp), %rax
	movq	(%rax), %rcx
	movq	-96(%rbp), %rax
	movq	(%rax), %rdx
	movq	-104(%rbp), %rax
	movq	(%rax), %rax
	movq	%rsi, %r8
	movq	%rax, %rsi
	leaq	.LC9(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	nop
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L35
	call	__stack_chk_fail@PLT
.L35:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	find_biggest_object, .-find_biggest_object
	.globl	object_size
	.type	object_size, @function
object_size:
.LFB10:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$80, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%rdx, -56(%rbp)
	movq	%rcx, -64(%rbp)
	movq	%r8, -72(%rbp)
	movq	%r9, -80(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$16, %edi
	call	malloc@PLT
	movq	%rax, -24(%rbp)
	movq	$0, -16(%rbp)
	leaq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	inicializar_pilha@PLT
	movq	-40(%rbp), %rax
	movq	24(%rax), %rax
	movq	-48(%rbp), %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	-56(%rbp), %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movq	(%rax), %rax
	cmpq	$1, %rax
	jne	.L46
	movq	-40(%rbp), %rax
	movq	24(%rax), %rax
	movq	-48(%rbp), %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	-56(%rbp), %rdx
	salq	$3, %rdx
	addq	%rax, %rdx
	movq	-72(%rbp), %rax
	movq	%rax, (%rdx)
	movq	-64(%rbp), %rax
	movq	(%rax), %rax
	leaq	1(%rax), %rdx
	movq	-64(%rbp), %rax
	movq	%rdx, (%rax)
	movq	-24(%rbp), %rax
	movq	-48(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	-80(%rbp), %rax
	movq	-48(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	-24(%rbp), %rax
	movq	-56(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	-80(%rbp), %rax
	movq	-56(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	-24(%rbp), %rdx
	movq	-16(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	append_pilha@PLT
.L43:
	movq	-40(%rbp), %rax
	movq	24(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	salq	$3, %rax
	addq	%rdx, %rax
	movq	(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	addq	$1, %rax
	salq	$3, %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	cmpq	$1, %rax
	jne	.L38
	movq	-24(%rbp), %rax
	movq	8(%rax), %rdx
	addq	$1, %rdx
	movq	%rdx, 8(%rax)
	movq	-24(%rbp), %rdx
	movq	-16(%rbp), %rax
	movq	-80(%rbp), %r8
	movq	-64(%rbp), %rdi
	movq	-72(%rbp), %rcx
	movq	-40(%rbp), %rsi
	movq	%r8, %r9
	movq	%rdi, %r8
	movq	%rax, %rdi
	call	marcar_matriz_e_caminho
	jmp	.L43
.L38:
	movq	-40(%rbp), %rax
	movq	24(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	addq	$1, %rax
	salq	$3, %rax
	addq	%rdx, %rax
	movq	(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	salq	$3, %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	cmpq	$1, %rax
	jne	.L40
	movq	-24(%rbp), %rax
	movq	(%rax), %rdx
	addq	$1, %rdx
	movq	%rdx, (%rax)
	movq	-24(%rbp), %rdx
	movq	-16(%rbp), %rax
	movq	-80(%rbp), %r8
	movq	-64(%rbp), %rdi
	movq	-72(%rbp), %rcx
	movq	-40(%rbp), %rsi
	movq	%r8, %r9
	movq	%rdi, %r8
	movq	%rax, %rdi
	call	marcar_matriz_e_caminho
	jmp	.L43
.L40:
	movq	-40(%rbp), %rax
	movq	24(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	salq	$3, %rax
	addq	%rdx, %rax
	movq	(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	salq	$3, %rax
	subq	$8, %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	cmpq	$1, %rax
	jne	.L41
	movq	-24(%rbp), %rax
	movq	8(%rax), %rdx
	subq	$1, %rdx
	movq	%rdx, 8(%rax)
	movq	-24(%rbp), %rdx
	movq	-16(%rbp), %rax
	movq	-80(%rbp), %r8
	movq	-64(%rbp), %rdi
	movq	-72(%rbp), %rcx
	movq	-40(%rbp), %rsi
	movq	%r8, %r9
	movq	%rdi, %r8
	movq	%rax, %rdi
	call	marcar_matriz_e_caminho
	jmp	.L43
.L41:
	movq	-40(%rbp), %rax
	movq	24(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	salq	$3, %rax
	subq	$8, %rax
	addq	%rdx, %rax
	movq	(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	salq	$3, %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	cmpq	$1, %rax
	jne	.L42
	movq	-24(%rbp), %rax
	movq	(%rax), %rdx
	subq	$1, %rdx
	movq	%rdx, (%rax)
	movq	-24(%rbp), %rdx
	movq	-16(%rbp), %rax
	movq	-80(%rbp), %r8
	movq	-64(%rbp), %rdi
	movq	-72(%rbp), %rcx
	movq	-40(%rbp), %rsi
	movq	%r8, %r9
	movq	%rdi, %r8
	movq	%rax, %rdi
	call	marcar_matriz_e_caminho
	jmp	.L43
.L42:
	movq	-16(%rbp), %rax
	leaq	-24(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	pop_pilha@PLT
	movq	-24(%rbp), %rax
	testq	%rax, %rax
	je	.L47
	jmp	.L43
.L47:
	nop
.L46:
	nop
	movq	-8(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L44
	call	__stack_chk_fail@PLT
.L44:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	object_size, .-object_size
	.section	.rodata
.LC11:
	.string	"mass center at: (%zu, %zu)\n"
	.text
	.globl	marcar_matriz_e_caminho
	.type	marcar_matriz_e_caminho, @function
marcar_matriz_e_caminho:
.LFB11:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	%rcx, -32(%rbp)
	movq	%r8, -40(%rbp)
	movq	%r9, -48(%rbp)
	movq	-16(%rbp), %rax
	movq	24(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	salq	$3, %rax
	addq	%rdx, %rax
	movq	(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	salq	$3, %rax
	addq	%rax, %rdx
	movq	-32(%rbp), %rax
	movq	%rax, (%rdx)
	movq	-40(%rbp), %rax
	movq	(%rax), %rax
	leaq	1(%rax), %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, (%rax)
	movq	-48(%rbp), %rax
	movq	(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	addq	%rax, %rdx
	movq	-48(%rbp), %rax
	movq	%rdx, (%rax)
	movq	-48(%rbp), %rax
	movq	8(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	addq	%rax, %rdx
	movq	-48(%rbp), %rax
	movq	%rdx, 8(%rax)
	movq	-48(%rbp), %rax
	movq	8(%rax), %rdx
	movq	-48(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rsi
	leaq	.LC11(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-24(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	append_pilha@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	marcar_matriz_e_caminho, .-marcar_matriz_e_caminho
	.section	.rodata
.LC12:
	.string	"%3zu"
	.text
	.globl	print_matriz_desc
	.type	print_matriz_desc, @function
print_matriz_desc:
.LFB12:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	$0, -16(%rbp)
	jmp	.L50
.L53:
	movq	$0, -8(%rbp)
	jmp	.L51
.L52:
	movq	40(%rbp), %rax
	movq	-16(%rbp), %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	-8(%rbp), %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	%rax, %rsi
	leaq	.LC12(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	addq	$1, -8(%rbp)
.L51:
	movq	24(%rbp), %rax
	cmpq	%rax, -8(%rbp)
	jb	.L52
	movl	$10, %edi
	call	putchar@PLT
	addq	$1, -16(%rbp)
.L50:
	movq	16(%rbp), %rax
	cmpq	%rax, -16(%rbp)
	jb	.L53
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE12:
	.size	print_matriz_desc, .-print_matriz_desc
	.section	.rodata
.LC13:
	.string	"\033[0m"
.LC14:
	.string	"\033[0;35m"
.LC15:
	.string	"%s%3zu%s"
.LC16:
	.string	"\033[0;32m"
	.text
	.globl	print_matriz_object_with_mass_center
	.type	print_matriz_object_with_mass_center, @function
print_matriz_object_with_mass_center:
.LFB13:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, %rax
	movq	%rdx, %rcx
	movq	%rcx, %rdx
	movq	%rax, -48(%rbp)
	movq	%rdx, -40(%rbp)
	movq	$0, -16(%rbp)
	jmp	.L55
.L61:
	movq	$0, -8(%rbp)
	jmp	.L56
.L60:
	movq	-48(%rbp), %rax
	cmpq	%rax, -16(%rbp)
	jne	.L57
	movq	-40(%rbp), %rax
	cmpq	%rax, -8(%rbp)
	jne	.L57
	movq	40(%rbp), %rax
	movq	-16(%rbp), %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	-8(%rbp), %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movq	(%rax), %rax
	leaq	.LC13(%rip), %rcx
	movq	%rax, %rdx
	leaq	.LC14(%rip), %rsi
	leaq	.LC15(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L58
.L57:
	movq	40(%rbp), %rax
	movq	-16(%rbp), %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	-8(%rbp), %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movq	(%rax), %rax
	cmpq	%rax, -24(%rbp)
	jne	.L59
	movq	40(%rbp), %rax
	movq	-16(%rbp), %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	-8(%rbp), %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movq	(%rax), %rax
	leaq	.LC13(%rip), %rcx
	movq	%rax, %rdx
	leaq	.LC16(%rip), %rsi
	leaq	.LC15(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L58
.L59:
	movq	40(%rbp), %rax
	movq	-16(%rbp), %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	-8(%rbp), %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	%rax, %rsi
	leaq	.LC12(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
.L58:
	addq	$1, -8(%rbp)
.L56:
	movq	24(%rbp), %rax
	cmpq	%rax, -8(%rbp)
	jb	.L60
	movl	$10, %edi
	call	putchar@PLT
	addq	$1, -16(%rbp)
.L55:
	movq	16(%rbp), %rax
	cmpq	%rax, -16(%rbp)
	jb	.L61
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE13:
	.size	print_matriz_object_with_mass_center, .-print_matriz_object_with_mass_center
	.globl	print_matriz
	.type	print_matriz, @function
print_matriz:
.LFB14:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	$0, -16(%rbp)
	jmp	.L63
.L66:
	movq	$0, -8(%rbp)
	jmp	.L64
.L65:
	movq	-16(%rbp), %rax
	leaq	0(,%rax,8), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	-8(%rbp), %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	%rax, %rsi
	leaq	.LC12(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	addq	$1, -8(%rbp)
.L64:
	movq	-8(%rbp), %rax
	cmpq	-40(%rbp), %rax
	jb	.L65
	movl	$10, %edi
	call	putchar@PLT
	addq	$1, -16(%rbp)
.L63:
	movq	-16(%rbp), %rax
	cmpq	-32(%rbp), %rax
	jb	.L66
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE14:
	.size	print_matriz, .-print_matriz
	.section	.rodata
.LC17:
	.string	"%d"
	.text
	.globl	write_object_to_file
	.type	write_object_to_file, @function
write_object_to_file:
.LFB15:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	$1, -16(%rbp)
	jmp	.L68
.L71:
	movq	$1, -8(%rbp)
	jmp	.L69
.L70:
	movq	40(%rbp), %rax
	movq	-16(%rbp), %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	-8(%rbp), %rdx
	salq	$3, %rdx
	addq	%rdx, %rax
	movq	(%rax), %rax
	cmpq	%rax, -32(%rbp)
	sete	%al
	movzbl	%al, %edx
	movq	-24(%rbp), %rax
	leaq	.LC17(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	addq	$1, -8(%rbp)
.L69:
	movq	32(%rbp), %rax
	subq	$1, %rax
	cmpq	%rax, -8(%rbp)
	jb	.L70
	movq	-24(%rbp), %rax
	movq	%rax, %rsi
	movl	$10, %edi
	call	fputc@PLT
	addq	$1, -16(%rbp)
.L68:
	movq	16(%rbp), %rax
	subq	$1, %rax
	cmpq	%rax, -16(%rbp)
	jb	.L71
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE15:
	.size	write_object_to_file, .-write_object_to_file
	.globl	wrap_with_zeros
	.type	wrap_with_zeros, @function
wrap_with_zeros:
.LFB16:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$56, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -56(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movq	$0, -40(%rbp)
	movq	-56(%rbp), %rax
	movq	(%rax), %rax
	addq	$2, %rax
	salq	$3, %rax
	movq	%rax, %rdi
	call	malloc@PLT
	movq	%rax, -40(%rbp)
	movq	-56(%rbp), %rax
	movq	16(%rax), %rax
	addq	$2, %rax
	movq	-40(%rbp), %rbx
	movl	$8, %esi
	movq	%rax, %rdi
	call	calloc@PLT
	movq	%rax, (%rbx)
	movq	$1, -32(%rbp)
	jmp	.L73
.L74:
	movq	-56(%rbp), %rax
	movq	16(%rax), %rax
	addq	$2, %rax
	movq	-40(%rbp), %rdx
	movq	-32(%rbp), %rcx
	salq	$3, %rcx
	leaq	(%rdx,%rcx), %rbx
	movl	$8, %esi
	movq	%rax, %rdi
	call	calloc@PLT
	movq	%rax, (%rbx)
	movq	-56(%rbp), %rax
	movq	16(%rax), %rax
	leaq	0(,%rax,8), %rdx
	movq	-56(%rbp), %rax
	movq	24(%rax), %rax
	movq	-32(%rbp), %rcx
	salq	$3, %rcx
	subq	$8, %rcx
	addq	%rcx, %rax
	movq	(%rax), %rax
	movq	-40(%rbp), %rcx
	movq	-32(%rbp), %rsi
	salq	$3, %rsi
	addq	%rsi, %rcx
	movq	(%rcx), %rcx
	addq	$8, %rcx
	movq	%rax, %rsi
	movq	%rcx, %rdi
	call	memcpy@PLT
	addq	$1, -32(%rbp)
.L73:
	movq	-56(%rbp), %rax
	movq	(%rax), %rax
	addq	$1, %rax
	cmpq	%rax, -32(%rbp)
	jb	.L74
	movq	-56(%rbp), %rax
	movq	16(%rax), %rax
	addq	$2, %rax
	movq	-40(%rbp), %rdx
	movq	-32(%rbp), %rcx
	salq	$3, %rcx
	leaq	(%rdx,%rcx), %rbx
	movl	$8, %esi
	movq	%rax, %rdi
	call	calloc@PLT
	movq	%rax, (%rbx)
	movq	-56(%rbp), %rax
	leaq	24(%rax), %rdx
	movq	-40(%rbp), %rax
	movq	%rax, (%rdx)
	movq	-56(%rbp), %rax
	movq	8(%rax), %rax
	leaq	2(%rax), %rdx
	movq	-56(%rbp), %rax
	movq	%rdx, 8(%rax)
	movq	-56(%rbp), %rax
	movq	(%rax), %rax
	leaq	2(%rax), %rdx
	movq	-56(%rbp), %rax
	movq	%rdx, (%rax)
	movq	-56(%rbp), %rax
	movq	16(%rax), %rax
	leaq	2(%rax), %rdx
	movq	-56(%rbp), %rax
	movq	%rdx, 16(%rax)
	nop
	movq	-24(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L75
	call	__stack_chk_fail@PLT
.L75:
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE16:
	.size	wrap_with_zeros, .-wrap_with_zeros
	.section	.rodata
	.align 16
.LC7:
	.long	0
	.long	2147483648
	.long	16447
	.long	0
	.align 8
.LC8:
	.long	0
	.long	1138753536
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
