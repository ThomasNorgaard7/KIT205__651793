// Author: Thomas Norgaard
// AI was used in the making of this code

// Author: Thomas Norgaard
// AI was used in the making of this code

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "actor.h"

Actor* create_actor(const char* name) {
// Allocate memory
    Actor* new_actor = (Actor*)malloc(sizeof(Actor));
    new_actor->name = _strdup(name);
    new_actor->next = NULL;
// Return value
    return new_actor;
// End block
}

void add_actor(ActorList* list, const char* name) {
    Actor* new_actor = create_actor(name);

    Actor** current = &(list->head);
// Begin while block
    while (*current != NULL && strcmp((*current)->name, name) < 0) {
        current = &((*current)->next);
// End block
    }

    new_actor->next = *current;
    *current = new_actor;
// End block
}

void print_actors(const ActorList* list) {
    Actor* current = list->head;
// Begin while block
    while (current != NULL) {
        printf("  Actor: %s\n", current->name);
        current = current->next;
// End block
    }
// End block
}

void free_actors(ActorList* list) {
    Actor* current = list->head;
// Begin while block
    while (current != NULL) {
        Actor* temp = current;
        current = current->next;
// Free allocated memory
        free(temp->name);
// Free allocated memory
        free(temp);
// End block
    }
// End block
}
