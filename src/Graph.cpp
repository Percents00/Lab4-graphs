#include "../include/Graph.h"
#include <queue>
#include <algorithm>
Graph::Graph(int vertices, bool directed) : vertices(vertices), directed(directed) {
    adjacencyList.resize(vertices);
}

void Graph::addEdge(int u, int v) {
    if (!hasEdge(u, v)) {
        adjacencyList[u].push_back(v);
        if (!directed && !hasEdge(v, u)) {
            adjacencyList[v].push_back(u);
        }
    }
}
void Graph::removeEdge(int u, int v) {
    adjacencyList[u].erase(std::remove(adjacencyList[u].begin(), adjacencyList[u].end(), v), adjacencyList[u].end());
    if (!directed) {
        adjacencyList[v].erase(std::remove(adjacencyList[v].begin(), adjacencyList[v].end(), u), adjacencyList[v].end());
    }
}
void Graph::printGraph() const {
    for (int i = 0; i < vertices; ++i) {
        std::cout << "Vertex " << i << " is connected to: ";
        for (int neighbor : adjacencyList[i]) {
            std::cout << neighbor << " ";
        }
        std::cout << std::endl;
    }
}
bool Graph::isConnected() const {
    if (vertices == 0) return true;

    std::vector<bool> visited(vertices, false);
    std::queue<int> q;

    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : adjacencyList[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    for (bool v : visited) {
        if (!v) return false;
    }
    return true;
}
int Graph::getVertices() const {
    return vertices;
}
const std::vector<std::vector<int>>& Graph::getAdjacencyList() const {
    return adjacencyList;
}

bool Graph::hasEdge(int u, int v) const {
    for (int neighbor : adjacencyList[u]) {
        if (neighbor == v) {
            return true;
        }
    }
    return false;
}

