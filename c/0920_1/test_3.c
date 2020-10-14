/*************************************************************************
	> File Name: test_3.c
	> Author: ls
	> Mail: 
	> Created Time: Sun 20 Sep 2020 02:36:56 PM CST
 ************************************************************************/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    switch (n) {
        case 1:
            printf("one ");
        case 2:
            printf("two ");
        case 3:
            printf("three\n");
            break;
        default:
            printf("error\n");
            break;
    }
    return 0;
}
