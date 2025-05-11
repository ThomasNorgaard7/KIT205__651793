#include <stdio.h>
#include <stdlib.h>
#include "graph_10.h"

void add_edge(Graph* self, int from, int to, int w) {
    EdgeNodePtr new_node = malloc(sizeof(struct edgeNode));
    new_node->edge.to_vertex = to;
    new_node->edge.weight = w;
    new_node->next = self->edges[from].head;
    self->edges[from].head = new_node;
}

void calculate_pagerank(Graph* g, int iterations, double damping) {
    int V = g->V;
    double* rank = malloc(V * sizeof(double));
    double* new_rank = malloc(V * sizeof(double));
    int* out_degrees = calloc(V, sizeof(int));

    for (int i = 0; i < V; i++) {
        rank[i] = 1.0;
        EdgeNodePtr curr = g->edges[i].head;
        while (curr) {
            out_degrees[i]++;
            curr = curr->next;
        }
    }

    for (int it = 0; it < iterations; it++) {
        for (int i = 0; i < V; i++) {
            new_rank[i] = 0.0;
        }

        for (int i = 0; i < V; i++) {
            EdgeNodePtr curr = g->edges[i].head;
            while (curr) {
                int to = curr->edge.to_vertex;
                if (out_degrees[i] > 0) {
                    new_rank[to] += rank[i] / out_degrees[i];
                }
                curr = curr->next;
            }
        }

        for (int i = 0; i < V; i++) {
            rank[i] = (1.0 - damping) + damping * new_rank[i];
        }
    }

    printf("\nPageRank Results:\n");
    for (int i = 0; i < V; i++) {
        printf("Vertex %d: %.6f\n", i, rank[i]);
    }

    free(rank);
    free(new_rank);
    free(out_degrees);
}

void free_graph(Graph* g) {
    for (int v = 0; v < g->V; v++) {
        EdgeNodePtr curr = g->edges[v].head;
        while (curr) {
            EdgeNodePtr tmp = curr;
            curr = curr->next;
            free(tmp);
        }
    }
    free(g->edges);
}
