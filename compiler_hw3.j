.class public compiler_hw3
.super java/lang/Object
.field public static v F = 1.000000
.field public static f F = 2.000000
.field public static e F = 6.000000
.field public static r F = 0.300000
.field public static b Ljava/lang/String; = "Hi"
.method public static func()F
.limit stack 50
.limit locals 50
	ldc 5.000000
	freturn
.end method
.method public static func2(F)F
.limit stack 50
.limit locals 50
	fload 0
	freturn
.end method
.method public static func3(FLjava/lang/String;)F
.limit stack 50
.limit locals 50
	fload 0
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
	invokestatic compiler_hw3/func()F
	fstore 2
	ldc 1.0
	invokestatic compiler_hw3/func2(F)F
	fstore 3
	ldc "ss"
	astore 4
	ldc 2.0
	aload 4
	invokestatic compiler_hw3/func3(FLjava/lang/String;)F
	fstore 5
	fload 2
	ldc 1.0
	fadd
	fstore 2
	fload 2
	ldc 1.0
	fsub
	fstore 6
	fload 0
	ldc 1.0
	fsub
	fstore 0
	fload 0
	fstore 7
	ldc 4.000000
	ldc 2.000000
	fstore 49
	f2i
	fload 49
	f2i
	irem
i2f
	fstore 8
	return
.end method
