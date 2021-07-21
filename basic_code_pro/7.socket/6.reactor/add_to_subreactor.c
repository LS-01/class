/*************************************************************************
	> File Name: add_to_subreactor.c
	> Author: ls
	> Mail: 
	> Created Time: Wed 21 Jul 2021 11:26:48 AM CST
 ************************************************************************/
#include "common/head.h"
#include "add_to_subreactor.h"

void add_event_ptr(int epollfd, struct User *user) {
    struct epoll_event ev;
    ev.events = EPOLLIN | EPOLLET;
    ev.data.ptr = (void *)user;
    epoll_ctl(epollfd, EPOLL_CTL_ADD, user->fd, &ev);

}

void add_to_subreactor(struct User *user) {
    //前置已完成数据的复制与保存
    add_event_ptr(user->epollfd, user);
    printf("Add %s to subreactor\n", user->name);
}
