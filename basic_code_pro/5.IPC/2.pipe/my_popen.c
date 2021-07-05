/*************************************************************************
	> File Name: my_popen.c
	> Author: ls
	> Mail: 
	> Created Time: Fri 02 Jul 2021 09:20:02 AM CST
 ************************************************************************/

#include "common/head.h"

static pid_t *childpid = NULL;
static int maxsize = 0;

FILE *my_popen(const char *cmd, const char *type) {
    //pipe() fork() execl()
    FILE *fp;
    int pipefd[2];
    pid_t pid;
    
    if ((type[0] != 'r' && type[0] != 'w') || type[1] != '\0') {
        errno = EINVAL;
        return NULL;
    }

    if (childpid == NULL) {
        maxsize = sysconf(_SC_OPEN_MAX);
        if ((childpid = (pid_t *)calloc(maxsize, sizeof(pid_t))) == NULL) {
            return NULL;
        }
    }

    if (pipe(pipefd) < 0) {
        return NULL;
    }

    if ((pid = fork()) < 0) {
        return NULL;
    }
    if (pid == 0) {
        if (type[0] == 'r') {
            close(pipefd[0]);
            if (pipefd[1] != STDOUT_FILENO) {
                dup2(pipefd[1], STDOUT_FILENO);
                close(pipefd[1]);
            }
        } else {
            close(pipefd[1]);
            if (pipefd[0] != STDIN_FILENO) {
                dup2(pipefd[0], STDIN_FILENO);
                close(pipefd[0]);
            }
        }
        execl("/bin/sh", "sh", "-c", cmd, NULL);
    }

    if (type[0] == 'r') {
        close(pipefd[1]);
        if ((fp = fdopen(pipefd[0], type)) == NULL) {
            return NULL;
        }
    } else {
        close(pipefd[0]);
        if ((fp = fdopen(pipefd[1], type)) == NULL) {
            return NULL;
        }
    }
    childpid[fileno(fp)] = pid;
    return fp;
}

int my_pclose(FILE *fp) {
    //wait() fclose(fp)
    int status, pid, fd;
    fd = fileno(fp);
    pid = childpid[fd];
    if (pid == 0) {
        errno = EINVAL;
        return -1;
    }
    fflush(fp);
    close(fd);
    wait4(pid, &status, 0, NULL);
    return status;
}
