#ifndef GRAPH_COLORING_H
#define GRAPH_COLORING_H

#include "Graph.h"
#include <vector>

class GraphColoring {
public:
    static std::vector<int> colorGraph(const Graph& graph);
    static bool isColoringValid(const Graph& graph, const std::vector<int>& colors);
    static void printColoring(const std::vector<int>& colors);
};

#endif