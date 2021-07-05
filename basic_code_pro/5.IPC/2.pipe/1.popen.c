/*************************************************************************
	> File Name: 1.popen.c
	> Author: ls
	> Mail: 
	> Created Time: Thu 01 Jul 2021 07:47:18 PM CST
 ************************************************************************/

#include "common/head.h"
#include "my_popen.h"

int main() {
    FILE *fp;
    char buff[512] = {0};
    if ((fp = my_popen("cat ./1.popen.c", "r")) == NULL) {
        perror("popen");
        exit(1);
    }
    while (fgets(buff, sizeof(buff), fp) != NULL) {
        printf("%s", buff);
        memset(buff, 0, sizeof(buff));
    }
    sleep(10);
    my_pclose(fp);
    sleep(10);
    return 0;
}
