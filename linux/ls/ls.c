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
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

#define FILE_NAME_LENGTH 256

#define COLOR(a, color) "\033[" #color "m" a "\033[0m"
#define COLOR_HL(a, color) "\033[1;" #color "m" a "\033[0m"
#define RED(a) COLOR(a, 31)
#define GREEN(a) COLOR(a, 32)
#define YELLOW(a) COLOR(a, 33)
#define BLUE(a) COLOR(a, 34)
#define CYAN(a) COLOR(a, 36)
#define GREEN_HL(a) COLOR_HL(a, 32)

void do_ls(char **, int);
void show_files(char files[][FILE_NAME_LENGTH], int, char *);
void print_name(char *, int, char *);
int files_sort_for_max_length(char files[][FILE_NAME_LENGTH], int);
int str_tolower_comp(char *, char *);

struct {
    int show_all;
    int show_list;
} show_config;

int main(int argc, char *argv[]) {
    char tmp = '\0';
    while ((tmp = getopt(argc, argv, "al")) != -1) {
        switch (tmp) {
            case 'a':
                show_config.show_all = 1;
                break;
            case 'l':
                show_config.show_list = 1;
                break;
        }
    }
    do_ls(argv, argc);
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
                if (direntp->d_name[0] == '.'){
                    if (show_config.show_all) {
                        num++;
                    }
                } else {
                    num++;
                }
            }
            closedir(dir);
            if (max_dir_file_num < num) {
                max_dir_file_num = num;
            }
        }
    }

    if (file_index <= 0 && dir_index <= 0) {
        do_ls(NULL, 2);
    }

    if (file_index > 0) {
        show_files(files, file_index, NULL);
    }

    char dir_files[max_dir_file_num][FILE_NAME_LENGTH];

    if (dir_index > 1) {
        files_sort_for_max_length(dirs, dir_index);
    }

    for (int i = 0; i < dir_index; i++) {
        int j = 0;
        if ((dir = opendir(dirs[i])) == NULL) {
            continue;
        }
        while ((direntp = readdir(dir))) {
            if (direntp->d_name[0] == '.') {
                if (show_config.show_all) {
                    strcpy(dir_files[j++], direntp->d_name);
                }
            } else {
                strcpy(dir_files[j++], direntp->d_name);
            }
        }
        closedir(dir);
        if (dir_index > 1) {
            printf("%s:\n", dirs[i]);
        }
        show_files(dir_files, j, dirs[i]);
        if (dir_index > 1 && i != dir_index - 1) {
            printf("\n");
        }
    }
    return;
}

void show_files(char files[][FILE_NAME_LENGTH], int length, char *dir_name) {
    int max_length = files_sort_for_max_length(files, length) + 1;
    struct winsize size;
    memset(&size, 0, sizeof(size));
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &size) < 0) {
        perror("ioctl()");
        exit(EXIT_FAILURE);
    }

    int col = (int)floor(1.0 * size.ws_col / max_length);
    int row = (int)ceil(1.0 * length / col);

    if (show_config.show_list) {
        for (int i = 0; i < length; i++) {
            print_name(files[i], 0 - max_length, dir_name);
            printf("\n");
        }
    } else {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (i + j * row < length) {
                    print_name(files[i + j * row], 0 - max_length, dir_name);
                }
            }
            printf("\n");
        }
    }
}

void print_name(char *name, int style, char *dir_name) {
    char full_name[FILE_NAME_LENGTH * 2 + 5];
    if (dir_name != NULL) {
        sprintf(full_name, "%s/%s", dir_name, name);
    } else {
        sprintf(full_name, "%s", name);
    }
    struct stat sb;
    if (lstat(full_name, &sb) == -1) {
        perror("lstat");
        exit(EXIT_FAILURE);
    }

    char mode[11] = {0};

    char *frm;
    switch (sb.st_mode & S_IFMT) {
        case S_IFBLK:
            mode[0] = 'b';
            frm = YELLOW("%*s");
            break;
        case S_IFCHR:
            mode[0] = 'c';
            frm = YELLOW("%*s");
            break;
        case S_IFDIR:
            mode[0] = 'd';
            frm = BLUE("%*s");
            break;
        case S_IFIFO:
            mode[0] = 'p';
            frm = BLUE("%*s");
            break;
        case S_IFLNK:
            mode[0] = 'l';
            frm = CYAN("%*s");
            break;
        case S_IFREG:
            mode[0] = '-';
            if (access(full_name, X_OK) == 0) {
                frm = GREEN_HL("%*s");
            } else {
                frm = "%*s";
            }
            break;
        case S_IFSOCK:
            mode[0] = 's';
            frm = YELLOW("%*s");
            break;
    }

    if (show_config.show_list) {
        struct passwd *pd = getpwuid(sb.st_uid);
        struct group *gp = getgrgid(sb.st_gid);

        if (sb.st_mode & S_IRUSR) {
            mode[1] = 'r';
        } else {
            mode[1] = '-';
        }
        if (sb.st_mode & S_IWUSR) {
            mode[2] = 'w';
        } else {
            mode[2] = '-';
        }
        if (sb.st_mode & S_IXUSR) {
            mode[3] = 'x';
        } else {
            mode[3] = '-';
        }
        if (sb.st_mode & S_IRGRP) {
            mode[4] = 'r';
        } else {
            mode[4] = '-';
        }
        if (sb.st_mode & S_IWGRP) {
            mode[5] = 'w';
        } else {
            mode[5] = '-';
        }
        if (sb.st_mode & S_IXGRP) {
            mode[6] = 'x';
        } else {
            mode[6] = '-';
        }
        if (sb.st_mode & S_IROTH) {
            mode[7] = 'r';
        } else {
            mode[7] = '-';
        }
        if (sb.st_mode & S_IWOTH) {
            mode[8] = 'w';
        } else {
            mode[8] = '-';
        }
        if (sb.st_mode & S_IXOTH) {
            mode[9] = 'x';
        } else {
            mode[9] = '-';
        }
        char time[13] = {0};
        char *c_time = ctime(&sb.st_ctime);
        for (int i = 4; i < 16; i++) {
            time[i - 4] = c_time[i];
        }
        printf("%s ", mode);
        printf("%ld ", (long)sb.st_nlink);
        printf("%s ", pd->pw_name);
        printf("%s ", gp->gr_name);
        printf("%lld ", (long long)sb.st_size);
        printf("%s ", time);
        printf(frm, style, name); 
    } else {
        printf(frm, style, name);
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
