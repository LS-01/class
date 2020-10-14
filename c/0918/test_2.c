/*************************************************************************
	> File Name: test_2.c
	> Author: ls
	> Mail: 
	> Created Time: Fri 18 Sep 2020 07:34:38 PM CST
 ************************************************************************/

#include <stdio.h>
#include <math.h>

#define PI acos(-1)

int main() {
    double x;
    scanf("%lf", &x);
    printf("%lf\n", PI / 180.0 * x);
    return 0;
}
