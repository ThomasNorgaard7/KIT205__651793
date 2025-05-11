#include <stdio.h>
#include <stdlib.h>
#include "graph_10.h"

int main() {
    FILE* file;
    //fopen_s(&file, "graph_10.txt", "r");
    fopen_s(&file, "SN_graph_10.txt", "r");
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

    int from, to;
    while (fscanf_s(file, "%d,%d", &from, &to) == 2) {
        add_edge(&G, from, to, 0); // weight is unused
    }

    fclose(file);

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

    calculate_pagerank(&G, 20, 0.85); // 20 iterations, damping factor 0.85

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
