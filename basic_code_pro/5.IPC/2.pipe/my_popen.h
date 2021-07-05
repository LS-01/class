/*************************************************************************
	> File Name: my_popen.h
	> Author: ls
	> Mail: 
	> Created Time: Fri 02 Jul 2021 09:18:30 AM CST
 ************************************************************************/

#ifndef _MY_POPEN_H
#define _MY_POPEN_H
FILE *my_popen(const char *cmd, const char *type);
int my_pclose(FILE *fp);
#endif
