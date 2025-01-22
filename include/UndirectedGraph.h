#ifndef UNDIRECTEDGRAPH_H
#define UNDIRECTEDGRAPH_H

#include "IGraph.h"
#include <map>
#include <vector>

template <typename VertexType, typename EdgeType>
class UndirectedGraph : public IGraph<VertexType, EdgeType> {
private:
    std::map<VertexType, std::vector<std::pair<VertexType, EdgeType>>> adjacencyList;

public:
    void addVertex(const VertexType& vertex) override;
    void addEdge(const VertexType& u, const VertexType& v, const EdgeType& edge) override;
    void removeEdge(const VertexType& u, const VertexType& v) override;
    bool hasEdge(const VertexType& u, const VertexType& v) const override;
    std::vector<VertexType> getVertices() const override;
    std::vector<VertexType> getNeighbors(const VertexType& u) const override;
    bool isDirected() const override;
    void printGraph() const override;
    int getVerticesCount() const override;
};

#endif // UNDIRECTEDGRAPH_H