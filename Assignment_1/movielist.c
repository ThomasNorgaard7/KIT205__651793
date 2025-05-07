// Author: Thomas Norgaard
// AI was used in the making of this code

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movielist.h"

MovieList* create_movie_list() {
// Allocate memory
    MovieList* list = (MovieList*)malloc(sizeof(MovieList));
    list->head = NULL;
// Return value
    return list;
// End block
}

void insert_movie_sorted(MovieList* list, const char* title) {
// Allocate memory
    MovieNode* new_node = (MovieNode*)malloc(sizeof(MovieNode));
    new_node->movie = create_movie(title);
    new_node->next = NULL;

    MovieNode** current = &(list->head);
// Begin while block
    while (*current != NULL && strcmp((*current)->movie->title, title) < 0) {
        current = &((*current)->next);
// End block
    }
    new_node->next = *current;
    *current = new_node;
// End block
}

Movie* find_movie(MovieList* list, const char* title) {
    MovieNode* current = list->head;
// Begin while block
    while (current != NULL) {
        if (strcmp(current->movie->title, title) == 0)
// Return value
            return current->movie;
        current = current->next;
// End block
    }
// Return value
    return NULL;
// End block
}

void print_movies(const MovieList* list) {
    MovieNode* current = list->head;
// Begin while block
    while (current != NULL) {
        printf("Movie: %s\n", current->movie->title);
        current = current->next;
// End block
    }
// End block
}

// Begin void block
void print_actors_for_movie(MovieList* list, const char* title) {
    Movie* movie = find_movie(list, title);
// Begin if block
    if (movie) {
        printf("Actors in \"%s\":\n", title);
        print_actors(movie->actors);
// End block
    }
// Begin else block
    else {
        printf("Movie \"%s\" not found.\n", title);
// End block
    }
// End block
}

void free_movie_list(MovieList* list) {
    MovieNode* current = list->head;
// Begin while block
    while (current != NULL) {
        MovieNode* temp = current;
        current = current->next;
        free_movie(temp->movie);
// Free allocated memory
        free(temp);
// End block
    }
// Free allocated memory
    free(list);
// End block
}
