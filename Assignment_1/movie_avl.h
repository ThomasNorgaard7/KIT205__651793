#ifndef MOVIE_AVL_H
#define MOVIE_AVL_H

#include "avltree.h"

typedef struct {
    char* title;
    AVLNode* actors;  // AVL tree instead of linked list
} MovieAVL;

MovieAVL* create_movie_avl(const char* title);
void add_actor_to_movie_avl(MovieAVL* movie, const char* actor_name);
void print_movie_avl(const MovieAVL* movie);
void free_movie_avl(MovieAVL* movie);

#endif
