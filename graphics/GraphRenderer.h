#ifndef GRAPHRENDERER_H
#define GRAPHRENDERER_H

#include <QGraphicsScene>
#include <QMap>
#include <vector>
#include "../include/IGraph.h"

class GraphRenderer {
public:
    GraphRenderer(QGraphicsScene* scene);
    void renderGraph(const IGraph<int, int>* graph, const std::vector<int>& colors = {});

private:
    void drawVertices(const QMap<int, QPointF>& vertexPositions, const std::vector<int>& colors);
    void drawEdges(const QMap<int, QPointF>& vertexPositions);
    void drawArrow(const QPointF& start, const QPointF& end);

    QGraphicsScene* scene;
    const IGraph<int, int>* currentGraph;
    QMap<int, QPointF> vertexPositions;
};

#endif // GRAPHRENDERER_H