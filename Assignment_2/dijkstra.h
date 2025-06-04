// ================================
// dijkstra.h
// ================================
#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "graph.h"

// GenAI Acknowledgment:
// This function and header were created with the assistance of ChatGPT to implement Dijkstra's algorithm for a grid-based graph in C.

int dijkstra(Graph* graph, int start_row, int start_col, int goal_row, int goal_col, PathStep* out_path[], int* out_length);

#endif
