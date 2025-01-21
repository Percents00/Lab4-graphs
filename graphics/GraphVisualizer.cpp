#include "../graphics/GraphVisualizer.h"
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QFont>
#include <cmath>

GraphVisualizer::GraphVisualizer(const Graph& graph, const std::vector<int>& colors, QWidget* parent)
    : QGraphicsView(parent), graph(graph), colors(colors) {
    scene = new QGraphicsScene(this);
    setScene(scene);
    int vertices = graph.getVertices();
    float radius = 200.0f;
    QPointF center(400.0f, 300.0f);

    for (int i = 0; i < vertices; ++i) {
        float angle = 2 * M_PI * i / vertices;
        float x = center.x() + radius * std::cos(angle);
        float y = center.y() + radius * std::sin(angle);
        vertexPositions[i] = QPointF(x, y);
    }

    drawGraph();
}

void GraphVisualizer::drawGraph() {
    drawEdges();
    drawVertices();
}

void GraphVisualizer::drawVertices() {
    int vertices = graph.getVertices();
    float radius = 20.0f;

    for (int i = 0; i < vertices; ++i) {
        QPointF position = vertexPositions[i];
        QGraphicsEllipseItem* vertex = scene->addEllipse(position.x() - radius, position.y() - radius, 2 * radius, 2 * radius);
        switch (colors[i]) {
            case 0: vertex->setBrush(Qt::red); break;
            case 1: vertex->setBrush(Qt::green); break;
            case 2: vertex->setBrush(Qt::blue); break;
            case 3: vertex->setBrush(Qt::yellow); break;
            default: vertex->setBrush(Qt::black); break;
        }
        QGraphicsTextItem* label = scene->addText(QString::number(i));
        label->setPos(position.x() - 5, position.y() - 10);
    }
}

void GraphVisualizer::drawEdges() {
    for (int i = 0; i < graph.getVertices(); ++i) {
        for (int neighbor : graph.getAdjacencyList()[i]) {
            QPointF start = vertexPositions[i];
            QPointF end = vertexPositions[neighbor];
            scene->addLine(start.x(), start.y(), end.x(), end.y(), QPen(Qt::black));
        }
    }
}