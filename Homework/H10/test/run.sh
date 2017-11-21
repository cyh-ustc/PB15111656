#!/bin/sh
gcc foo6.c bar6.c -o p1_m64.out
./p1_m64.out
gcc -m32 foo6.c bar6.c -o p1_m32.out
./p1_m32.out
gcc endian.c -o endian.out
./endian.out
