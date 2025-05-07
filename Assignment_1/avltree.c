// Author: Thomas Norgaard
// AI was used in the making of this code

// Author: Thomas Norgaard
// AI was used in the making of this code

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avltree.h"

static int max_int(int a, int b) {
// Return value
    return (a > b) ? a : b;
// End block
}

static int height(AVLNode* n) {
// Return value
    return n ? n->height : 0;
// End block
}

static AVLNode* create_node(const char* name) {
// Allocate memory
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
    node->name = _strdup(name);
    node->left = node->right = NULL;
    node->height = 1;
// Return value
    return node;
// End block
}

static int get_balance(AVLNode* n) {
// Return value
    return n ? height(n->left) - height(n->right) : 0;
// End block
}

static AVLNode* rotate_right(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max_int(height(y->left), height(y->right)) + 1;
    x->height = max_int(height(x->left), height(x->right)) + 1;
// Return value
    return x;
// End block
}

static AVLNode* rotate_left(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max_int(height(x->left), height(x->right)) + 1;
    y->height = max_int(height(y->left), height(y->right)) + 1;
// Return value
    return y;
// End block
}

AVLNode* insert_avl(AVLNode* node, const char* name) {
    if (!node) return create_node(name);
    int cmp = strcmp(name, node->name);
    if (cmp < 0)
        node->left = insert_avl(node->left, name);
    else if (cmp > 0)
        node->right = insert_avl(node->right, name);
    else
// Return value
        return node; // no duplicates

    node->height = 1 + max_int(height(node->left), height(node->right));

    int balance = get_balance(node);

    if (balance > 1 && strcmp(name, node->left->name) < 0)
// Return value
        return rotate_right(node);
    if (balance < -1 && strcmp(name, node->right->name) > 0)
// Return value
        return rotate_left(node);
// Begin if block
    if (balance > 1 && strcmp(name, node->left->name) > 0) {
        node->left = rotate_left(node->left);
// Return value
        return rotate_right(node);
// End block
    }
// Begin if block
    if (balance < -1 && strcmp(name, node->right->name) < 0) {
        node->right = rotate_right(node->right);
// Return value
        return rotate_left(node);
// End block
    }
// Return value
    return node;
// End block
}

void print_avl_inorder(const AVLNode* root) {
// Begin if block
    if (root) {
        print_avl_inorder(root->left);
        printf("  Actor: %s\n", root->name);
        print_avl_inorder(root->right);
// End block
    }
// End block
}

void free_avl(AVLNode* root) {
// Begin if block
    if (root) {
        free_avl(root->left);
        free_avl(root->right);
// Free allocated memory
        free(root->name);
// Free allocated memory
        free(root);
// End block
    }
// End block
}
