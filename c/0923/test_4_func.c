/*************************************************************************
	> File Name: test_4_func.c
	> Author: ls
	> Mail: 
	> Created Time: Thu 24 Sep 2020 07:26:05 PM CST
 ************************************************************************/

#include <stdio.h>

int funcB(int n) {
    if (n == 0) {
        return 0;
    }
    printf("funcB : %d\n", n);
    return 0;
}

int funcB(int);

int funcA(int n) {
    if (n == 0) {
        return 0;
    }
    printf("funcA : %d\n", n);
    funcB(n--);
    return 0;
}

int main() {
    funcA(5);
    return 0;
}
