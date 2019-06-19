.class public compiler_hw3
.super java/lang/Object
.field public static v F = 1.000000
.field public static e F = 6.000000
.field public static r F = 0.300000
.field public static b Ljava/lang/String; = "Hi"
.method public static main([Ljava/lang/String;)V
.limit stack 50
.limit locals 50
	ldc 1.000000
	fstore 0
	fload 0
	ldc 6.000000
	fadd
	fstore 1
	ldc "ss"
	astore 2
	ldc 3.000000
	fstore 3
	fload 3
	ldc 1.0
	fadd
	fstore 3
	fload 3
	ldc 1.0
	fsub
	fstore 4
	ldc 5.000000
	ldc 3.000000
	fstore 49
	f2i
	fload 49
	f2i
	irem
i2f
	fstore 5
	fload 3
	ldc 3.000000
	fstore 49
	f2i
	fload 49
	f2i
	irem
i2f
	fstore 6
	ldc 5.000000
	fload 3
	fstore 3
	f2i
	fload 3
	f2i
	irem
i2f
	fstore 7
	fload 4
	fload 3
	fstore 3
	f2i
	fload 3
	f2i
	irem
i2f
	fstore 8
	fload 5
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(F)V
	fload 6
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(F)V
	fload 7
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(F)V
	fload 8
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(F)V
	return
.end method
