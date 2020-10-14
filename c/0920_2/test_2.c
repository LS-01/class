/*************************************************************************
	> File Name: test_2.c
	> Author: ls
	> Mail: 
	> Created Time: Sun 20 Sep 2020 07:34:27 PM CST
 ************************************************************************/

#include <stdio.h>

int fac(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * fac(n - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", fac(n));
    return 0;
}
