#include "database_avl.h"

MovieListAVL* create_database_avl() {
    return create_movie_list_avl();
}

void insert_movie_record_avl(MovieListAVL* db, const char* title) {
    insert_movie_sorted_avl(db, title);
}

void insert_actor_record_avl(MovieListAVL* db, const char* movie_title, const char* actor_name) {
    MovieAVL* movie = find_movie_avl(db, movie_title);
    if (movie) {
        add_actor_to_movie_avl(movie, actor_name);
    }
}

void print_all_movies_avl(const MovieListAVL* db) {
    print_movies_avl(db);
}

void print_actors_in_movie_avl(MovieListAVL* db, const char* movie_title) {
    print_actors_for_movie_avl(db, movie_title);
}

void free_database_avl(MovieListAVL* db) {
    free_movie_list_avl(db);
}
