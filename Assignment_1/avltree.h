#ifndef AVLTREE_H
#define AVLTREE_H

typedef struct AVLNode {
    char* name;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
} AVLNode;

AVLNode* insert_avl(AVLNode* root, const char* name);
void print_avl_inorder(const AVLNode* root);
void free_avl(AVLNode* root);

#endif
