// ================================
// graph.c
// ================================
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

// GenAI Acknowledgment:
// This function was written with the assistance of ChatGPT to convert a 2D char array into a graph with neighbors and traversal costs.

static int terrain_cost(char t) {
    switch (t) {
        case 'P': return TERRAIN_PLAIN;
        case 'F': return TERRAIN_FOREST;
        case 'W': return TERRAIN_WATER;
        case 'S': return TERRAIN_START;
        case 'G': return TERRAIN_GOAL;
        default: return 999; // impassable or undefined
    }
}

Graph* create_graph_from_map(char** map, int rows, int cols) {
    Graph* graph = malloc(sizeof(Graph));
    graph->rows = rows;
    graph->cols = cols;

    graph->nodes = malloc(rows * sizeof(Node*));
    for (int r = 0; r < rows; r++) {
        graph->nodes[r] = malloc(cols * sizeof(Node));
        for (int c = 0; c < cols; c++) {
            Node* node = &graph->nodes[r][c];
            node->row = r;
            node->col = c;
            node->cost = terrain_cost(map[r][c]);
            node->neighbor_count = 0;
        }
    }

    // Set neighbors (up/down/left/right)
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            Node* node = &graph->nodes[r][c];
            int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
            for (int i = 0; i < 4; i++) {
                int nr = r + dirs[i][0];
                int nc = c + dirs[i][1];
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                    node->neighbors[node->neighbor_count] = &graph->nodes[nr][nc];
                    node->neighbor_costs[node->neighbor_count] = graph->nodes[nr][nc].cost;
                    node->neighbor_count++;
                }
            }
        }
    }

    return graph;
}

void free_graph(Graph* graph) {
    for (int r = 0; r < graph->rows; r++) {
        free(graph->nodes[r]);
    }
    free(graph->nodes);
    free(graph);
}


void print_graph_costs(Graph* graph) {
    for (int r = 0; r < graph->rows; r++) {
        for (int c = 0; c < graph->cols; c++) {
            printf("%2d ", graph->nodes[r][c].cost);
        }
        printf("\n");
    }
}
