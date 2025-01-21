#ifndef GRAPH_GENERATOR_H
#define GRAPH_GENERATOR_H

#include "Graph.h"

class GraphGenerator {
public:
    static Graph generateRandomGraph(int vertices, int edges, bool directed = false);
    static Graph generatePentagram();
    static Graph generateCompleteGraph(int vertices);
    static Graph generateRingGraph(int vertices);

private:
    static bool hasEdge(const Graph& graph, int u, int v);
};

#endif