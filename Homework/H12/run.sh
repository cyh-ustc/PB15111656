#!/bin/sh
gcc fact_1.c -o fact_1_gcc.out
gcc fact_1.c -S -o fact_1_gcc.s
gcc fact_abs.c -o fact_abs_gcc.out
gcc fact_abs.c -S -o fact_abs_gcc.s
clang fact_1.c -o fact_1_clang.out
clang fact_1.c -S -o fact_1_clang.s
clang fact_abs.c -o fact_abs_clang.out
clang fact_abs.c -S -o fact_abs_clang.s
gcc plusplus_in.c -o plusplus_in_gcc.out
gcc plusplus_in.c -S -o plusplus_in_gcc.s
clang plusplus_in.c -o plusplus_in_clang.out
clang plusplus_in.c -S -o plusplus_in_clang.s
gcc plusplus_out.c -o plusplus_out_gcc.out
gcc plusplus_out.c -S -o plusplus_out_gcc.s
clang plusplus_out.c -o plusplus_out_clang.out
clang plusplus_out.c -S -o plusplus_out_clang.s
