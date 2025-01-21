#ifndef GRAPHVISUALIZER_H
#define GRAPHVISUALIZER_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include <QMap>
#include <QColor>
#include "../include/Graph.h"

class GraphVisualizer : public QGraphicsView {
    Q_OBJECT

public:
    GraphVisualizer(const Graph& graph, const std::vector<int>& colors, QWidget* parent = nullptr);

private:
    void drawGraph();
    void drawVertices();
    void drawEdges();

    const Graph& graph;
    const std::vector<int>& colors;

    QGraphicsScene* scene;
    QMap<int, QPointF> vertexPositions;
};

#endif