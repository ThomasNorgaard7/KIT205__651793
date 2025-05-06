#ifndef DATABASE_H
#define DATABASE_H

#include "movie.h"

// For future expansion – right now this just centralizes movie functions
Movie* insert_movie(const char* title);
void add_actor_to_movie(Movie* movie, const char* actor_name);
void print_movie(const Movie* movie);
void free_movie(Movie* movie);

#endif
