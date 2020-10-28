/*************************************************************************
	> File Name: ls_t.c
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
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

#define MAXFILE 1024
#define MAXNAME 512

int a_flag = 0;
int l_flag = 0;
int bg_c, fg_c;
int *wide;

void do_ls(const char *);
void do_stat(const char *);
void size_window(char filename[][MAXNAME], int num, int *row, int *col);
void show_files(char filename[][MAXNAME], int num, int row, int col);
char *uid_to_name(uid_t);
char *gid_to_name(gid_t);
void show_info(const char *, struct stat *);
void mode_to_str(char *modestr, mode_t mode);
void update_color(mode_t mode);

int dir_num = 0;

//ls a.x b.y
int main(int argc, char *argv[]) {
    int opt;
    while ((opt = getopt(argc, argv, "al")) != -1) {
        switch (opt) {
            case 'a':
                a_flag = 1;
                break;
            case 'l':
                l_flag = 1;
                break;
            default:
                fprintf(stderr, "Usage : %s [-al] file...\n", argv[0]);
                exit(1);
        }
    }
    argc -= (optind - 1);
    argv += (optind - 1);

    dir_num = argc;
    //printf("dir_num = %d\n", argc);
    //printf("optind = %d\n", optind);
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
    char names[MAXFILE][MAXNAME] = {0};
    if ((dir = opendir(name)) == NULL) {
        if (access(name, R_OK) == 0) {
            if (l_flag == 1) {
                do_stat(name);
            } else {
                struct stat tmp_st;
                lstat(name, &tmp_st);
                update_color(tmp_st.st_mode);
                printf("\033[%d;%dm%s\033[0m ", bg_c, fg_c, name);
            }
        }
    } else {
        if (dir_num > 2) printf("%s:\n", name);
        int cnt = 0;
        while ((direntp = readdir(dir))) {
            //printf("%s ", direntp->d_name);
            if ((a_flag == 0) && (direntp->d_name[0] == '.')) {
                continue;
            }
            strcpy(names[cnt++], direntp->d_name);
        }
        //qsort(names, cnt, MAXNAME, cmp_name);
        if (l_flag == 0) {
            int row, col;
            size_window(names, cnt, &row, &col);
            //printf("row = %d, col = %d\n", row, col);
            show_files(names, cnt, row, col);
        } else {
            for (int i = 0; i < cnt; i++) {
                //bug
                do_stat(names[i]);
            }
        }
        printf("\n");
    }
    return;
}

void size_window(char filename[][MAXNAME], int num, int *row, int *col) {
    struct winsize size;
    int len[num], max = 0, total = 0;
    memset(len, 0, sizeof(int) * num);
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &size) < 0) {
        perror("ioctl");
        exit(1);
    }

    for (int i = 0; i < num; i++) {
        len[i] = strlen(filename[i]);
        if (max < len[i]) max = len[i];
        total += (len[i] + 2);
    }

    if (max + 1 >= size.ws_col) {
        *row = num;
        *col = 1;
        return;
    }

    if (total <= size.ws_col) {
        *row = 1;
        *col = num;
        return;
    }

    int try_begin = 0;
    for (int i = 0, len_tmp = 0; i < num; i++) {
        len_tmp += (len[i] + 2);
        if (len_tmp >= size.ws_col) {
            try_begin = i;
            break;
        }
    }

    for (int i = try_begin - 1; ; i--) {
        wide = (int *)malloc(sizeof(int) * i);
        int try_sum = 0;
        *row = (int)ceil(num / i);
        for (int x = 0; x < i; x++) {
            for (int y = x * *row; y < (x + 1) * *row && y < num; y++) {
                if (wide[x] < len[y]) wide[x] = len[y];
            }
            try_sum += (wide[x] + 2);
        }

        if (try_sum > size.ws_col) {
            continue;
        } else {
            *col = i;
            break;
        } 
    }
}

void show_files(char filename[][MAXNAME], int cnt, int row, int col) {
    if (row == 1) {
        for (int i = 0; i < cnt; i++) {
            struct stat tmp_st;
            lstat(filename[i], &tmp_st);
            update_color(tmp_st.st_mode);
            printf("\033[%d;%dm%s\033[0m  ", bg_c, fg_c, filename[i]);
        }
        printf("\n");
        return;
    }
    if (col == 1) {
        for (int i = 0; i < cnt; i++) {
            struct stat tmp_st;
            lstat(filename[i], &tmp_st);
            update_color(tmp_st.st_mode);
            printf("\033[%d;%dm%s\033[0m\n", bg_c, fg_c, filename[i]);
        }
        return;
    }
    for (int i = 0; i < row; i++) {
        for (int j = i; j < i + (row * col) && j < cnt; j += row) {
            int tmp = j / row;
            struct stat tmp_st;
            lstat(filename[j], &tmp_st);
            update_color(tmp_st.st_mode);
            printf("\033[%d;%dm%-*s\033[0m", bg_c, fg_c, wide[tmp] + 2, filename[j]);
        }
        printf("\n");
    }
}

void do_stat(const char *filename) {
    struct stat st;
    if ((lstat(filename, &st)) < 0) {
        perror("lstat");
        exit(1);
    }
    show_info(filename, &st);
}

char *uid_to_name(uid_t uid) {
    struct passwd *pw_pr;
    static char tmpname[20] = {0};
    if ((pw_pr = getpwuid(uid)) == NULL) {
        sprintf(tmpname, "%d", uid);
        return tmpname;
    } else {
        return pw_pr->pw_name;
    }
}

char *gid_to_name(gid_t gid) {
    struct group *gr_pr;
    static char tmpname[20] = {0};
    if ((gr_pr = getgrgid(gid)) == NULL) {
        sprintf(tmpname, "%d", gid);
        return tmpname;
    } else {
        return gr_pr->gr_name;
    }
}

void show_info(const char *filename, struct stat *st) {
    char modestr[11] = "----------";
    mode_to_str(modestr, st->st_mode);
    printf("%s ", modestr);
    printf("%5ld ", st->st_nlink);
    printf("%7s ", uid_to_name(st->st_uid));
    printf("%7s ", gid_to_name(st->st_gid));
    printf("%9ld ", st->st_size);
    printf("%.15s ", 4 + ctime(&st->st_mtime));
    update_color(st->st_mode);
    printf("\033[%d;%dm%s\033[0m\n", bg_c, fg_c, filename);
}

void mode_to_str(char *modestr, mode_t mode) {
    if (S_ISREG(mode)) modestr[0] = '-';
    if (S_ISDIR(mode)) modestr[0] = 'd';
    if (S_ISCHR(mode)) modestr[0] = 'c';
    if (S_ISBLK(mode)) modestr[0] = 'b';
    if (S_ISSOCK(mode)) modestr[0] = 's';
    if (S_ISFIFO(mode)) modestr[0] = 'p';
    if (S_ISLNK(mode)) modestr[0] = 'l';

    if (mode & S_IRUSR) modestr[1] = 'r';
    if (mode & S_IWUSR) modestr[2] = 'w';
    if (mode & S_IXUSR) modestr[3] = 'x';
    
    if (mode & S_IRGRP) modestr[4] = 'r';
    if (mode & S_IWGRP) modestr[5] = 'w';
    if (mode & S_IXGRP) modestr[6] = 'x';
    
    if (mode & S_IROTH) modestr[7] = 'r';
    if (mode & S_IWOTH) modestr[8] = 'w';
    if (mode & S_IXOTH) modestr[9] = 'x';
}

void update_color(mode_t mode) {
    bg_c = 40;
    fg_c = 37;
    if (mode & (S_IXUSR | S_IXGRP | S_IXOTH)) fg_c = 32;
    switch (mode & S_IFMT) {
        case S_IFDIR:
            fg_c = 34;
            break;
        case S_IFCHR:
            fg_c = 33;
            break;
        case S_IFBLK:
            fg_c = 33;
            break;
        case S_IFSOCK:
            fg_c = 33;
            break;
        case S_IFIFO:
            fg_c = 33;
            break;
        case S_IFLNK:
            fg_c = 33;
            break;
        case S_IFREG:
            fg_c = 33;
            break;
    }
}
