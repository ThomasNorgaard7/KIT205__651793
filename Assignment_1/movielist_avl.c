#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movielist_avl.h"

MovieListAVL* create_movie_list_avl() {
    MovieListAVL* list = (MovieListAVL*)malloc(sizeof(MovieListAVL));
    list->head = NULL;
    return list;
}

void insert_movie_sorted_avl(MovieListAVL* list, const char* title) {
    MovieNodeAVL* new_node = (MovieNodeAVL*)malloc(sizeof(MovieNodeAVL));
    new_node->movie = create_movie_avl(title);
    new_node->next = NULL;

    if (!list->head || strcmp(title, list->head->movie->title) < 0) {
        new_node->next = list->head;
        list->head = new_node;
        return;
    }

    MovieNodeAVL* current = list->head;
    while (current->next && strcmp(title, current->next->movie->title) > 0) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
}

MovieAVL* find_movie_avl(MovieListAVL* list, const char* title) {
    MovieNodeAVL* current = list->head;
    while (current) {
        if (strcmp(current->movie->title, title) == 0)
            return current->movie;
        current = current->next;
    }
    return NULL;
}

void print_movies_avl(const MovieListAVL* list) {
    MovieNodeAVL* current = list->head;
    while (current) {
        printf("Movie: %s\n", current->movie->title);
        current = current->next;
    }
}

void print_actors_for_movie_avl(MovieListAVL* list, const char* title) {
    MovieAVL* movie = find_movie_avl(list, title);
    if (movie) {
        print_movie_avl(movie);
    }
    else {
        printf("Movie \"%s\" not found.\n", title);
    }
}

void free_movie_list_avl(MovieListAVL* list) {
    MovieNodeAVL* current = list->head;
    while (current) {
        MovieNodeAVL* temp = current;
        current = current->next;
        free_movie_avl(temp->movie);
        free(temp);
    }
    free(list);
}
