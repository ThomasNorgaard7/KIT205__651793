// ================================
// astar.h
// ================================
#ifndef ASTAR_H
#define ASTAR_H

#include "graph.h"

// GenAI Acknowledgment:
// This header was generated with assistance from ChatGPT to implement A* search 
// using a Manhattan-distance heuristic on a 2D grid.

int astar(Graph* graph, int start_row, int start_col, int goal_row, int goal_col, PathStep* out_path[], int* out_length);

#endif
