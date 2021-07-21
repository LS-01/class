/*************************************************************************
	> File Name: reactor.h
	> Author: ls
	> Mail: 
	> Created Time: Wed 21 Jul 2021 11:25:32 AM CST
 ************************************************************************/

#ifndef _REACTOR_H
#define _REACTOR_H
struct logRequest {
    char name[20];
    int sex;//1 boy 0 girl
};

struct logResponse {
    int flag;//1 ok 0 wrong
    char msg[512];
};

struct User {
    int fd;
    char name[20];
    char ip[20];
    int online;
    int epollfd;
};
#endif
