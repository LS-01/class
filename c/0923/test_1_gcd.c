/*************************************************************************
	> File Name: test_1_gcd.c
	> Author: ls
	> Mail: 
	> Created Time: Thu 24 Sep 2020 05:32:25 PM CST
 ************************************************************************/

#include <stdio.h>

int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}

int main() {
    int a, b;
    while (~scanf("%d%d", &a, &b)) {
        printf("%d\n", gcd(a, b));
    }
    return 0;
}
