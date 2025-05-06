#include <stdio.h>
#include "database.h"

int main() {
    MovieList* db = create_database();

    insert_movie_record(db, "The Matrix");
    insert_movie_record(db, "Inception");
    insert_movie_record(db, "Avengers");

    insert_actor_record(db, "The Matrix", "Keanu Reeves");
    insert_actor_record(db, "The Matrix", "Carrie-Anne Moss");
    insert_actor_record(db, "Inception", "Leonardo DiCaprio");
    insert_actor_record(db, "Inception", "Cillian Murphy");
    insert_actor_record(db, "Avengers", "Robert Downey Jr.");
    insert_actor_record(db, "Avengers", "Scarlett Johansson");

    printf("All Movies:\n");
    print_all_movies(db);

    printf("\nActors in 'The Matrix':\n");
    print_actors_in_movie(db, "The Matrix");

    printf("\nActors in 'Avengers':\n");
    print_actors_in_movie(db, "Avengers");

    free_database(db);
    return 0;
}
