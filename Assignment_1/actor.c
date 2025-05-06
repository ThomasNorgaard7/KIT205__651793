#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "actor.h"

Actor* create_actor(const char* name) {
    Actor* new_actor = (Actor*)malloc(sizeof(Actor));
    new_actor->name = _strdup(name);
    new_actor->next = NULL;
    return new_actor;
}

void add_actor(ActorList* list, const char* name) {
    Actor* new_actor = create_actor(name);

    Actor** current = &(list->head);
    while (*current != NULL && strcmp((*current)->name, name) < 0) {
        current = &((*current)->next);
    }

    new_actor->next = *current;
    *current = new_actor;
}

void print_actors(const ActorList* list) {
    Actor* current = list->head;
    while (current != NULL) {
        printf("  Actor: %s\n", current->name);
        current = current->next;
    }
}

void free_actors(ActorList* list) {
    Actor* current = list->head;
    while (current != NULL) {
        Actor* temp = current;
        current = current->next;
        free(temp->name);
        free(temp);
    }
}
