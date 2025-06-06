// ================================
// graph.h
// ================================
#ifndef GRAPH_H
#define GRAPH_H

#define MAX_NEIGHBORS 4

// GenAI Acknowledgment:
// This graph structure was initially generated with the assistance of ChatGPT to model a 2D grid as an adjacency list for Zelda-style terrain maps.

// Terrain cost enum
typedef enum {
    TERRAIN_PLAIN = 1,
    TERRAIN_FOREST = 3,
    TERRAIN_WATER = 5,
    TERRAIN_START = 0,
    TERRAIN_GOAL = 0
} TerrainCost;

// Node in the grid
typedef struct Node {
    int row, col;
    int cost; // cost to traverse this node
    struct Node* neighbors[MAX_NEIGHBORS];
    int neighbor_costs[MAX_NEIGHBORS];
    int neighbor_count;
} Node;

// Graph holds the 2D grid as nodes
typedef struct {
    int rows;
    int cols;
    Node** nodes; // 2D array of nodes
} Graph;

typedef struct {
    int row, col;
} PathStep;

Graph* create_graph_from_map(char** map, int rows, int cols, int* startRow, int* startCol, int* goalRow, int* goalCol);
void free_graph(Graph* graph);

#endif
