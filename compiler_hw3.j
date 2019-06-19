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
	fstore 3
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
.method public static func4(FF)V
.limit stack 50
.limit locals 50
	return
.end method
.method public static func5()F
.limit stack 50
.limit locals 50
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
	fload 1
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(F)V
	return
.end method
