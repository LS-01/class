/*************************************************************************
	> File Name: 4.nonblock.c
	> Author: 
	> Mail: 
	> Created Time: 2021年04月15日 星期四 18时30分17秒
 ************************************************************************/

#include "common/head.h"

int main() {
    int age = 0;
    int flag = fcntl(0, F_GETFL);
    flag |= O_NONBLOCK;
    fcntl(0, F_SETFL, flag);
    scanf("%d", &age);
    printf("ls is %d years old!\n", age);

    int age1 = 0, age2 = 0;
    make_nonblock(0);
    int ret = scanf("%d", &age1);
    if (ret < 0) {
        if (errno == EAGAIN) {
            printf("EAGAIN\n");
        }
        perror("scanf");
    }
    make_block(0);
    scanf("%d", &age2);
    printf("%d %d\n", age1, age2);
    return 0;
}
