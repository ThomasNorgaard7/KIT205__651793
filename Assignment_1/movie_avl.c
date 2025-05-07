// Author: Thomas Norgaard
// AI was used in the making of this code

// Author: Thomas Norgaard
// AI was used in the making of this code

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie_avl.h"

MovieAVL* create_movie_avl(const char* title) {
// Allocate memory
    MovieAVL* movie = (MovieAVL*)malloc(sizeof(MovieAVL));
    movie->title = _strdup(title);
    movie->actors = NULL;
// Return value
    return movie;
// End block
}

void add_actor_to_movie_avl(MovieAVL* movie, const char* actor_name) {
    movie->actors = insert_avl(movie->actors, actor_name);
// End block
}

void print_movie_avl(const MovieAVL* movie) {
    printf("Movie: %s\n", movie->title);
    print_avl_inorder(movie->actors);
// End block
}

void free_movie_avl(MovieAVL* movie) {
    free_avl(movie->actors);
// Free allocated memory
    free(movie->title);
// Free allocated memory
    free(movie);
// End block
}
