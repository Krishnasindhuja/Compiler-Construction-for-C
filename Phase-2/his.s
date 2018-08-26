 #    2
 #    3
 #    4
 #    5
 #    6
				# b_global_decl (i, alignment = 4, size = 4)
.globl i
	.data
	.align	4
	.type	i, @object
	.size	i, 4
i:
	.zero	4
				# b_global_decl (j, alignment = 4, size = 4)
.globl j
	.align	4
	.type	j, @object
	.size	j, 4
j:
	.zero	4
				# b_global_decl (k, alignment = 4, size = 4)
.globl k
	.align	4
	.type	k, @object
	.size	k, 4
k:
	.zero	4
 #    7
 #    8
				# b_global_decl (x, alignment = 4, size = 4)
.globl x
	.align	4
	.type	x, @object
	.size	x, 4
x:
	.zero	4
				# b_global_decl (y, alignment = 4, size = 4)
.globl y
	.align	4
	.type	y, @object
	.size	y, 4
y:
	.zero	4
				# b_global_decl (z, alignment = 4, size = 4)
.globl z
	.align	4
	.type	z, @object
	.size	z, 4
z:
	.zero	4
 #    9
 #   10
				# b_global_decl (d, alignment = 8, size = 8)
.globl d
	.align	8
	.type	d, @object
	.size	d, 8
d:
	.zero	8
 #   11
 #   12
				# b_global_decl (c, alignment = 1, size = 1)
.globl c
	.align	1
	.type	c, @object
	.size	c, 1
c:
	.zero	1
 #   13
 #   14
 #   15
 #   16
 #   17
 #   18
 #   19
 #   20
 #   21
				# b_func_prologue (main)
	.text
