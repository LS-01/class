/*************************************************************************
	> File Name: test_3.c
	> Author: ls
	> Mail: 
	> Created Time: Fri 18 Sep 2020 07:50:23 PM CST
 ************************************************************************/

#include <stdio.h>

int main() {
    int a = 7, b = 3;
    int *p = &a;
    //*p--; error
    (*p)--;
    --*p;
    printf("%d\n", a);
    printf("%d\n", a / b);
    printf("%lf\n", a * 1.0 / b);

    //swap
    printf("a = %d, b = %d\n", a, b);
    a ^= b;
    b ^= a;
    a ^= b;
    printf("swap: a = %d, b = %d\n", a, b);

    while (~scanf("%d", &a)) {
        printf("a = %d\n", a);
    }
    return 0;
}
