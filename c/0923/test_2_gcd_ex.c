/*************************************************************************
	> File Name: test_2_gcd_ex.c
	> Author: ls
	> Mail: 
	> Created Time: Thu 24 Sep 2020 06:27:51 PM CST
 ************************************************************************/

#include <stdio.h>

int ex_gcd(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
       return a; 
    }
    int xx, yy, ret = ex_gcd(b, a % b, &xx, &yy);
    *x = yy;
    *y = xx - yy * (a / b);
    return ret;
}

int main() {
    int a, b, x, y;
    while (~scanf("%d%d", &a, &b)) {
        printf("gcd(%d, %d) = %d\n", a, b, ex_gcd(a, b, &x, &y));
        printf("%d * %d + %d * %d = %d\n", a, x, b, y, a * x + b * y);
    }
    return 0;
}
