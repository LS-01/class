/*************************************************************************
	> File Name: test_2.c
	> Author: ls
	> Mail: 
	> Created Time: Wed 16 Sep 2020 07:25:30 PM CST
 ************************************************************************/

#include <stdio.h>

int main() {
    char str[100] = {0};
    while (scanf("%[^\n]s", str) != EOF) {
        //getchar();
        //
        //char c;
        //scanf("%c", &c);
        //
        printf(" has %d chars!\n", printf("%s", str));
        scanf("\n");
    }
    return 0;
}
