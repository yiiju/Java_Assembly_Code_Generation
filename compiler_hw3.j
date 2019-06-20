.class public compiler_hw3
.super java/lang/Object
.field public static v F = 1.000000
.field public static e F = 6.000000
.field public static r F = 0.300000
.field public static b Ljava/lang/String; = "Hi"
.method public static fun(F)V
.limit stack 50
.limit locals 50
	ldc 3.000000
	fstore 1
	fload 0
	f2i
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	return
.end method
.method public static fun2(F)V
.limit stack 50
.limit locals 50
	return
.end method
.method public static func3()F
.limit stack 50
.limit locals 50
	ldc 1.400000
	freturn
.end method
.method public static func4(FLjava/lang/String;)V
.limit stack 50
.limit locals 50
	aload 1
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	return
.end method
.method public static func5()F
.limit stack 50
.limit locals 50
	ldc "in 5"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	ldc 8.300000
	freturn
.end method
.method public static main([Ljava/lang/String;)V
.limit stack 50
.limit locals 50
	ldc 1.000000
	fstore 0
	fload 0
	ldc 6.000000
	fadd
	fstore 1
	invokestatic compiler_hw3/func5()F
	fload 1
	f2i
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	fload 1
	ldc "hihi"
	invokestatic compiler_hw3/func4(FLjava/lang/String;)V
	ldc 3.000000
	invokestatic compiler_hw3/fun(F)V
	return
.end method
