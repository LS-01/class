/*************************************************************************
	> File Name: test_3_max_int.c
	> Author: ls
	> Mail: 
	> Created Time: Thu 24 Sep 2020 07:10:42 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdarg.h>

int max_int(int n, ...) {
    if (n < 0) {
        return 0;
    }
    int ans = 0;
    va_list arg;
    va_start(arg, n);
    while (n--) {
        int temp = va_arg(arg, int);
        if (temp > ans) {
            ans = temp;
        }
    }
    va_end(arg);
    return ans;
}

int main() {
    printf("%d\n", max_int(3, 1, 2, 5));
    printf("%d\n", max_int(2, 1, 7, 17));
    printf("%d\n", max_int(3, 3, 6, 18));
    return 0;
}
