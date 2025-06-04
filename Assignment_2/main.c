// ================================
// main.c
// ================================
#include <stdio.h>
#include <stdlib.h>  // For malloc/free
#include "graph.h"
#include "dijkstra.h"

// GenAI Acknowledgment:
// This main driver was structured with ChatGPT to initialize a test terrain map, create a graph, and verify graph construction.

int main() {
    int rows = 9;
    int cols = 9;

    char* test_map[] = {
        "SPPPPPPPP",
        "PWWWWWWWP",
        "PFFPPPPPP",
        "PWPWWWWWP",
        "PFPFFFFFP",
        "PPPWPWWWP",
        "PWWPFPWPP",
        "PPPPWPWPG",
        "PPPPPPPPP"
    };

    int startRow, startCol, goalRow, goalCol;
    Graph* graph = create_graph_from_map(test_map, rows, cols, &startRow, &startCol, &goalRow, &goalCol);

    printf("Start position: (%d, %d)\n", startRow, startCol);
    printf("Goal position: (%d, %d)\n", goalRow, goalCol);
    printf("\nGraph terrain cost map:\n");
    print_graph_costs(graph);

    PathStep* path = NULL;
    int length = 0;

    dijkstra(graph, startRow, startCol, goalRow, goalCol, &path, &length);

    if (length > 0 && path != NULL) {
        print_map_with_path(test_map, rows, cols, path, length);

        free(path);
    }
    else {
        printf("No path found or path length is zero.\n");
    }

    free_graph(graph);
    return 0;
}
