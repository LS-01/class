/*************************************************************************
	> File Name: ls.c
	> Author: ls
	> Mail: 
	> Created Time: Fri 16 Oct 2020 11:55:26 PM CST
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>

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
    DIR *dir = NULL;
    struct dirent *direntp;
    if ((dir = opendir(name)) == NULL) {
        if (access(name, R_OK) == 0) {
            printf("%s ", name);
        }
    } else {
        if (dir_num > 2) printf("%s:\n", name);
        while ((direntp = readdir(dir))) {
            printf("\033[31;34m%s\033[0m ", direntp->d_name);
        }
    }
    printf("\n");
    return;
}
