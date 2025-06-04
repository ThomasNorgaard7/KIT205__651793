// ================================
// dijkstra.c
// ================================
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "dijkstra.h"

// GenAI Acknowledgment:
// This Dijkstra’s algorithm implementation was generated with ChatGPT's help. It works on a 2D grid with neighbor pointers.

typedef struct {
    int dist;
    int visited;
    Node* prev;
} DijkstraNode;

int dijkstra(Graph* graph, int start_row, int start_col, int goal_row, int goal_col, PathStep* out_path[], int* out_length) {
    int rows = graph->rows;
    int cols = graph->cols;

    DijkstraNode** dnodes = malloc(rows * sizeof(DijkstraNode*));
    for (int r = 0; r < rows; r++) {
        dnodes[r] = malloc(cols * sizeof(DijkstraNode));
        for (int c = 0; c < cols; c++) {
            dnodes[r][c].dist = INT_MAX;
            dnodes[r][c].visited = 0;
            dnodes[r][c].prev = NULL;
        }
    }

    dnodes[start_row][start_col].dist = 0;

    while (1) {
        // Find unvisited node with smallest distance
        int min_dist = INT_MAX;
        Node* current = NULL;
        int cur_r = -1, cur_c = -1;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (!dnodes[r][c].visited && dnodes[r][c].dist < min_dist) {
                    min_dist = dnodes[r][c].dist;
                    current = &graph->nodes[r][c];
                    cur_r = r;
                    cur_c = c;
                }
            }
        }

        if (current == NULL) break; // All reachable nodes visited
        if (cur_r == goal_row && cur_c == goal_col) break; // Goal reached

        dnodes[cur_r][cur_c].visited = 1;

        for (int i = 0; i < current->neighbor_count; i++) {
            Node* neighbor = current->neighbors[i];
            int nr = neighbor->row, nc = neighbor->col;
            int cost = current->neighbor_costs[i];

            if (!dnodes[nr][nc].visited) {
                int alt = dnodes[cur_r][cur_c].dist + cost;
                if (alt < dnodes[nr][nc].dist) {
                    dnodes[nr][nc].dist = alt;
                    dnodes[nr][nc].prev = current;
                }
            }
        }
    }

    // Reconstruct path
    *out_length = 0;
    Node* step = &graph->nodes[goal_row][goal_col];
    while (step != NULL) {
        (*out_length)++;
        step = dnodes[step->row][step->col].prev;
    }

    *out_path = malloc(*out_length * sizeof(PathStep));
    step = &graph->nodes[goal_row][goal_col];
    for (int i = *out_length - 1; i >= 0; i--) {
        (*out_path)[i].row = step->row;
        (*out_path)[i].col = step->col;
        step = dnodes[step->row][step->col].prev;
    }

    // Free temporary data
    for (int r = 0; r < rows; r++) free(dnodes[r]);
    free(dnodes);

    return 0;
}
