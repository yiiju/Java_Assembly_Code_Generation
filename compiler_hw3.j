.class public compiler_hw3
.super java/lang/Object
.field public static v F = 1.000000
.field public static e F = 6.000000
.field public static r F = 0.300000
.field public static b Ljava/lang/String; = "Hi"
.method public static fun(FLjava/lang/String;)V
.limit stack 50
.limit locals 50
.method public static main([Ljava/lang/String;)V
.limit stack 50
.limit locals 50
    ldc 1.000000
    fstore 2
    fload 2
    ldc 6.000000
    fadd
    fstore 3
    ldc "ss"
    astore 2
    fload 2
    ldc 1.0
    fsub
    fstore 2
    fload 2
    fstore 5
    fload 3
    getstatic java/lang/System/out Ljava/io/PrintStream;
    swap
    invokevirtual java/io/PrintStream/println(F)V
	return
.end method
