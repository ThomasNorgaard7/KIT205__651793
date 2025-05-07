#ifndef MOVIELIST_AVL_H
#define MOVIELIST_AVL_H

#include "movie_avl.h"

typedef struct MovieNodeAVL {
    MovieAVL* movie;
    struct MovieNodeAVL* next;
} MovieNodeAVL;

typedef struct {
    MovieNodeAVL* head;
} MovieListAVL;

MovieListAVL* create_movie_list_avl();
void insert_movie_sorted_avl(MovieListAVL* list, const char* title);
MovieAVL* find_movie_avl(MovieListAVL* list, const char* title);
void print_movies_avl(const MovieListAVL* list);
void print_actors_for_movie_avl(MovieListAVL* list, const char* title);
void free_movie_list_avl(MovieListAVL* list);

#endif
