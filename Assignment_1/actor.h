#ifndef ACTOR_H
#define ACTOR_H

typedef struct actor {
    char* name;
    struct actor* next;
} Actor;

typedef struct {
    Actor* head;
} ActorList;

// Function declarations
Actor* create_actor(const char* name);
void add_actor(ActorList* list, const char* name);
void print_actors(const ActorList* list);
void free_actors(ActorList* list);

#endif
