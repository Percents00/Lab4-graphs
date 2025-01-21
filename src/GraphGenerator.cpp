#include "../include/GraphGenerator.h"
#include <algorithm>
#include <random>

Graph GraphGenerator::generateRandomGraph(int vertices, int edges, bool directed) {
    Graph graph(vertices, directed);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, vertices - 1);
    for (int i = 1; i < vertices; ++i) {
        int parent = dis(gen) % i;
        graph.addEdge(parent, i);
    }
    int remainingEdges = edges - (vertices - 1);
    for (int i = 0; i < remainingEdges; ++i) {
        int u = dis(gen);
        int v = dis(gen);
        if (u != v && !hasEdge(graph, u, v)) {
            graph.addEdge(u, v);
        }
    }

    return graph;
}
Graph GraphGenerator::generatePentagram() {
    Graph graph(5);

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 0);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 0);
    graph.addEdge(4, 1);

    return graph;
}
Graph GraphGenerator::generateCompleteGraph(int vertices) {
    Graph graph(vertices);
    for (int i = 0; i < vertices; ++i) {
        for (int j = i + 1; j < vertices; ++j) {
            graph.addEdge(i, j);
        }
    }

    return graph;
}

Graph GraphGenerator::generateRingGraph(int vertices) {
    Graph graph(vertices);

    for (int i = 0; i < vertices; ++i) {
        graph.addEdge(i, (i + 1) % vertices);
    }

    return graph;
}

bool GraphGenerator::hasEdge(const Graph& graph, int u, int v) {
    for (int neighbor : graph.getAdjacencyList()[u]) {
        if (neighbor == v) {
            return true;
        }
    }
    return false;
}