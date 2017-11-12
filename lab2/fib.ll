define i32 @fib(i32 %n)
{
	%cond = icmp eq i32 %n, 0
	br i1 %cond, label %Equal0, label %NotEqual0
Equal0:
	ret i32 0
NotEqual0:
	%cond1 = icmp eq i32 %n, 1
	br i1 %cond1, label %Equal1, label %NotEqual1
Equal1:
	ret i32 1
NotEqual1:
	%t0 = sub i32 %n, 1
	%t1 = call i32 @fib(i32 %t0)
	%t2 = sub i32 %n, 2
	%t3 = call i32 @fib(i32 %t2)
	%t4 = add i32 %t1, %t3
	ret i32 %t4
}
define i32 @main()
{
	%x = alloca i32
	store i32 0, i32* %x
	%i = alloca i32
	store i32 0, i32* %i
	br label %forcond
forcond:
	%t0 = load i32, i32* %i
	%cond = icmp slt i32 %t0, 10
	br i1 %cond, label %forexpr, label %forfini
forexpr:
	%t1 = load i32, i32* %x
	%t2 = load i32, i32* %i
	%t3 = call i32 @fib(i32 %t2)
	%t4 = add i32 %t1, %t3
	store i32 %t4, i32* %x
	%t5 = load i32, i32* %i
	%t6 = add i32 %t5, 1
	store i32 %t6, i32* %i
	br label %forcond
forfini:
	%t7 = load i32, i32* %x
	ret i32 %t7
}
