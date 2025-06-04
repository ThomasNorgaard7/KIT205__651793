// ================================
// main.c
// ================================
#include <stdio.h>
#include <stdlib.h>  // For malloc/free

#include "graph.h"
#include "dijkstra.h"
#include "display.h"
#include "timer.h"

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

    printf("\nDijkstra Method:\n");

    Timer timer;
    timer_start(&timer);

    dijkstra(graph, startRow, startCol, goalRow, goalCol, &path, &length);

    double elapsed = timer_elapsed_seconds(&timer);
    printf("Dijkstra completed in %.6f seconds.\n", elapsed);

    int dis_steps = 0; // debugging varriable
    if (length > 0 && path != NULL) {
        print_map_with_path(test_map, rows, cols, path, length, dis_steps);

        free(path);
    }
    else {
        printf("No path found or path length is zero.\n");
    }

    free_graph(graph);
    return 0;
}
