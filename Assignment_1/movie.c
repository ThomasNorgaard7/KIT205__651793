#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"

Movie* create_movie(const char* title) {
    Movie* movie = (Movie*)malloc(sizeof(Movie));
    movie->title = _strdup(title);
    movie->actors = (ActorList*)malloc(sizeof(ActorList));
    movie->actors->head = NULL;
    return movie;
}

void add_actor_to_movie(Movie* movie, const char* actor_name) {
    add_actor(movie->actors, actor_name);
}

void print_movie(const Movie* movie) {
    printf("Movie: %s\n", movie->title);
    print_actors(movie->actors);
}

void free_movie(Movie* movie) {
    free_actors(movie->actors);
    free(movie->actors);
    free(movie->title);
    free(movie);
}
