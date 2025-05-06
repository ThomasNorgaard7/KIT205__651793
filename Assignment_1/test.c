#include <stdio.h>
#include <string.h>
#include "database.h"

int main() {
    Movie* movie = insert_movie("The Matrix");
    add_actor_to_movie(movie, "Keanu Reeves");
    add_actor_to_movie(movie, "Carrie-Anne Moss");

    print_movie(movie);

    // Check if "Keanu Reeves" is in the list
    Actor* actor = movie->actors->head;
    while (actor != NULL) {
        if (strcmp(actor->name, "Keanu Reeves") == 0) {
            printf("Found Keanu Reeves in the movie!\n");
            break;
        }
        actor = actor->next;
    }

    free_movie(movie);
    return 0;
}
