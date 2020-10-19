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
#include <math.h>
#include <ctype.h>

#define FILE_NAME_LENGTH 256

void do_ls(char **, int);
void show_files(char files[][FILE_NAME_LENGTH], int);
int files_sort_for_max_length(char files[][FILE_NAME_LENGTH], int);
int str_tolower_comp(char *, char *);

int main(int argc, char *argv[]) { 
    if (argc == 1) {
        do_ls(NULL, argc + 1);
    } else {
        do_ls(argv, argc);
    }
    return 0;
}

void do_ls(char **names, int size) {
    int dir_num = size;
    char files[dir_num][FILE_NAME_LENGTH];
    int file_index = 0;
    char dirs[dir_num][FILE_NAME_LENGTH];
    int max_dir_file_num = 0;
    int dir_index = 0;

    DIR *dir = NULL;
    struct dirent *direntp;

    for (int i = 1; i < dir_num; i++) {
        char *name;
        if (names == NULL) {
            name = "./";
        } else {
            name = names[i];
        }
        if ((dir = opendir(name)) == NULL) {
            if (access(name, R_OK) == 0) {
                strcpy(files[file_index], name);
                file_index++;
            }
        } else {
            strcpy(dirs[dir_index], name);
            dir_index++;
            int num = 0;
            while ((direntp = readdir(dir))) {
                num++;
            }
            closedir(dir);
            if (max_dir_file_num < num) {
                max_dir_file_num = num;
            }
        }
    }

    if (file_index > 0) {
        show_files(files, file_index);
    }

    char dir_files[max_dir_file_num][FILE_NAME_LENGTH];

    for (int i = 0; i < dir_index; i++) {
        int j = 0;
        if ((dir = opendir(dirs[i])) == NULL) {
            continue;
        }
        while ((direntp = readdir(dir))) {
            strcpy(dir_files[j++], direntp->d_name);
        }
        closedir(dir);
        if (dir_index > 1) {
            printf("%s\n", dirs[i]);
        }
        show_files(dir_files, j);
        if (dir_index > 1 && i != dir_index - 1) {
            printf("\n");
        }
    }
    return;
}

void show_files(char files[][FILE_NAME_LENGTH], int length) {
    int max_length = files_sort_for_max_length(files, length) + 1;
    
    struct winsize size;
    memset(&size, 0, sizeof(size));
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &size) < 0) {
        perror("ioctl()");
        exit(1);
    }

    int col = (int)floor(1.0 * size.ws_col / max_length);
    int row = (int)ceil(1.0 * length / col);
   
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i + j * row < length) {
                printf("%*s", 0 - max_length, files[i + j * row]);
            }
        }
        printf("\n");
    }

}

int files_sort_for_max_length(char files[][FILE_NAME_LENGTH], int length) {
    int max_length = 0;
    for (int i = 0; i < length; i++) {
        if (strlen(files[i]) > max_length) {
            max_length = strlen(files[i]);
        }
        int index = i;
        char name[FILE_NAME_LENGTH] = {0};
        strcpy(name, files[i]);
        for (int j = i + 1; j < length; j++) {
            if (str_tolower_comp(files[j], name) < 0) {
                index = j;
                strcpy(name, files[j]);
            }
        }
        strcpy(files[index], files[i]);
        strcpy(files[i], name);
    }
    return max_length;
}

int str_tolower_comp(char *s1, char *s2) {
    int s1_len = strlen(s1);
    int s2_len = strlen(s2);
    char s1_res[FILE_NAME_LENGTH] = {0};
    char s2_res[FILE_NAME_LENGTH] = {0};
    for (int i = 0; i < s1_len; i++) {
        if (isalpha(s1[i])) s1_res[i] = tolower(s1[i]);
        else s1_res[i] = s1[i];
    }
    for (int i = 0; i < s2_len; i++) {
        if (isalpha(s2[i])) s2_res[i] = tolower(s2[i]);
        else s2_res[i] = s2[i];
    }
    return strcmp(s1_res, s2_res);
}
