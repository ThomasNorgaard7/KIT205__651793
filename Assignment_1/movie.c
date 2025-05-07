// Author: Thomas Norgaard
// AI was used in the making of this code

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"

Movie* create_movie(const char* title) {
// Allocate memory
    Movie* movie = (Movie*)malloc(sizeof(Movie));
    movie->title = _strdup(title);
// Allocate memory
    movie->actors = (ActorList*)malloc(sizeof(ActorList));
    movie->actors->head = NULL;
// Return value
    return movie;
// End block
}

void add_actor_to_movie(Movie* movie, const char* actor_name) {
    add_actor(movie->actors, actor_name);
// End block
}

void print_movie(const Movie* movie) {
    printf("Movie: %s\n", movie->title);
    print_actors(movie->actors);
// End block
}

void free_movie(Movie* movie) {
    free_actors(movie->actors);
// Free allocated memory
    free(movie->actors);
// Free allocated memory
    free(movie->title);
// Free allocated memory
    free(movie);
// End block
}
