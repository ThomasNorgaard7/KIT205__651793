#ifndef MOVIE_H
#define MOVIE_H

#include "actor.h"

typedef struct {
    char* title;
    ActorList* actors;
} Movie;

// Function declarations
Movie* create_movie(const char* title);
void add_actor_to_movie(Movie* movie, const char* actor_name);
void print_movie(const Movie* movie);
void free_movie(Movie* movie);

#endif
