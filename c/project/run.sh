#!/bin/bash

#g++ -std=c++11 -I./include  test.c -L./lib -lgtest -lpthread
g++ test.c -lgtest -lpthread
./a.out
