#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Toggle testing modes
#define RUN_FUNCTIONAL_TESTS 1
#define RUN_PERFORMANCE_TESTS 1
#define Movie_Num 2000
#define Actor_Num 100
#define Movie_Incr 250
#define Actor_incr 25

// Prototype 1 headers (linked list of linked lists)
#include "database.h"

// Prototype 2 headers (linked list of AVL trees)
#include "database_avl.h"

void functional_test_prototype1() {
    printf("\n=== Functional Test: Prototype 1 ===\n");

    MovieList* db = create_database();

    insert_movie_record(db, "The Matrix");
    insert_actor_record(db, "The Matrix", "Keanu Reeves");
    insert_actor_record(db, "The Matrix", "Carrie-Anne Moss");
    insert_actor_record(db, "The Matrix", "Hugo Weaving");

    insert_movie_record(db, "Inception");
    insert_actor_record(db, "Inception", "Leonardo DiCaprio");

    printf("All Movies:\n");
    print_all_movies(db);

    printf("Actors in 'The Matrix':\n");
    print_actors_in_movie(db, "The Matrix");

    printf("Actors in 'Inception':\n");
    print_actors_in_movie(db, "Inception");

    // Edge case: non-existent movie
    printf("Actors in 'Missing Movie':\n");
    print_actors_in_movie(db, "Missing Movie");

    free_database(db);
}

void functional_test_prototype2() {
    printf("\n=== Functional Test: Prototype 2 ===\n");

    MovieListAVL* db_avl = create_database_avl();

    insert_movie_record_avl(db_avl, "The Matrix");
    insert_actor_record_avl(db_avl, "The Matrix", "Keanu Reeves");
    insert_actor_record_avl(db_avl, "The Matrix", "Carrie-Anne Moss");
    insert_actor_record_avl(db_avl, "The Matrix", "Hugo Weaving");

    insert_movie_record_avl(db_avl, "Inception");
    insert_actor_record_avl(db_avl, "Inception", "Leonardo DiCaprio");

    printf("All Movies:\n");
    print_all_movies_avl(db_avl);

    printf("Actors in 'The Matrix':\n");
    print_actors_in_movie_avl(db_avl, "The Matrix");

    printf("Actors in 'Inception':\n");
    print_actors_in_movie_avl(db_avl, "Inception");

    // Edge case: movie not found
    printf("Actors in 'Missing Movie':\n");
    print_actors_in_movie_avl(db_avl, "Missing Movie");

    free_database_avl(db_avl);
}

void performance_test_prototype1(int num_movies, int num_actors_per_movie) {
    printf("\n=== Performance Test: Prototype 1 ===\n");
    clock_t start = clock();

    MovieList* db = create_database();

    char movie_title[50];
    char actor_name[50];

    for (int i = 0; i < num_movies; i++) {
        sprintf(movie_title, "Movie %d", i);
        insert_movie_record(db, movie_title);
        for (int j = 0; j < num_actors_per_movie; j++) {
            sprintf(actor_name, "Actor %d_%d", i, j);
            insert_actor_record(db, movie_title, actor_name);
        }
    }

    //print_all_movies(db); // Optionally comment out to improve performance visibility

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken (Prototype 2) (movies: %d)(actors: %d): %.2f seconds\n", num_movies, num_actors_per_movie, time_spent);

    free_database(db);
}

void performance_test_prototype2(int num_movies, int num_actors_per_movie) {
    printf("\n=== Performance Test: Prototype 2 ===\n");
    clock_t start = clock();

    MovieListAVL* db = create_database_avl();

    char movie_title[50];
    char actor_name[50];

    for (int i = 0; i < num_movies; i++) {
        sprintf(movie_title, "Movie %d", i);
        insert_movie_record_avl(db, movie_title);
        for (int j = 0; j < num_actors_per_movie; j++) {
            sprintf(actor_name, "Actor %d_%d", i, j);
            insert_actor_record_avl(db, movie_title, actor_name);
        }
    }

    //print_all_movies_avl(db); // Optionally comment out to improve performance visibility

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken (Prototype 1) (movies: %d)(actors: %d): %.2f seconds\n", num_movies, num_actors_per_movie, time_spent);

    free_database_avl(db);
}

int main() {
#if RUN_FUNCTIONAL_TESTS
    functional_test_prototype1();
    functional_test_prototype2();
#endif

#if RUN_PERFORMANCE_TESTS
    int j = Actor_Num;
    while (j > 0) {
        int i = Movie_Num;
        while (i > 0) {
            performance_test_prototype1(i, j);
            performance_test_prototype2(i, j);

            i = i - Movie_Incr;
        }

        j = j - Actor_incr;
    }


#endif

    return 0;
}
