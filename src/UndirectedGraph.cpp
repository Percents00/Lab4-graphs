#include "../include/UndirectedGraph.h"
#include <iostream>
#include <algorithm>
#include <queue>

template <typename VertexType, typename EdgeType>
void UndirectedGraph<VertexType, EdgeType>::addEdge(const VertexType& u, const VertexType& v, const EdgeType& edge) {
    adjacencyList[u].emplace_back(v, edge);
    adjacencyList[v].emplace_back(u, edge);
}

template <typename VertexType, typename EdgeType>
void UndirectedGraph<VertexType, EdgeType>::removeEdge(const VertexType& u, const VertexType& v) {
    auto& neighborsU = adjacencyList[u];
    neighborsU.erase(std::remove_if(neighborsU.begin(), neighborsU.end(),
        [&v](const std::pair<VertexType, EdgeType>& pair) {
            return pair.first == v;
        }), neighborsU.end());

    auto& neighborsV = adjacencyList[v];
    neighborsV.erase(std::remove_if(neighborsV.begin(), neighborsV.end(),
        [&u](const std::pair<VertexType, EdgeType>& pair) {
            return pair.first == u;
        }), neighborsV.end());
}

template <typename VertexType, typename EdgeType>
bool UndirectedGraph<VertexType, EdgeType>::hasEdge(const VertexType& u, const VertexType& v) const {
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
std::vector<VertexType> UndirectedGraph<VertexType, EdgeType>::getVertices() const {
    std::vector<VertexType> vertices;
    for (const auto& pair : adjacencyList) {
        vertices.push_back(pair.first);
    }
    return vertices;
}

template <typename VertexType, typename EdgeType>
std::vector<VertexType> UndirectedGraph<VertexType, EdgeType>::getNeighbors(const VertexType& u) const {
    std::vector<VertexType> neighbors;
    if (adjacencyList.find(u) != adjacencyList.end()) {
        for (const auto& pair : adjacencyList.at(u)) {
            neighbors.push_back(pair.first);
        }
    }
    return neighbors;
}

template <typename VertexType, typename EdgeType>
bool UndirectedGraph<VertexType, EdgeType>::isDirected() const {
    return false;
}

 template <typename VertexType, typename EdgeType>
 void UndirectedGraph<VertexType, EdgeType>::printGraph() const {
     for (const auto& pair : adjacencyList) {
         std::cout << "Vertex " << pair.first << " is connected to: ";
         for (const auto& neighbor : pair.second) {
             std::cout << neighbor.first << " (weight: " << neighbor.second << ") ";
         }
         std::cout << std::endl;
     }
}

template <typename VertexType, typename EdgeType>
int UndirectedGraph<VertexType, EdgeType>::getVerticesCount() const {
    return adjacencyList.size();
}

template <typename VertexType, typename EdgeType>
void UndirectedGraph<VertexType, EdgeType>::addVertex(const VertexType& vertex) {
    if (adjacencyList.find(vertex) == adjacencyList.end()) {
        adjacencyList[vertex] = std::vector<std::pair<VertexType, EdgeType>>();
    }
}

template class UndirectedGraph<int, int>;