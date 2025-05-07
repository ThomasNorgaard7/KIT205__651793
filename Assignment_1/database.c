// Author: Thomas Norgaard
// AI was used in the making of this code

// Author: Thomas Norgaard
// AI was used in the making of this code

#include "database.h"

MovieList* create_database() {
// Return value
    return create_movie_list();
// End block
}

void insert_movie_record(MovieList* db, const char* title) {
    insert_movie_sorted(db, title);
// End block
}

void insert_actor_record(MovieList* db, const char* movie_title, const char* actor_name) {
    Movie* movie = find_movie(db, movie_title);
// Begin if block
    if (movie) {
        add_actor_to_movie(movie, actor_name);
// End block
    }
// End block
}

void print_all_movies(const MovieList* db) {
    print_movies(db);
// End block
}

void print_actors_in_movie(MovieList* db, const char* movie_title) {
    print_actors_for_movie(db, movie_title);
// End block
}

void free_database(MovieList* db) {
    free_movie_list(db);
// End block
}
