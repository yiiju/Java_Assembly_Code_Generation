.class public compiler_hw3
.super java/lang/Object
.field public static a F = 6.000000
.field public static b F
.method public static main([Ljava/lang/String;)V
.limit stack 50
.limit locals 50
	ldc 0.0
	fstore 0
	getstatic compiler_hw3/a F
	ldc 6.000000
	fadd
	fstore 0
	fload 0
	f2i
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	return
.end method
