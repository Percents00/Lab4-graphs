#include "../include/DirectedGraph.h"
#include <iostream>
#include <algorithm>
#include <queue>

template <typename VertexType, typename EdgeType>
void DirectedGraph<VertexType, EdgeType>::addEdge(const VertexType& u, const VertexType& v, const EdgeType& edge) {
    adjacencyList[u].emplace_back(v, edge);
}

template <typename VertexType, typename EdgeType>
void DirectedGraph<VertexType, EdgeType>::removeEdge(const VertexType& u, const VertexType& v) {
    auto& neighbors = adjacencyList[u];
    neighbors.erase(std::remove_if(neighbors.begin(), neighbors.end(),
        [&v](const std::pair<VertexType, EdgeType>& pair) {
            return pair.first == v;
        }), neighbors.end());
}

template <typename VertexType, typename EdgeType>
bool DirectedGraph<VertexType, EdgeType>::hasEdge(const VertexType& u, const VertexType& v) const {
    if (adjacencyList.find(u) == adjacencyList.end()) {
        return false;
    }
    for (const auto& neighbor : adjacencyList.at(u)) {
        if (neighbor.first == v) {
            return true;
        }
    }
    return false;
}

template <typename VertexType, typename EdgeType>
std::vector<VertexType> DirectedGraph<VertexType, EdgeType>::getVertices() const {
    std::vector<VertexType> vertices;
    for (const auto& pair : adjacencyList) {
        vertices.push_back(pair.first);
    }
    return vertices;
}

template <typename VertexType, typename EdgeType>
std::vector<VertexType> DirectedGraph<VertexType, EdgeType>::getNeighbors(const VertexType& u) const {
    std::vector<VertexType> neighbors;
    if (adjacencyList.find(u) != adjacencyList.end()) {
        for (const auto& pair : adjacencyList.at(u)) {
            neighbors.push_back(pair.first);
        }
    }
    return neighbors;
}

template <typename VertexType, typename EdgeType>
bool DirectedGraph<VertexType, EdgeType>::isDirected() const {
    return true;
}

template <typename VertexType, typename EdgeType>
void DirectedGraph<VertexType, EdgeType>::printGraph() const {
    for (const auto& pair : adjacencyList) {
        std::cout << "Vertex " << pair.first << " is connected to: ";
        for (const auto& neighbor : pair.second) {
            std::cout << neighbor.first << " (weight: " << neighbor.second << ") ";
        }
        std::cout << std::endl;
    }
}

template <typename VertexType, typename EdgeType>
int DirectedGraph<VertexType, EdgeType>::getVerticesCount() const {
    return adjacencyList.size();
}


template <typename VertexType, typename EdgeType>
void DirectedGraph<VertexType, EdgeType>::addVertex(const VertexType& vertex) {
    if (adjacencyList.find(vertex) == adjacencyList.end()) {
        adjacencyList[vertex] = std::vector<std::pair<VertexType, EdgeType>>();
    }
}

template class DirectedGraph<int, int>;