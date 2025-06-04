// ================================
// display.c
// ================================
#include <stdio.h>
#include <stdlib.h>
#include "display.h"

void print_graph_costs(Graph* graph) {
    for (int r = 0; r < graph->rows; r++) {
        for (int c = 0; c < graph->cols; c++) {
            printf("%2d ", graph->nodes[r][c].cost);
        }
        printf("\n");
    }

}void print_map_with_path(char** map, int rows, int cols, PathStep* path, int length, int print_steps) {

    if (!map || !path || length <= 0) {
        printf("Invalid map or path data.\n");
        return;
    }

    // Debug print path steps and validate coordinates
    if (print_steps) {
        printf("\nPath length: %d\n", length);
        printf("\nPath Steps:\n");
        for (int i = 0; i < length; i++) {
            int r = path[i].row;
            int c = path[i].col;
            if (r < 0 || r >= rows || c < 0 || c >= cols) {
                printf("Invalid path coordinate at step %d: (%d, %d)\n", i, r, c);
                return;
            }
            printf("Step %d: (%d, %d)\n", i, r, c);
        }
    }

    // Create a copy of the map so we don't overwrite the original
    char** display_map = malloc(rows * sizeof(char*));
    if (!display_map) {
        printf("Memory allocation failed for display_map\n");
        return;
    }

    for (int r = 0; r < rows; r++) {
        display_map[r] = malloc((cols + 1) * sizeof(char));
        if (!display_map[r]) {
            printf("Memory allocation failed for display_map[%d]\n", r);
            // Free previously allocated rows before return
            for (int rr = 0; rr < r; rr++) free(display_map[rr]);
            free(display_map);
            return;
        }
        for (int c = 0; c < cols; c++) {
            display_map[r][c] = map[r][c];
        }
        display_map[r][cols] = '\0'; // Null-terminate each row string
    }

    // For each step except last, set arrow pointing to next step
    for (int i = 0; i < length - 1; i++) {
        int r = path[i].row;
        int c = path[i].col;
        int nr = path[i + 1].row;
        int nc = path[i + 1].col;

        // Do not overwrite Start or Goal chars
        if (map[r][c] == 'S' || map[r][c] == 'G') {
            continue;
        }

        if (nr == r && nc == c + 1) {
            display_map[r][c] = '>';
        }
        else if (nr == r && nc == c - 1) {
            display_map[r][c] = '<';
        }
        else if (nr == r + 1 && nc == c) {
            display_map[r][c] = 'v';
        }
        else if (nr == r - 1 && nc == c) {
            display_map[r][c] = '^';
        }
    }

    // Print the display map with path arrows
    printf("\nPath on map:\n");
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            printf("%c  ", display_map[r][c]);  // print char + 2 spaces
        }
        printf("\n");
    }

    for (int r = 0; r < rows; r++) {
        free(display_map[r]);
    }
    free(display_map);
}
