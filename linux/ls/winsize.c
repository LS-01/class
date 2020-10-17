/*************************************************************************
	> File Name: winsize.c
	> Author: ls
	> Mail: 
	> Created Time: Sat 17 Oct 2020 11:19:01 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <string.h>

int main() {
    struct winsize size;
    memset(&size, 0, sizeof(size));
    while (1) {
        sleep(1);
        if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &size) < 0) {
            perror("ioctl()");
            exit(1);
        }
        printf("col = %d\n", size.ws_col);
        printf("row = %d\n", size.ws_row);
    }

    return 0;
}
