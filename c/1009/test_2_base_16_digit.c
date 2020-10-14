/*************************************************************************
	> File Name: test_2_string.c
	> Author: ls
	> Mail: 
	> Created Time: Fri 09 Oct 2020 08:02:45 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char str[12];
    while(~scanf("%d", &n)){
        sprintf(str, "%X", n);
        printf("%s has %lu digits\n", str, strlen(str));
    }
    return 0;
}
