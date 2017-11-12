使用makefile编译，运行直接打印llvmir到终端

```sh
make
./fib_gen
```





```sh
make
./fib_gen > f.ll
lli f.ll
echo $?
```

可以看到返回值为88
