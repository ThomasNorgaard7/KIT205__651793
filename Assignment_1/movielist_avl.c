// Author: Thomas Norgaard
// AI was used in the making of this code

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movielist_avl.h"

MovieListAVL* create_movie_list_avl() {
// Allocate memory
    MovieListAVL* list = (MovieListAVL*)malloc(sizeof(MovieListAVL));
    list->head = NULL;
// Return value
    return list;
// End block
}

void insert_movie_sorted_avl(MovieListAVL* list, const char* title) {
// Allocate memory
    MovieNodeAVL* new_node = (MovieNodeAVL*)malloc(sizeof(MovieNodeAVL));
    new_node->movie = create_movie_avl(title);
    new_node->next = NULL;

// Begin if block
    if (!list->head || strcmp(title, list->head->movie->title) < 0) {
        new_node->next = list->head;
        list->head = new_node;
        return;
// End block
    }

    MovieNodeAVL* current = list->head;
// Begin while block
    while (current->next && strcmp(title, current->next->movie->title) > 0) {
        current = current->next;
// End block
    }
    new_node->next = current->next;
    current->next = new_node;
// End block
}

MovieAVL* find_movie_avl(MovieListAVL* list, const char* title) {
    MovieNodeAVL* current = list->head;
// Begin while block
    while (current) {
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

void print_movies_avl(const MovieListAVL* list) {
    MovieNodeAVL* current = list->head;
// Begin while block
    while (current) {
        printf("Movie: %s\n", current->movie->title);
        current = current->next;
// End block
    }
// End block
}

// Begin void block
void print_actors_for_movie_avl(MovieListAVL* list, const char* title) {
    MovieAVL* movie = find_movie_avl(list, title);
// Begin if block
    if (movie) {
        print_movie_avl(movie);
// End block
    }
// Begin else block
    else {
        printf("Movie \"%s\" not found.\n", title);
// End block
    }
// End block
}

void free_movie_list_avl(MovieListAVL* list) {
    MovieNodeAVL* current = list->head;
// Begin while block
    while (current) {
        MovieNodeAVL* temp = current;
        current = current->next;
        free_movie_avl(temp->movie);
// Free allocated memory
        free(temp);
// End block
    }
// Free allocated memory
    free(list);
// End block
}
