.class public compiler_hw3
.super java/lang/Object
.method public static main([Ljava/lang/String;)V
.limit stack 50
.limit locals 50
	ldc 20.000000
	fstore 0
	fload 0
	ldc 40.000000
	fsub
	f2i
	ifne IF_0_0
	ldc "a is equal to 40"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	ldc 4.000000
	fstore 1
	fload 1
	ldc 4.000000
	fsub
	f2i
	ifne IF_1_0
	fload 1
	f2i
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	goto EXIT_IF_1
IF_1_0:
	fload 1
	ldc 7.000000
	fsub
	f2i
	ifne IF_1_1
	ldc 9.000000
	fstore 2
	fload 2
	f2i
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	goto EXIT_IF_1
IF_1_1:
EXIT_IF_1:
	goto EXIT_IF_0
IF_0_0:
	fload 0
	ldc 40.000000
	fsub
	f2i
	ifle IF_0_1
	ldc "a is larger than 40"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	fload 0
	ldc 50.000000
	fsub
	f2i
	ifle IF_2_0
	ldc "a > 50"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	goto EXIT_IF_2
IF_2_0:
EXIT_IF_2:
	goto EXIT_IF_0
IF_0_1:
	ldc 666.000000
	f2i
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	goto EXIT_IF_0
EXIT_IF_0:
	fload 0
	ldc 30.000000
	fsub
	f2i
	ifne IF_3_0
	ldc "a == 30"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	goto EXIT_IF_3
IF_3_0:
	fload 0
	ldc 20.000000
	fsub
	f2i
	ifne IF_3_1
	fload 0
	ldc 20.000000
	fsub
	f2i
	ifne IF_4_0
	ldc "a == 20"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	goto EXIT_IF_4
IF_4_0:
	ldc "fail"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	goto EXIT_IF_4
EXIT_IF_4:
	ldc "succ"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	goto EXIT_IF_3
IF_3_1:
EXIT_IF_3:
	return
.end method
