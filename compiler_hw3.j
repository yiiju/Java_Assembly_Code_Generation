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
	fload 3
	fload 4
	fdiv
	fstore 5
	fload 5
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
f2i
	invokevirtual java/io/PrintStream/println(I)V
	return
.end method
