#include "GraphRenderer.h"
#include <QGraphicsEllipseItem>
#include <QGraphicsLineItem>
#include <QGraphicsTextItem>
#include <QtMath>

GraphRenderer::GraphRenderer(QGraphicsScene* scene) : scene(scene), currentGraph(nullptr) {}

void GraphRenderer::renderGraph(const IGraph<int, int>* graph, const std::vector<int>& colors) {
    scene->clear();
    currentGraph = graph;

    const auto& vertices = graph->getVertices();
    const float radius = 20.0f;
    const float centerX = 400;
    const float centerY = 300;
    const float circleRadius = 200;

    vertexPositions.clear();
    int index = 0;
    for (int vertexId : vertices) {
        const float angle = 2 * M_PI * index / vertices.size();
        const float x = centerX + circleRadius * qCos(angle);
        const float y = centerY + circleRadius * qSin(angle);
        vertexPositions[vertexId] = QPointF(x, y);
        index++;
    }

    drawEdges(vertexPositions);
    drawVertices(vertexPositions, colors);
}

void GraphRenderer::drawVertices(const QMap<int, QPointF>& vertexPositions, const std::vector<int>& colors) {
    const float radius = 20.0f;
    int index = 0;
    for (auto it = vertexPositions.constBegin(); it != vertexPositions.constEnd(); ++it) {
        int vertexId = it.key();
        QPointF pos = it.value();
        QColor color = Qt::lightGray;
        if (index < colors.size()) {
            int colorValue = colors[index];
            int hue = (colorValue * 67) % 360;
            color = QColor::fromHsl(hue, 255, 150);
        }
        QGraphicsEllipseItem* vertex = scene->addEllipse(
            pos.x() - radius,
            pos.y() - radius,
            2 * radius,
            2 * radius,
            QPen(Qt::black),
            QBrush(color)
        );
        QGraphicsTextItem* label = scene->addText(QString::number(vertexId));
        label->setPos(pos.x() - 5, pos.y() - radius - 20);
        index++;
    }
}

void GraphRenderer::drawEdges(const QMap<int, QPointF>& vertexPositions) {
    const float vertexRadius = 20.0f;
    for (int u : currentGraph->getVertices()) {
        for (int v : currentGraph->getNeighbors(u)) {
            QPointF startPos = vertexPositions[u];
            QPointF endPos = vertexPositions[v];
            QLineF line(startPos, endPos);

            line.setLength(line.length() - vertexRadius);

            if (currentGraph->isDirected()) {
                drawArrow(line.p1(), line.p2());
            } else {
                scene->addLine(line, QPen(Qt::black, 2));
            }
        }
    }
}

void GraphRenderer::drawArrow(const QPointF& start, const QPointF& end) {
    const float arrowSize = 10.0f;
    QLineF line(end, start);
    double angle = qAtan2(-line.dy(), line.dx());
    
    QPointF arrowP1 = end + QPointF(qSin(angle + M_PI / 3) * arrowSize, qCos(angle + M_PI / 3) * arrowSize);
    QPointF arrowP2 = end + QPointF(qSin(angle + M_PI - M_PI / 3) * arrowSize, qCos(angle + M_PI - M_PI / 3) * arrowSize);
    
    scene->addLine(QLineF(end, arrowP1), QPen(Qt::black, 2));
    scene->addLine(QLineF(end, arrowP2), QPen(Qt::black, 2));
    scene->addLine(QLineF(start, end), QPen(Qt::black, 2));
}
