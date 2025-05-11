#include <stdio.h>
#include <stdlib.h>
#include "graph_9.h"

void add_edge(Graph* self, int from, int to, int w) {
    EdgeNodePtr new_node = malloc(sizeof(struct edgeNode));
    new_node->edge.to_vertex = to;
    new_node->edge.weight = w;
    new_node->next = self->edges[from].head;
    self->edges[from].head = new_node;
}

int main() {
    //FILE* file = fopen("graph_9.txt", "r");
    FILE* file = fopen("SN_graph_9.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    Graph G;
    fscanf_s(file, "%d", &G.V);

    G.edges = malloc(G.V * sizeof(EdgeList));
    for (int v = 0; v < G.V; v++) {
        G.edges[v].head = NULL;
    }

    int from, to, weight;
    //while (fscanf_s(file, "%d,%d,%d", &from, &to, &weight) == 3) {
    while (fscanf_s(file, "%d,%d", &from, &to) == 2) {
        //add_edge(&G, from, to, weight);
        add_edge(&G, from, to, 0);  // use 0 as weight
    }

    fclose(file);

    // In-degree calculation
    int* in_degrees = calloc(G.V, sizeof(int));

    for (int v = 0; v < G.V; v++) {
        EdgeNodePtr current = G.edges[v].head;
        while (current != NULL) {
            in_degrees[current->edge.to_vertex]++;
            current = current->next;
        }
    }

    printf("In-degrees:\n");
    for (int i = 0; i < G.V; i++) {
        printf("Vertex %d: %d\n", i, in_degrees[i]);
    }

    // Free memory
    for (int v = 0; v < G.V; v++) {
        EdgeNodePtr current = G.edges[v].head;
        while (current != NULL) {
            EdgeNodePtr temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(G.edges);
    free(in_degrees);

    return 0;
}
