/*************************************************************************
	> File Name: 2.shm_1.c
	> Author: ls
	> Mail: 
	> Created Time: Tue 22 Jun 2021 11:13:08 PM CST
 ************************************************************************/
 //Usage : ./a.out -t 1|2 -m msg
#include "common/head.h"

struct SHM {
    int flag;
    int type;
    char msg[512];
};

int main(int argc, char **argv) {
    int opt;
    struct SHM shm_data;
    memset(&shm_data, 0, sizeof(shm_data));
    if (argc != 5) {
        fprintf(stderr, "Usage : %s -t 1|2 -m msg.\n", argv[0]);
        exit(1);
    }
    while ((opt = getopt(argc, argv, "t:m:")) != -1) {
        switch (opt) {
            case 't':
                shm_data.type = atoi(optarg);
                break;
            case 'm':
                strcpy(shm_data.msg, optarg);
                break;
            default:
                fprintf(stderr, "Usage : %s -t 1|2 -m msg.\n", argv[0]);
                exit(1);
        }
    }

    key_t key;
    int shmid;
    struct SHM *share_memory = NULL;
    key = ftok("./2.shm_1.c", 328);
    if ((shmid = shmget(key, sizeof(struct SHM), IPC_CREAT | IPC_EXCL | 0600)) < 0) {
        if (errno == EEXIST) {
            printf("shm exist!\n");
            if ((shmid = shmget(key, sizeof(struct SHM), 0600)) < 0) {
                perror("shmget");
                exit(1);
            }
        } else {
            perror("shmget");
            exit(1);
        }
    } else {
        printf("Success!\n");
    }
    if ((share_memory = (struct SHM *)shmat(shmid, NULL, 0)) < 0) {
        perror("shmat");
        exit(1);
    }
    printf("addr of share_memory %p \n", share_memory);
    while (1) {
        if (!share_memory->flag) {
            printf("<%d> : get shm data\n", shm_data.type);
            share_memory->flag = 1;
            sprintf(share_memory->msg, "<%d> : %s", shm_data.type, shm_data.msg);
            sleep(1);
        } else {
            printf("%s\n", share_memory->msg);
            share_memory->flag = 0;
        }
    }
    return 0;
}
