#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movielist.h"

MovieList* create_movie_list() {
    MovieList* list = (MovieList*)malloc(sizeof(MovieList));
    list->head = NULL;
    return list;
}

void insert_movie_sorted(MovieList* list, const char* title) {
    MovieNode* new_node = (MovieNode*)malloc(sizeof(MovieNode));
    new_node->movie = create_movie(title);
    new_node->next = NULL;

    MovieNode** current = &(list->head);
    while (*current != NULL && strcmp((*current)->movie->title, title) < 0) {
        current = &((*current)->next);
    }
    new_node->next = *current;
    *current = new_node;
}

Movie* find_movie(MovieList* list, const char* title) {
    MovieNode* current = list->head;
    while (current != NULL) {
        if (strcmp(current->movie->title, title) == 0)
            return current->movie;
        current = current->next;
    }
    return NULL;
}

void print_movies(const MovieList* list) {
    MovieNode* current = list->head;
    while (current != NULL) {
        printf("Movie: %s\n", current->movie->title);
        current = current->next;
    }
}

void print_actors_for_movie(MovieList* list, const char* title) {
    Movie* movie = find_movie(list, title);
    if (movie) {
        printf("Actors in \"%s\":\n", title);
        print_actors(movie->actors);
    }
    else {
        printf("Movie \"%s\" not found.\n", title);
    }
}

void free_movie_list(MovieList* list) {
    MovieNode* current = list->head;
    while (current != NULL) {
        MovieNode* temp = current;
        current = current->next;
        free_movie(temp->movie);
        free(temp);
    }
    free(list);
}
