/*************************************************************************
	> File Name: test_1_data.c
	> Author: ls
	> Mail: 
	> Created Time: Sun 11 Oct 2020 03:22:30 PM CST
 ************************************************************************/

#include <stdio.h>
#define P(a) {\
    printf("%s = %d\n", #a, a);\
}
struct Data {
    int x, y;
};

int main() {
    struct Data a[2], *p = a;//a[1].x
    a[0].x = 1, a[0].y = 1;
    a[1].x = 2, a[1].y = 2;
    P(a[1].x);
    P((a + 1)->x);
    P((p + 1)->x);
    P(p[1].x);
    P((*(p + 1)).x);
    P((*(a + 1)).x);

    P((&a[0] + 1)->x);
    P((*(&a[0] + 1)).x);

    P(*((int *)p + 2));

    P(1[a].x);
    return 0;
}
