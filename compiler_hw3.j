.class public compiler_hw3
.super java/lang/Object
.method public static main([Ljava/lang/String;)V
.limit stack 50
.limit locals 50
	ldc 1.000000
	fstore 0
BEGIN_WHILE_0:
	fload 0
	ldc 6.000000
	fsub
	f2i
	iflt TRUE_WHILE_0
	goto EXIT_WHILE_0
TRUE_WHILE_0:
	fload 0
	f2i
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	fload 0
	ldc 1.000000
	fadd
	fstore 0
BEGIN_WHILE_1:
	fload 0
	ldc 6.000000
	fsub
	f2i
	iflt TRUE_WHILE_1
	goto EXIT_WHILE_1
TRUE_WHILE_1:
	fload 0
	f2i
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	fload 0
	ldc 1.000000
	fadd
	fstore 0
	goto BEGIN_WHILE_1
EXIT_WHILE_1:
BEGIN_WHILE_2:
	fload 0
	ldc 6.000000
	fsub
	f2i
	iflt TRUE_WHILE_2
	goto EXIT_WHILE_2
TRUE_WHILE_2:
	fload 0
	f2i
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	fload 0
	ldc 1.000000
	fadd
	fstore 0
BEGIN_WHILE_3:
	fload 0
	ldc 6.000000
	fsub
	f2i
	iflt TRUE_WHILE_3
	goto EXIT_WHILE_3
TRUE_WHILE_3:
	fload 0
	f2i
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	fload 0
	ldc 1.000000
	fadd
	fstore 0
	goto BEGIN_WHILE_3
EXIT_WHILE_3:
	goto BEGIN_WHILE_2
EXIT_WHILE_2:
	goto BEGIN_WHILE_0
EXIT_WHILE_0:
BEGIN_WHILE_4:
	fload 0
	ldc 6.000000
	fsub
	f2i
	iflt TRUE_WHILE_4
	goto EXIT_WHILE_4
TRUE_WHILE_4:
	fload 0
	f2i
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	fload 0
	ldc 1.000000
	fadd
	fstore 0
BEGIN_WHILE_5:
	fload 0
	ldc 6.000000
	fsub
	f2i
	iflt TRUE_WHILE_5
	goto EXIT_WHILE_5
TRUE_WHILE_5:
	fload 0
	f2i
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	goto BEGIN_WHILE_5
EXIT_WHILE_5:
	goto BEGIN_WHILE_4
EXIT_WHILE_4:
	return
.end method
