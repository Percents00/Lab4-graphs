#ifndef GRAPH_COLORING_H
#define GRAPH_COLORING_H

#include "UndirectedGraph.h"
#include <vector>

class GraphColoring {
public:
    static std::vector<int> colorGraph(const UndirectedGraph<int, int>& graph);
    static bool isColoringValid(const UndirectedGraph<int, int>& graph, const std::vector<int>& colors);
    static void printColoring(const std::vector<int>& colors);
};

#endif