.global main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
 #   22
				# b_push_ext_addr (i)
	subl	$8, %esp
	movl	$i, (%esp)
				# b_push_const_int (34)
	movl	$34, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_assign (signed int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   23
				# b_push_ext_addr (k)
	subl	$8, %esp
	movl	$k, (%esp)
				# b_push_const_int (5)
	movl	$5, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_assign (signed int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   24
				# b_push_ext_addr (x)
	subl	$8, %esp
	movl	$x, (%esp)
				# b_push_ext_addr (i)
	subl	$8, %esp
	movl	$i, (%esp)
				# b_deref (signed int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_ext_addr (k)
	subl	$8, %esp
	movl	$k, (%esp)
				# b_deref (signed int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_arith_rel_op ( / , signed int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%eax, %edx
	sarl	$31, %edx
	idivl	%ecx
	movl	%eax, (%esp)
				# b_convert (signed int -> float)
	fildl	(%esp)
	fstps	(%esp)
				# b_assign (float)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   25
				# b_push_ext_addr (d)
	subl	$8, %esp
	movl	$d, (%esp)
				# b_push_ext_addr (x)
	subl	$8, %esp
	movl	$x, (%esp)
				# b_deref (float)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_convert (float -> double)
	flds	(%esp)
	fstpl	(%esp)
				# b_push_const_int (2)
	movl	$2, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_convert (signed int -> double)
	fildl	(%esp)
	fstpl	(%esp)
				# b_arith_rel_op ( * , double)
	fldl	8(%esp)
	fldl	(%esp)
	addl	$8, %esp
	fmulp	%st, %st(1)
	fstpl	(%esp)
				# b_assign (double)
	fldl	(%esp)
	addl	$8, %esp
	movl	(%esp), %eax
	fstpl	(%eax)
	fstpl	(%esp)
				# b_pop ()
	addl	$8, %esp
 #   26
				# b_push_ext_addr (c)
	subl	$8, %esp
	movl	$c, (%esp)
				# b_push_ext_addr (i)
	subl	$8, %esp
	movl	$i, (%esp)
				# b_deref (signed int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_convert (signed int -> signed char)
				# b_assign (signed char)
	movzbl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movb	%dl, (%eax)
	movb	%dl, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   27
				# b_push_ext_addr (c)
	subl	$8, %esp
	movl	$c, (%esp)
				# b_push_ext_addr (c)
	subl	$8, %esp
	movl	$c, (%esp)
				# b_deref (signed char)
	movl	(%esp), %eax
	movsbl	(%eax), %edx
	movb	%dl, (%esp)
				# b_convert (signed char -> signed int)
	movzbl	(%esp), %eax
	movsbl	%al, %eax
	movl	%eax, (%esp)
				# b_push_const_int (50)
	movl	$50, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( + , signed int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	addl	%ecx, %eax
	movl	%eax, (%esp)
				# b_convert (signed int -> signed char)
				# b_assign (signed char)
	movzbl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movb	%dl, (%eax)
	movb	%dl, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   28
				# b_alloc_arglist (28 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$32, %esp
				# b_push_ext_addr (i)
	subl	$8, %esp
	movl	$i, (%esp)
				# b_deref (signed int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_load_arg (signed int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 0(%esp)
				# b_push_ext_addr (x)
	subl	$8, %esp
	movl	$x, (%esp)
				# b_deref (float)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_convert (float -> double)
	flds	(%esp)
	fstpl	(%esp)
				# b_load_arg (double)
	movl	(%esp), %eax
	movl	4(%esp), %edx
	addl	$8, %esp
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
				# b_push_ext_addr (d)
	subl	$8, %esp
	movl	$d, (%esp)
				# b_deref (double)
	movl	(%esp), %eax
	fldl	(%eax)
	fstpl	(%esp)
				# b_load_arg (double)
	movl	(%esp), %eax
	movl	4(%esp), %edx
	addl	$8, %esp
	movl	%eax, 12(%esp)
	movl	%edx, 16(%esp)
				# b_push_ext_addr (c)
	subl	$8, %esp
	movl	$c, (%esp)
				# b_deref (signed char)
	movl	(%esp), %eax
	movsbl	(%eax), %edx
	movb	%dl, (%esp)
				# b_convert (signed char -> signed int)
	movzbl	(%esp), %eax
	movsbl	%al, %eax
	movl	%eax, (%esp)
				# b_load_arg (signed int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 20(%esp)
				# b_push_ext_addr (c)
	subl	$8, %esp
	movl	$c, (%esp)
				# b_deref (signed char)
	movl	(%esp), %eax
	movsbl	(%eax), %edx
	movb	%dl, (%esp)
				# b_convert (signed char -> signed int)
	movzbl	(%esp), %eax
	movsbl	%al, %eax
	movl	%eax, (%esp)
				# b_load_arg (signed int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 24(%esp)
				# b_funcall_by_name (f, signed int)
	call	f
	addl	$32, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   29
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (print_g, signed int)
	call	print_g
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   30
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (test_ref_params, signed int)
	call	test_ref_params
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   31
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (print_g, signed int)
	call	print_g
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   32
				# b_alloc_arglist (4 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$16, %esp
				# b_push_const_string ("this is a debugging message\n")
	.section	.rodata
.LC1:
.string	"this is a debugging message\n"
	.text
				# b_push_ext_addr (.LC1)
	subl	$8, %esp
	movl	$.LC1, (%esp)
				# b_load_arg (pointer)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 0(%esp)
				# b_funcall_by_name (printf, signed int)
	call	printf
	addl	$16, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   33
.LC0:
				# b_func_epilogue (main)
	leave
	ret
	.size	main, .-main
 #   34
 #   35
				# b_global_decl (ga, alignment = 4, size = 4)
.globl ga
	.data
	.align	4
	.type	ga, @object
	.size	ga, 4
ga:
	.zero	4
 #   36
				# b_global_decl (gd, alignment = 4, size = 4)
.globl gd
	.align	4
	.type	gd, @object
	.size	gd, 4
gd:
	.zero	4
 #   37
				# b_global_decl (gb, alignment = 4, size = 4)
.globl gb
	.align	4
	.type	gb, @object
	.size	gb, 4
gb:
	.zero	4
 #   38
				# b_global_decl (gc, alignment = 8, size = 8)
.globl gc
	.align	8
	.type	gc, @object
	.size	gc, 8
gc:
	.zero	8
 #   39
				# b_global_decl (ge, alignment = 1, size = 1)
.globl ge
	.align	1
	.type	ge, @object
	.size	ge, 1
ge:
	.zero	1
 #   40
 #   41
 #   42
				# b_func_prologue (f)
	.text
.global f
	.type	f, @function
f:
	pushl	%ebp
	movl	%esp, %ebp
				# b_store_formal_param (signed int)
				# b_store_formal_param (float)
	movl	12(%ebp), %eax
	movl	16(%ebp), %edx
	subl	$8, %esp
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
				# b_convert (double -> float)
	fldl	(%esp)
	fstps	(%esp)
				# b_store_formal_param (double)
	movl	20(%ebp), %eax
	movl	24(%ebp), %edx
	subl	$8, %esp
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
				# b_store_formal_param (signed int)
				# b_store_formal_param (signed char)
 #   43
				# b_push_ext_addr (ga)
	subl	$8, %esp
	movl	$ga, (%esp)
				# b_push_loc_addr (offset = 8)
	leal	8(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (signed int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_assign (signed int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   44
				# b_push_ext_addr (gb)
	subl	$8, %esp
	movl	$gb, (%esp)
				# b_push_loc_addr (offset = -8)
	leal	-8(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (float)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_assign (float)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   45
				# b_push_ext_addr (gc)
	subl	$8, %esp
	movl	$gc, (%esp)
				# b_push_loc_addr (offset = -16)
	leal	-16(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (double)
	movl	(%esp), %eax
	fldl	(%eax)
	fstpl	(%esp)
				# b_assign (double)
	fldl	(%esp)
	addl	$8, %esp
	movl	(%esp), %eax
	fstpl	(%eax)
	fstpl	(%esp)
				# b_pop ()
	addl	$8, %esp
 #   46
				# b_push_ext_addr (gd)
	subl	$8, %esp
	movl	$gd, (%esp)
				# b_push_loc_addr (offset = 28)
	leal	28(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (signed int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_assign (signed int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   47
				# b_push_ext_addr (ge)
	subl	$8, %esp
	movl	$ge, (%esp)
				# b_push_loc_addr (offset = 32)
	leal	32(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (signed char)
	movl	(%esp), %eax
	movsbl	(%eax), %edx
	movb	%dl, (%esp)
				# b_assign (signed char)
	movzbl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movb	%dl, (%eax)
	movb	%dl, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   48
 #   49
				# b_alloc_arglist (0 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$0, %esp
				# b_funcall_by_name (print_g, signed int)
	call	print_g
	addl	$0, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   50
 #   51
				# b_push_loc_addr (offset = -8)
	leal	-8(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_push_loc_addr (offset = -8)
	leal	-8(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (float)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_convert (float -> double)
	flds	(%esp)
	fstpl	(%esp)
				# b_push_loc_addr (offset = -16)
	leal	-16(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (double)
	movl	(%esp), %eax
	fldl	(%eax)
	fstpl	(%esp)
				# b_arith_rel_op ( + , double)
	fldl	8(%esp)
	fldl	(%esp)
	addl	$8, %esp
	faddp	%st, %st(1)
	fstpl	(%esp)
				# b_push_loc_addr (offset = 28)
	leal	28(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (signed int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_convert (signed int -> double)
	fildl	(%esp)
	fstpl	(%esp)
				# b_arith_rel_op ( + , double)
	fldl	8(%esp)
	fldl	(%esp)
	addl	$8, %esp
	faddp	%st, %st(1)
	fstpl	(%esp)
				# b_push_loc_addr (offset = 8)
	leal	8(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (signed int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_convert (signed int -> double)
	fildl	(%esp)
	fstpl	(%esp)
				# b_arith_rel_op ( + , double)
	fldl	8(%esp)
	fldl	(%esp)
	addl	$8, %esp
	faddp	%st, %st(1)
	fstpl	(%esp)
				# b_push_loc_addr (offset = 32)
	leal	32(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (signed char)
	movl	(%esp), %eax
	movsbl	(%eax), %edx
	movb	%dl, (%esp)
				# b_convert (signed char -> signed int)
	movzbl	(%esp), %eax
	movsbl	%al, %eax
	movl	%eax, (%esp)
				# b_convert (signed int -> double)
	fildl	(%esp)
	fstpl	(%esp)
				# b_arith_rel_op ( + , double)
	fldl	8(%esp)
	fldl	(%esp)
	addl	$8, %esp
	faddp	%st, %st(1)
	fstpl	(%esp)
				# b_convert (double -> float)
	fldl	(%esp)
	fstps	(%esp)
				# b_assign (float)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   52
 #   53
				# b_alloc_arglist (28 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$32, %esp
				# b_push_loc_addr (offset = 8)
	leal	8(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (signed int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_load_arg (signed int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 0(%esp)
				# b_push_loc_addr (offset = -8)
	leal	-8(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (float)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_convert (float -> double)
	flds	(%esp)
	fstpl	(%esp)
				# b_load_arg (double)
	movl	(%esp), %eax
	movl	4(%esp), %edx
	addl	$8, %esp
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
				# b_push_loc_addr (offset = -16)
	leal	-16(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (double)
	movl	(%esp), %eax
	fldl	(%eax)
	fstpl	(%esp)
				# b_load_arg (double)
	movl	(%esp), %eax
	movl	4(%esp), %edx
	addl	$8, %esp
	movl	%eax, 12(%esp)
	movl	%edx, 16(%esp)
				# b_push_loc_addr (offset = 28)
	leal	28(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (signed int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_load_arg (signed int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 20(%esp)
				# b_push_loc_addr (offset = 32)
	leal	32(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (signed char)
	movl	(%esp), %eax
	movsbl	(%eax), %edx
	movb	%dl, (%esp)
				# b_convert (signed char -> signed int)
	movzbl	(%esp), %eax
	movsbl	%al, %eax
	movl	%eax, (%esp)
				# b_load_arg (signed int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 24(%esp)
				# b_funcall_by_name (print_p, signed int)
	call	print_p
	addl	$32, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   54
				# b_alloc_arglist (28 bytes)
	movl	%esp, %eax
	subl	$4, %esp
	andl	$-16, %esp
	movl	%eax, (%esp)
	subl	$32, %esp
				# b_push_loc_addr (offset = 8)
	leal	8(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (signed int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_const_int (1)
	movl	$1, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( * , signed int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	imull	%ecx, %eax
	movl	%eax, (%esp)
				# b_load_arg (signed int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 0(%esp)
				# b_push_loc_addr (offset = -8)
	leal	-8(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (float)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_convert (float -> double)
	flds	(%esp)
	fstpl	(%esp)
				# b_push_loc_addr (offset = -16)
	leal	-16(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (double)
	movl	(%esp), %eax
	fldl	(%eax)
	fstpl	(%esp)
				# b_arith_rel_op ( + , double)
	fldl	8(%esp)
	fldl	(%esp)
	addl	$8, %esp
	faddp	%st, %st(1)
	fstpl	(%esp)
				# b_load_arg (double)
	movl	(%esp), %eax
	movl	4(%esp), %edx
	addl	$8, %esp
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
				# b_push_loc_addr (offset = -8)
	leal	-8(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (float)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_convert (float -> double)
	flds	(%esp)
	fstpl	(%esp)
				# b_push_loc_addr (offset = -16)
	leal	-16(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (double)
	movl	(%esp), %eax
	fldl	(%eax)
	fstpl	(%esp)
				# b_push_loc_addr (offset = 28)
	leal	28(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (signed int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_convert (signed int -> double)
	fildl	(%esp)
	fstpl	(%esp)
				# b_arith_rel_op ( == , double)
	fldl	8(%esp)
	fldl	(%esp)
	addl	$8, %esp
	fucompp
	fnstsw	%ax
	sahf
	sete	%al
	setnp	%dl
	andl	%edx, %eax
	movzbl	%al, %eax
	movl	%eax, (%esp)
				# b_convert (signed int -> double)
	fildl	(%esp)
	fstpl	(%esp)
				# b_arith_rel_op ( + , double)
	fldl	8(%esp)
	fldl	(%esp)
	addl	$8, %esp
	faddp	%st, %st(1)
	fstpl	(%esp)
				# b_load_arg (double)
	movl	(%esp), %eax
	movl	4(%esp), %edx
	addl	$8, %esp
	movl	%eax, 12(%esp)
	movl	%edx, 16(%esp)
				# b_push_loc_addr (offset = 28)
	leal	28(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (signed int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_load_arg (signed int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 20(%esp)
				# b_push_loc_addr (offset = 28)
	leal	28(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (signed int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_loc_addr (offset = 32)
	leal	32(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (signed char)
	movl	(%esp), %eax
	movsbl	(%eax), %edx
	movb	%dl, (%esp)
				# b_convert (signed char -> signed int)
	movzbl	(%esp), %eax
	movsbl	%al, %eax
	movl	%eax, (%esp)
				# b_arith_rel_op ( == , signed int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	cmpl	%ecx, %eax
	sete	%al
	movzbl	%al, %eax
	movl	%eax, (%esp)
				# b_load_arg (signed int)
	movl	(%esp), %eax
	addl	$8, %esp
	movl	%eax, 24(%esp)
				# b_funcall_by_name (print_p, signed int)
	call	print_p
	addl	$32, %esp
	movl	(%esp), %ecx
	movl	%ecx, %esp
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   55
.LC2:
				# b_func_epilogue (f)
	leave
	ret
	.size	f, .-f
 #   56
 #   57
 #   58
 #   59
 #   60
				# b_func_prologue (ref_params)
.global ref_params
	.type	ref_params, @function
ref_params:
	pushl	%ebp
	movl	%esp, %ebp
				# b_store_formal_param (pointer)
				# b_store_formal_param (pointer)
				# b_store_formal_param (pointer)
				# b_store_formal_param (pointer)
				# b_store_formal_param (pointer)
 #   61
 #   62
				# b_push_loc_addr (offset = 12)
	leal	12(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_loc_addr (offset = 24)
	leal	24(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_deref (signed int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_loc_addr (offset = 12)
	leal	12(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_deref (signed int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_arith_rel_op ( - , signed int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	subl	%ecx, %eax
	movl	%eax, (%esp)
				# b_assign (signed int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   63
				# b_push_loc_addr (offset = 24)
	leal	24(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_loc_addr (offset = 24)
	leal	24(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_deref (signed int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_loc_addr (offset = 12)
	leal	12(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_deref (signed int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_arith_rel_op ( - , signed int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	subl	%ecx, %eax
	movl	%eax, (%esp)
				# b_assign (signed int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   64
				# b_push_loc_addr (offset = 12)
	leal	12(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_loc_addr (offset = 24)
	leal	24(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_deref (signed int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_loc_addr (offset = 12)
	leal	12(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_deref (signed int)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_arith_rel_op ( + , signed int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	addl	%ecx, %eax
	movl	%eax, (%esp)
				# b_assign (signed int)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   65
 #   66
				# b_push_loc_addr (offset = 20)
	leal	20(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_loc_addr (offset = 16)
	leal	16(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_deref (float)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_convert (float -> double)
	flds	(%esp)
	fstpl	(%esp)
				# b_push_loc_addr (offset = 20)
	leal	20(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_deref (double)
	movl	(%esp), %eax
	fldl	(%eax)
	fstpl	(%esp)
				# b_arith_rel_op ( - , double)
	fldl	8(%esp)
	fldl	(%esp)
	addl	$8, %esp
	fsubrp	%st, %st(1)
	fstpl	(%esp)
				# b_assign (double)
	fldl	(%esp)
	addl	$8, %esp
	movl	(%esp), %eax
	fstpl	(%eax)
	fstpl	(%esp)
				# b_pop ()
	addl	$8, %esp
 #   67
				# b_push_loc_addr (offset = 16)
	leal	16(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_loc_addr (offset = 16)
	leal	16(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_deref (float)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_convert (float -> double)
	flds	(%esp)
	fstpl	(%esp)
				# b_push_loc_addr (offset = 20)
	leal	20(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_deref (double)
	movl	(%esp), %eax
	fldl	(%eax)
	fstpl	(%esp)
				# b_arith_rel_op ( - , double)
	fldl	8(%esp)
	fldl	(%esp)
	addl	$8, %esp
	fsubrp	%st, %st(1)
	fstpl	(%esp)
				# b_convert (double -> float)
	fldl	(%esp)
	fstps	(%esp)
				# b_assign (float)
	movl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movl	%edx, (%eax)
	movl	%edx, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   68
				# b_push_loc_addr (offset = 20)
	leal	20(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_loc_addr (offset = 16)
	leal	16(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_deref (float)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_convert (float -> double)
	flds	(%esp)
	fstpl	(%esp)
				# b_push_loc_addr (offset = 20)
	leal	20(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_deref (double)
	movl	(%esp), %eax
	fldl	(%eax)
	fstpl	(%esp)
				# b_arith_rel_op ( + , double)
	fldl	8(%esp)
	fldl	(%esp)
	addl	$8, %esp
	faddp	%st, %st(1)
	fstpl	(%esp)
				# b_assign (double)
	fldl	(%esp)
	addl	$8, %esp
	movl	(%esp), %eax
	fstpl	(%eax)
	fstpl	(%esp)
				# b_pop ()
	addl	$8, %esp
 #   69
 #   70
				# b_push_loc_addr (offset = 8)
	leal	8(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_push_loc_addr (offset = 8)
	leal	8(%ebp), %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_deref (pointer)
	movl	(%esp), %eax
	movl	(%eax), %edx
	movl	%edx, (%esp)
				# b_deref (signed char)
	movl	(%esp), %eax
	movsbl	(%eax), %edx
	movb	%dl, (%esp)
				# b_convert (signed char -> signed int)
	movzbl	(%esp), %eax
	movsbl	%al, %eax
	movl	%eax, (%esp)
				# b_push_const_int (6)
	movl	$6, %eax
	subl	$8, %esp
	movl	%eax, (%esp)
				# b_arith_rel_op ( + , signed int)
	movl	(%esp), %ecx
	addl	$8, %esp
	movl	(%esp), %eax
	addl	%ecx, %eax
	movl	%eax, (%esp)
				# b_convert (signed int -> signed char)
				# b_assign (signed char)
	movzbl	(%esp), %edx
	addl	$8, %esp
	movl	(%esp), %eax
	movb	%dl, (%eax)
	movb	%dl, (%esp)
				# b_pop ()
	addl	$8, %esp
 #   71
.LC3:
				# b_func_epilogue (ref_params)
	leave
	ret
	.size	ref_params, .-ref_params
 #   72
