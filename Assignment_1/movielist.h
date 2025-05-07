// Author: Thomas Norgaard
// AI was used in the making of this code

#ifndef MOVIELIST_H
#define MOVIELIST_H

#include "movie.h"

typedef struct movienode {
    Movie* movie;
    struct movienode* next;
} MovieNode;

typedef struct {
    MovieNode* head;
} MovieList;

// Functions
MovieList* create_movie_list();
void insert_movie_sorted(MovieList* list, const char* title);
Movie* find_movie(MovieList* list, const char* title);
void print_movies(const MovieList* list);
void print_actors_for_movie(MovieList* list, const char* title);
void free_movie_list(MovieList* list);

#endif
