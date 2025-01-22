#ifndef IGRAPH_H
#define IGRAPH_H

#include <vector>

template <typename VertexType, typename EdgeType>
class IGraph {
public:
    virtual ~IGraph() = default;

    virtual void addVertex(const VertexType& vertex) = 0;

    virtual void addEdge(const VertexType& u, const VertexType& v, const EdgeType& edge) = 0;

    virtual void removeEdge(const VertexType& u, const VertexType& v) = 0;

    virtual bool hasEdge(const VertexType& u, const VertexType& v) const = 0;

    virtual std::vector<VertexType> getVertices() const = 0;

    virtual std::vector<VertexType> getNeighbors(const VertexType& u) const = 0;

    virtual bool isDirected() const = 0;

    virtual void printGraph() const = 0;

    virtual int getVerticesCount() const = 0;
};

#endif // IGRAPH_H