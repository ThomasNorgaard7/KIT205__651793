#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avltree.h"

static int max_int(int a, int b) {
    return (a > b) ? a : b;
}

static int height(AVLNode* n) {
    return n ? n->height : 0;
}

static AVLNode* create_node(const char* name) {
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
    node->name = _strdup(name);
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

static int get_balance(AVLNode* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

static AVLNode* rotate_right(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max_int(height(y->left), height(y->right)) + 1;
    x->height = max_int(height(x->left), height(x->right)) + 1;
    return x;
}

static AVLNode* rotate_left(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max_int(height(x->left), height(x->right)) + 1;
    y->height = max_int(height(y->left), height(y->right)) + 1;
    return y;
}

AVLNode* insert_avl(AVLNode* node, const char* name) {
    if (!node) return create_node(name);
    int cmp = strcmp(name, node->name);
    if (cmp < 0)
        node->left = insert_avl(node->left, name);
    else if (cmp > 0)
        node->right = insert_avl(node->right, name);
    else
        return node; // no duplicates

    node->height = 1 + max_int(height(node->left), height(node->right));

    int balance = get_balance(node);

    if (balance > 1 && strcmp(name, node->left->name) < 0)
        return rotate_right(node);
    if (balance < -1 && strcmp(name, node->right->name) > 0)
        return rotate_left(node);
    if (balance > 1 && strcmp(name, node->left->name) > 0) {
        node->left = rotate_left(node->left);
        return rotate_right(node);
    }
    if (balance < -1 && strcmp(name, node->right->name) < 0) {
        node->right = rotate_right(node->right);
        return rotate_left(node);
    }
    return node;
}

void print_avl_inorder(const AVLNode* root) {
    if (root) {
        print_avl_inorder(root->left);
        printf("  Actor: %s\n", root->name);
        print_avl_inorder(root->right);
    }
}

void free_avl(AVLNode* root) {
    if (root) {
        free_avl(root->left);
        free_avl(root->right);
        free(root->name);
        free(root);
    }
}
