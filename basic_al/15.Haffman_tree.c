/*************************************************************************
	> File Name: 15.Haffman_tree.c
	> Author: ls
	> Mail: 
	> Created Time: Sun 06 Dec 2020 05:45:30 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_n 1000

#define swap(a, b) {\
    __typeof(a) _tmp = a;\
    a = b; b = _tmp;\
}

typedef struct Node {
    char ch;
    double p;
    struct Node *next[2];
} Node;

typedef struct Data {
    char ch;
    double p;
} Data;

typedef struct Code {
    char ch;
    char *str;
} Code;

typedef struct Haffman_Tree {
    Node *root;
    int n;
    Code *codes;
} Haffman_Tree;

Data arr[max_n + 5];

Node *getNewNode(Data *obj) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->ch = (obj ? obj->ch : 0);
    p->p = (obj ? obj->p : 0);
    p->next[0] = p->next[1] = NULL;
    return p;
}

Haffman_Tree *getNewTree(int n) {
    Haffman_Tree *tree = (Haffman_Tree *)malloc(sizeof(Haffman_Tree));
    tree->codes = (Code *)malloc(sizeof(Code) * n);
    tree->n = n;
    tree->root = NULL;
    return tree;
}

void insertOnce(Node **arr, int n) {
    for (int j = n; j >= 1; j--) {
        if (arr[j]->p > arr[j - 1]->p) {
            swap(arr[j], arr[j - 1]);
            continue;
        }
        break;
    }
}

int extract_codes(Node *root, Code *arr, int k, int l, char *buff) {
    buff[l] = 0;
    if (root->next[0] == NULL && root->next[1] == NULL) {
        arr[k].ch = root->ch;
        arr[k].str = strdup(buff);
        return 1;
    }
    int delta = 0;
    buff[l] = '0';
    delta += extract_codes(root->next[0], arr, k + delta, l + 1, buff);
    buff[l] = '1';
    delta += extract_codes(root->next[1], arr, k + delta, l + 1, buff);
    return delta;
}

Haffman_Tree *build(Data *arr, int n) {
    Node **nodes = (Node **)malloc(sizeof(Node *) * n);
    for (int i = 0; i < n; i++) {
        nodes[i] = getNewNode(arr + i);
    }
    for (int i = 1; i < n; i++) {
        insertOnce(nodes, i);
    }
    for (int i = n - 1; i >= 1; i--) {
        Node *p = getNewNode(NULL);
        p->next[0] = nodes[i - 1];
        p->next[1] = nodes[i];
        p->p = nodes[i - 1]->p + nodes[i]->p;
        nodes[i - 1] = p;
        insertOnce(nodes, i - 1);
    }
    char *buff = (char *)malloc(sizeof(char) * n);
    Haffman_Tree *tree = getNewTree(n);
    tree->root = nodes[0];
    extract_codes(tree->root, tree->codes, 0, 0, buff);
    free(buff);
    free(nodes);
    return tree;
}

int main() {
    int n;
    char str[10];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s%lf", str, &arr[i].p);
        arr[i].ch = str[0];
    }
    Haffman_Tree *tree = build(arr, n);
    for (int i = 0; i < tree->n; i++) {
        printf("%c : %s\n", tree->codes[i].ch, tree->codes[i].str);
    }
    return 0;
}
