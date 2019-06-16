.class public compiler_hw3
.super java/lang/Object
.method public static main([Ljava/lang/String;)V
.field public static v F = 1
.field public static e F = 6.000000
.field public static r F = 0.300000
.field public static b Ljava/lang/String; = "Hi"
    ldc 1.000000
    fstore 0
    fload 0
    ldc 6.000000
    fadd
    fstore 1
    ldc 5.000000
    fstore 2
    fload 2
    ldc 1.000000
    fadd
    fstore 3
    fload 3
    ldc 1.0
    fadd
    fstore 3
    fload 3
    fsub
    fstore -1
    fload 2
    ldc 1.0
    fsub
    fstore 2
    fload 2
    fstore 5
    ldc 4.000000
    ldc 2.000000
    frem
    fstore 6
	return
.end method
