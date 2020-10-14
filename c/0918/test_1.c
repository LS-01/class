/*************************************************************************
	> File Name: test_1.c
	> Author: ls
	> Mail: 
	> Created Time: Fri 18 Sep 2020 07:28:06 PM CST
 ************************************************************************/

#include <stdio.h>
#include <math.h>

int main() {
    double x;
    scanf("%lf", &x);

    //link with -lm
    printf("%lf\n", pow(x, 1.0 / 3.0));
    return 0;
}
