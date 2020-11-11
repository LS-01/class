/*************************************************************************
	> File Name: 5.binary_tree.c
	> Author: ls
	> Mail: 
	> Created Time: Fri 06 Nov 2020 10:47:35 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node *lchild, *rchild;
} Node;

typedef struct Tree {
    Node *root;
    int n;
} Tree;

Node *init_node(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->lchild = p->rchild = NULL;
    return p;
}

Tree *init_tree() {
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree->root = NULL;
    tree->n = 0;
    return tree;
}

void clear_node(Node *node) {
    if (node == NULL) return;
    clear_node(node->lchild);
    clear_node(node->rchild);
    free(node);
    return;
}

void clear_tree(Tree *tree) {
    if (tree == NULL) return;
    clear_node(tree->root);
    free(tree);
    return;
}

Node *insert_node(Node *root, int val, int *flag) {
    if (root == NULL) {
        *flag = 1;
        return init_node(val);
    }
    if (root->data == val) return root;
    if (val < root->data) root->lchild = insert_node(root->lchild, val, flag);
    else root->rchild = insert_node(root->rchild, val, flag);
    return root;
}

void pre_order_node(Node *node) {
    if (node == NULL) return;
    printf("%d ", node->data);
    pre_order_node(node->lchild);
    pre_order_node(node->rchild);
    return;
}

void pre_order(Tree *tree) {
    if (tree == NULL) return;
    printf("pre_order : ");
    pre_order_node(tree->root);
    printf("\n");
    return;
}

void in_order_node(Node *node) {
    if (node == NULL) return;
    in_order_node(node->lchild);
    printf("%d ", node->data);
    in_order_node(node->rchild);
    return;
}

void in_order(Tree *tree) {
    if (tree == NULL) return;
    printf("in_order : ");
    in_order_node(tree->root);
    printf("\n");
    return;
}

void post_order_node(Node *node) {
    if (node == NULL) return;
    post_order_node(node->lchild);
    post_order_node(node->rchild);
    printf("%d ", node->data);
    return;
}

void post_order(Tree *tree) {
    if (tree == NULL) return;
    printf("post_order : ");
    post_order_node(tree->root);
    printf("\n");
    return;
}

void insert(Tree *tree, int val) {
    int flag = 0;
    tree->root = insert_node(tree->root, val, &flag);
    tree->n += flag;
    return;
}

void output_node(Node *node) {
    if (node == NULL) return;
    printf("%d", node->data);
    if (node->lchild == NULL && node->rchild == NULL) return;
    printf("(");
    output_node(node->lchild);
    printf(",");
    output_node(node->rchild);
    printf(")");
    return;
}

void output(Tree *tree) {
    if (tree == NULL) return;
    printf("tree(%d) : ", tree->n);
    output_node(tree->root);
    printf("\n");
    return;
}

int main() {
    srand(time(0));
    Tree *tree = init_tree();
    #define max_op 20 
    for (int i = 0; i < max_op; i++) {
        int val = rand() % 100;
        insert(tree, val);
        output(tree);
    }
    pre_order(tree);
    in_order(tree);
    post_order(tree);
    #undef max_op
    clear_tree(tree);
    return 0;
}
