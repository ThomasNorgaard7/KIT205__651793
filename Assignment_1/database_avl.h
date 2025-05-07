// Author: Thomas Norgaard
// AI was used in the making of this code

#ifndef DATABASE_AVL_H
#define DATABASE_AVL_H

#include "movielist_avl.h"

MovieListAVL* create_database_avl();
void insert_movie_record_avl(MovieListAVL* db, const char* title);
void insert_actor_record_avl(MovieListAVL* db, const char* movie_title, const char* actor_name);
void print_all_movies_avl(const MovieListAVL* db);
void print_actors_in_movie_avl(MovieListAVL* db, const char* movie_title);
void free_database_avl(MovieListAVL* db);

#endif
