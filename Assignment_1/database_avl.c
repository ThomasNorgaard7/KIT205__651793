// Author: Thomas Norgaard
// AI was used in the making of this code

#include "database_avl.h"

MovieListAVL* create_database_avl() {
// Return value
    return create_movie_list_avl();
// End block
}

void insert_movie_record_avl(MovieListAVL* db, const char* title) {
    insert_movie_sorted_avl(db, title);
// End block
}

void insert_actor_record_avl(MovieListAVL* db, const char* movie_title, const char* actor_name) {
    MovieAVL* movie = find_movie_avl(db, movie_title);
// Begin if block
    if (movie) {
        add_actor_to_movie_avl(movie, actor_name);
// End block
    }
// End block
}

void print_all_movies_avl(const MovieListAVL* db) {
    print_movies_avl(db);
// End block
}

void print_actors_in_movie_avl(MovieListAVL* db, const char* movie_title) {
    print_actors_for_movie_avl(db, movie_title);
// End block
}

void free_database_avl(MovieListAVL* db) {
    free_movie_list_avl(db);
// End block
}
