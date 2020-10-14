/*************************************************************************
	> File Name: test_2.c
	> Author: ls
	> Mail: 
	> Created Time: Sun 20 Sep 2020 02:27:54 PM CST
 ************************************************************************/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    switch (n) {
        case 1: 
            printf("ONE\n");
            break;
        case 2: 
            printf("TWO\n");
            break;
        case 3: 
            printf("THREE\n");
            break;
        default: 
            printf("ERROR\n");
            break;
    }
    return 0;
}
