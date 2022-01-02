/*************************************************************************
	> File Name: common.h
	> Author: 
	> Mail: 
	> Created Time: 2021年04月15日 星期四 18时51分43秒
 ************************************************************************/

#ifndef _COMMON_H
#define _COMMON_H

int make_nonblock(int fd);
int make_block(int fd);
int socket_create(int port);
int socket_connect(const char *ip, int port);
//int make_block(int fd, int op);
#ifdef _D
#define DBG(fmt, args...); printf(fmt, ##args);
#else
#define DBG(fmt, args...)
#endif
#endif
