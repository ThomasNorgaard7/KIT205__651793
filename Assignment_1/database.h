// Author: Thomas Norgaard
// AI was used in the making of this code

#ifndef DATABASE_H
#define DATABASE_H

#include "movielist.h"

MovieList* create_database();
void insert_movie_record(MovieList* db, const char* title);
void insert_actor_record(MovieList* db, const char* movie_title, const char* actor_name);
void print_all_movies(const MovieList* db);
void print_actors_in_movie(MovieList* db, const char* movie_title);
void free_database(MovieList* db);

#endif
