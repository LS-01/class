#!/bin/bash

gcc -c -I./module/include ./module/src/header1.c
gcc -c -I./module/include ./module/src/header2.c
gcc -c -I./module/include ./module/src/header3.c

ar -r ./module/lib/libhaizei.a header1.o header2.o header3.o

gcc -c -I./module/include test.c
gcc test.o -L./module/lib/ -lhaizei

rm ./module/lib/libhaizei.a
rm *.o

./a.out

rm ./a.out
