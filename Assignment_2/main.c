// ================================
// main.c
// ================================
#include <stdio.h>
#include "graph.h"
#include "dijkstra.h"

// GenAI Acknowledgment:
// This main driver was structured with ChatGPT to initialize a test terrain map, create a graph, and verify graph construction.

int main() {
    char* test_map[] = {
        "SPPPPF",
        "PWWWWP",
        "PFFPWP",
        "PWPWGP"
    };

    int rows = 4;
    int cols = 6;

    Graph* graph = create_graph_from_map(test_map, rows, cols);

    printf("Graph terrain cost map:\n");
    print_graph_costs(graph);

    PathStep* path = NULL;
    int length = 0;

    dijkstra(graph, 0, 0, 3, 5, &path, &length);

    printf("\nShortest path from S to G:\n");
    for (int i = 0; i < length; i++) {
        printf("(%d, %d) ", path[i].row, path[i].col);
    }
    printf("\n");

    free(path);
    free_graph(graph);
    return 0;
}
