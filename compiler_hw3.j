.class public compiler_hw3
.super java/lang/Object
.method public static main([Ljava/lang/String;)V
.field public static v F = 1
.field public static e F = 6.000000
.field public static r F = 0.300000
.field public static b Ljava/lang/String; = "Hi"
    fload 0
    fload 1
    ldc 1.000000
    fstore 3
    fload 3
    ldc 6.000000
    fadd
    fstore 4
    invokestatic compiler_hw3/func()F
    fstore 5
    invokestatic compiler_hw3/func2(F)F
    fstore -1
    ldc ss
    astore 4
    aload 7
    invokestatic compiler_hw3/func3(FLjava/lang/String;)F
    fstore 8
    fload 5
    ldc 1.0
    fadd
    fstore 5
    fload 5
    fsub
    fstore -1
    fload 3
    ldc 1.0
    fsub
    fstore 3
    fload 3
    fstore 10
    ldc 4.000000
    ldc 2.000000
    frem
    fstore 11
	return
.end method
