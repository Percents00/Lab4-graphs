#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>

class Graph {
public:
    Graph(int vertices = 0, bool directed = false);
    void addEdge(int u, int v);
    void removeEdge(int u, int v);
    void printGraph() const;
    bool isConnected() const;
    int getVertices() const;
    const std::vector<std::vector<int>>& getAdjacencyList() const;

    bool hasEdge(int u, int v) const;

private:
    int vertices;
    bool directed;
    std::vector<std::vector<int>> adjacencyList;
};

#endif