#ifndef GRAPH_GENERATOR_H
#define GRAPH_GENERATOR_H

#include "DirectedGraph.h"
#include "UndirectedGraph.h"

class GraphGenerator {
public:
    static IGraph<int, int>* generateRandomGraph(int vertices, int edges, bool directed);
    static IGraph<int, int>* generatePentagram();
    static IGraph<int, int>* generateCompleteGraph(int vertices, bool directed);
    static IGraph<int, int>* generateRingGraph(int vertices, bool directed);

private:
    static bool hasEdge(const IGraph<int, int>& graph, int u, int v);
};

#endif