/*************************************************************************
	> File Name: test_1.c
	> Author: ls
	> Mail: 
	> Created Time: Sun 20 Sep 2020 02:19:16 PM CST
 ************************************************************************/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    if (n < 0) {
        return -1;
    }
    if (!n) {
        printf("FOOLISH\n");
    } else if (n < 60) {
        printf("FAIL\n");
    } else if (n < 75) {
        printf("MEDIUM\n");
    } else if (n <= 100){
        printf("GOOD\n");
    }
    return 0;
}
