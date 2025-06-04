// ================================
// astar.c
// ================================
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include "astar.h"

// GenAI Acknowledgment:
// This A* implementation was derived from a Dijkstra's version originally generated with ChatGPT's help, and adapted to include heuristic search.

typedef struct {
    int g_cost;    // Cost from start
    int h_cost;    // Heuristic cost to goal
    int f_cost;    // Total cost = g + h
    int visited;
    Node* prev;
} AStarNode;

static int heuristic(int r1, int c1, int r2, int c2) {
    return abs(r1 - r2) + abs(c1 - c2);  // Manhattan distance
}

int astar(Graph* graph, int start_row, int start_col, int goal_row, int goal_col, PathStep* out_path[], int* out_length) {
    int rows = graph->rows;
    int cols = graph->cols;

    AStarNode** anodes = malloc(rows * sizeof(AStarNode*));
    for (int r = 0; r < rows; r++) {
        anodes[r] = malloc(cols * sizeof(AStarNode));
        for (int c = 0; c < cols; c++) {
            anodes[r][c].g_cost = INT_MAX;
            anodes[r][c].h_cost = 0;
            anodes[r][c].f_cost = INT_MAX;
            anodes[r][c].visited = 0;
            anodes[r][c].prev = NULL;
        }
    }

    anodes[start_row][start_col].g_cost = 0;
    anodes[start_row][start_col].h_cost = heuristic(start_row, start_col, goal_row, goal_col);
    anodes[start_row][start_col].f_cost = anodes[start_row][start_col].h_cost;

    while (1) {
        int min_f = INT_MAX;
        Node* current = NULL;
        int cur_r = -1, cur_c = -1;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (!anodes[r][c].visited && anodes[r][c].f_cost < min_f) {
                    min_f = anodes[r][c].f_cost;
                    current = &graph->nodes[r][c];
                    cur_r = r;
                    cur_c = c;
                }
            }
        }

        if (current == NULL) break;
        if (cur_r == goal_row && cur_c == goal_col) break;

        anodes[cur_r][cur_c].visited = 1;

        for (int i = 0; i < current->neighbor_count; i++) {
            Node* neighbor = current->neighbors[i];
            int nr = neighbor->row, nc = neighbor->col;
            int cost = current->neighbor_costs[i];

            if (!anodes[nr][nc].visited) {
                int tentative_g = anodes[cur_r][cur_c].g_cost + cost;
                if (tentative_g < anodes[nr][nc].g_cost) {
                    anodes[nr][nc].g_cost = tentative_g;
                    anodes[nr][nc].h_cost = heuristic(nr, nc, goal_row, goal_col);
                    anodes[nr][nc].f_cost = tentative_g + anodes[nr][nc].h_cost;
                    anodes[nr][nc].prev = current;
                }
            }
        }
    }

    // Reconstruct path
    *out_length = 0;
    Node* step = &graph->nodes[goal_row][goal_col];
    while (step != NULL) {
        (*out_length)++;
        step = anodes[step->row][step->col].prev;
    }

    *out_path = malloc(*out_length * sizeof(PathStep));
    step = &graph->nodes[goal_row][goal_col];
    for (int i = *out_length - 1; i >= 0; i--) {
        (*out_path)[i].row = step->row;
        (*out_path)[i].col = step->col;
        step = anodes[step->row][step->col].prev;
    }

    for (int r = 0; r < rows; r++) free(anodes[r]);
    free(anodes);

    return 0;
}
