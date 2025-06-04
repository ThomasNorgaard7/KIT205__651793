// ================================
// display.h
// ================================
#ifndef DISPLAY_H
#define DISPLAY_H

#include "graph.h"
#include "dijkstra.h"

// GenAI Acknowledgment:
// This display module was created with ChatGPT to centralize map and graph visualization.

void print_graph_costs(Graph* graph);
void print_map_with_path(char** map, int rows, int cols, PathStep* path, int length, int print_steps);

#endif