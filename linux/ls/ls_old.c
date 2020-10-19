/*************************************************************************
	> File Name: ls.c
	> Author: ls
	> Mail: 
	> Created Time: Fri 16 Oct 2020 11:55:26 PM CST
 ************************************************************************/

#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <string.h>

void do_ls(const char *);
int dir_num = 0;

//ls a.x b.y
int main(int argc, char *argv[]) { 
    dir_num = argc;
    if (argc == 1) {
        do_ls(".");
    } else {
        for (int i = 1; i < argc; i++) {
            do_ls(argv[i]);
        }
    }
    return 0;
}

void do_ls(const char *name) {
    struct winsize size;
    memset(&size, 0, sizeof(size));
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &size) < 0) {
        perror("ioctl()");
        exit(1);
    }
    printf("col = %d\n", size.ws_col);
    printf("row = %d\n", size.ws_row);

    char *files[dir_num];
    int file_index = 0;
    char *dirs[dir_num];
    int dir_file_num[dir_num];
    int dir_index = 0;

    DIR *dir = NULL;
    struct dirent *direntp;
    if ((dir = opendir(name)) == NULL) {
        if (access(name, R_OK) == 0) {
            printf("%s ", name);
            strcpy(files[file_index++], name);
        }
    } else {
        if (dir_num > 2) printf("%s:\n", name);
        strcpy(dirs[dir_index], name);
        int num = 0;
        while ((direntp = readdir(dir))) {
            num++;
            printf("\033[31;34m%s\033[0m ", direntp->d_name);
        }
        dir_file_num[dir_index] = num;
        dir_index++;
    }
    printf("\n");
    return;
}

