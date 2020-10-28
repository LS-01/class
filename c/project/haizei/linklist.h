/*************************************************************************
	> File Name: linklist.h
	> Author: ls
	> Mail: 
	> Created Time: Wed 21 Oct 2020 06:56:07 PM CST
 ************************************************************************/

#ifndef _LINKLIST_H
#define _LINKLIST_H

#define offset(T, name) (long long)(&(((T *)(0))->name))
#define Head(p, T, name) (T *)((char *)(p) - offset(T, name))

struct LinkNode {
    struct LinkNode *next;
};

#endif
