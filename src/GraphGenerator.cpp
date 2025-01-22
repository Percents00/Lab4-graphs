#include "../include/GraphGenerator.h"
#include <algorithm>
#include <random>

IGraph<int, int>* GraphGenerator::generateRandomGraph(int vertices, int edges, bool directed) {
    IGraph<int, int>* graph = directed ? static_cast<IGraph<int, int>*>(new DirectedGraph<int, int>())
                                       : static_cast<IGraph<int, int>*>(new UndirectedGraph<int, int>());

    for (int i = 0; i < vertices; ++i) {
        graph->addVertex(i);
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, vertices - 1);

    for (int i = 1; i < vertices; ++i) {
        int parent = dis(gen) % i;
        graph->addEdge(parent, i, 0);
    }

    int remainingEdges = edges - (vertices - 1);
    for (int i = 0; i < remainingEdges; ++i) {
        int u = dis(gen);
        int v = dis(gen);
        if (u != v && !hasEdge(*graph, u, v)) {
            graph->addEdge(u, v, 0);
            if (!directed && !hasEdge(*graph, v, u)) {
                graph->addEdge(v, u, 0);
            }
        } else {
            i--;
        }
    }

    return graph;
}

IGraph<int, int>* GraphGenerator::generatePentagram() {
    auto* graph = new UndirectedGraph<int, int>();
    for (int i = 0; i < 5; ++i) {
        graph->addVertex(i);
    }
    graph->addEdge(0, 1, 0);
    graph->addEdge(1, 2, 0);
    graph->addEdge(2, 3, 0);
    graph->addEdge(3, 4, 0);
    graph->addEdge(4, 0, 0);
    graph->addEdge(0, 2, 0);
    graph->addEdge(1, 3, 0);
    graph->addEdge(2, 4, 0);
    graph->addEdge(3, 0, 0);
    graph->addEdge(4, 1, 0);
    return graph;
}

IGraph<int, int>* GraphGenerator::generateCompleteGraph(int vertices, bool directed) {
    auto* graph = directed ? static_cast<IGraph<int, int>*>(new DirectedGraph<int, int>())
                           : static_cast<IGraph<int, int>*>(new UndirectedGraph<int, int>());

    for (int i = 0; i < vertices; ++i) {
        for (int j = i + 1; j < vertices; ++j) {
            graph->addEdge(i, j, 0);
        }
    }

    return graph;
}

IGraph<int, int>* GraphGenerator::generateRingGraph(int vertices, bool directed) {
    auto* graph = directed ? static_cast<IGraph<int, int>*>(new DirectedGraph<int, int>())
                           : static_cast<IGraph<int, int>*>(new UndirectedGraph<int, int>());

    for (int i = 0; i < vertices; ++i) {
        graph->addEdge(i, (i + 1) % vertices, 0);
    }

    return graph;
}

bool GraphGenerator::hasEdge(const IGraph<int, int>& graph, int u, int v) {
    return graph.hasEdge(u, v);
}