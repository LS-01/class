/*************************************************************************
	> File Name: test_2_MAX.c
	> Author: ls
	> Mail: 
	> Created Time: Wed 30 Sep 2020 08:36:45 PM CST
 ************************************************************************/

#include <stdio.h>

#define MAX(a, b) ({\
    __typeof(a) _a = a;\
    __typeof(b) _b = b;\
    _a > _b ? _a : _b;\
})

#define P(a) {\
    printf("%s = %d\n", #a, a);\
}

int main() {
    int a = 7;
    int _a = 0;
    int _b = 0;
    P(MAX(2, 3));
    P(5 + MAX(2, 3));
    P(MAX(2, MAX(3, 4)));
    P(MAX(2, 3 > 4 ? 3 : 4));
    P(MAX(a++, 6));
    P(a);
    //printf("%d\n", MAX(2, 3));
    //printf("%d\n", 5 + MAX(2, 3));
    //printf("%d\n", MAX(2, MAX(3, 4)));
    //printf("%d\n", MAX(2, 3 > 4 ? 3 : 4));
    //printf("%d\n", MAX(a++, 6));
    //printf("a = %d\n", a);
    return 0;
}
