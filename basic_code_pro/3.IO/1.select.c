/*************************************************************************
	> File Name: 1.select.c
	> Author: 
	> Mail: 
	> Created Time: 2021年04月16日 星期五 21时33分35秒
 ************************************************************************/

#include "common/head.h"

int main() {
    int age;

    struct timeval tv;
    tv.tv_sec = 5;
    tv.tv_usec = 0;
    
    fd_set rfds;
    FD_ZERO(&rfds);
    FD_SET(0, &rfds);
    
    int ret = select(1, &rfds, NULL, NULL, &tv);
    if (ret < 0) {
        perror("select");
        exit(1);
    }
    if (ret > 0) {
        scanf("%d", &age);
    } else {
        age = 100;
    }
    
    printf("ls is %d years old\n", age);
    
    return 0;
}

