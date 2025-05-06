#include "database.h"

MovieList* create_database() {
    return create_movie_list();
}

void insert_movie_record(MovieList* db, const char* title) {
    insert_movie_sorted(db, title);
}

void insert_actor_record(MovieList* db, const char* movie_title, const char* actor_name) {
    Movie* movie = find_movie(db, movie_title);
    if (movie) {
        add_actor_to_movie(movie, actor_name);
    }
}

void print_all_movies(const MovieList* db) {
    print_movies(db);
}

void print_actors_in_movie(MovieList* db, const char* movie_title) {
    print_actors_for_movie(db, movie_title);
}

void free_database(MovieList* db) {
    free_movie_list(db);
}
