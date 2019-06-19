.class public compiler_hw3
.super java/lang/Object
.method public static foo(F)F
.limit stack 50
.limit locals 50
	fload 0
	ldc 6.000000
	fadd
	fstore 0
	fload 0
	freturn
.end method
.method public static lol(F)V
.limit stack 50
.limit locals 50
	fload 0
	f2i
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	return
.end method
.method public static main([Ljava/lang/String;)V
.limit stack 50
.limit locals 50
	ldc 0.0
	fstore 0
	ldc 4.000000
	invokestatic compiler_hw3/foo(F)F
	fstore 0
	fload 0
	invokestatic compiler_hw3/lol(F)V
	return
.end method
