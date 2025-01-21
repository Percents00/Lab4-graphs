#include "MainWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QGraphicsTextItem>
#include <cmath>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), graph(0, false) {
    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);
    QHBoxLayout* inputLayout = new QHBoxLayout();
    QLabel* verticesLabel = new QLabel("Количество вершин:", this);
    inputLayout->addWidget(verticesLabel);

    verticesSpinBox = new QSpinBox(this);
    verticesSpinBox->setRange(1, 100);
    verticesSpinBox->setValue(10);
    inputLayout->addWidget(verticesSpinBox);
    QLabel* edgesLabel = new QLabel("Количество рёбер:", this);
    inputLayout->addWidget(edgesLabel);

    edgesSpinBox = new QSpinBox(this);
    edgesSpinBox->setRange(1, 1000);
    edgesSpinBox->setValue(15);
    inputLayout->addWidget(edgesSpinBox);
    generateButton = new QPushButton("Генерировать граф", this);
    inputLayout->addWidget(generateButton);
    colorButton = new QPushButton("Раскрасить граф", this);
    inputLayout->addWidget(colorButton);
    pentagramButton = new QPushButton("Пентаграмма", this);
    inputLayout->addWidget(pentagramButton);
    completeGraphButton = new QPushButton("Полный граф", this);
    inputLayout->addWidget(completeGraphButton);
    ringGraphButton = new QPushButton("Кольцевой граф", this);
    inputLayout->addWidget(ringGraphButton);
    mainLayout->addLayout(inputLayout);
    graphicsView = new QGraphicsView(this);
    scene = new QGraphicsScene(this);
    graphicsView->setScene(scene);
    mainLayout->addWidget(graphicsView);
    connect(generateButton, &QPushButton::clicked, this, &MainWindow::onGenerateButtonClicked);
    connect(colorButton, &QPushButton::clicked, this, &MainWindow::onColorButtonClicked);
    connect(pentagramButton, &QPushButton::clicked, this, &MainWindow::onPentagramButtonClicked);
    connect(completeGraphButton, &QPushButton::clicked, this, &MainWindow::onCompleteGraphButtonClicked);
    connect(ringGraphButton, &QPushButton::clicked, this, &MainWindow::onRingGraphButtonClicked);
}

MainWindow::~MainWindow() {
    delete scene;
}
void MainWindow::onGenerateButtonClicked() {
    int vertices = verticesSpinBox->value();
    int edges = edgesSpinBox->value();
    if (edges < vertices - 1 || edges > vertices * (vertices - 1) / 2) {
        QMessageBox::warning(this, "Ошибка", "Некорректное количество рёбер!");
        return;
    }
    graph = GraphGenerator::generateRandomGraph(vertices, edges);
    scene->clear();
    drawGraph();
}
void MainWindow::onColorButtonClicked() {
    if (graph.getVertices() == 0) {
        QMessageBox::warning(this, "Ошибка", "Сначала сгенерируйте граф!");
        return;
    }
    colors = GraphColoring::colorGraph(graph);
    scene->clear();
    drawGraph();
}
void MainWindow::onPentagramButtonClicked() {
    graph = GraphGenerator::generatePentagram();
    scene->clear();
    drawGraph();
}
void MainWindow::onCompleteGraphButtonClicked() {
    int vertices = verticesSpinBox->value();
    graph = GraphGenerator::generateCompleteGraph(vertices);
    scene->clear();
    drawGraph();
}
void MainWindow::onRingGraphButtonClicked() {
    int vertices = verticesSpinBox->value();
    graph = GraphGenerator::generateRingGraph(vertices);
    scene->clear();
    drawGraph();
}
void MainWindow::drawGraph() {
    drawEdges();
    drawVertices();
}
void MainWindow::drawVertices() {
    int vertices = graph.getVertices();
    float radius = 20.0f;

    for (int i = 0; i < vertices; ++i) {
        float angle = 2 * M_PI * i / vertices;
        float x = 400 + 200 * std::cos(angle) - radius;
        float y = 300 + 200 * std::sin(angle) - radius;
        QColor vertexColor = Qt::lightGray;
        if (i < colors.size()) {
            switch (colors[i] % 6) {
                case 0: vertexColor = Qt::red; break;
                case 1: vertexColor = Qt::green; break;
                case 2: vertexColor = Qt::blue; break;
                case 3: vertexColor = Qt::yellow; break;
                case 4: vertexColor = Qt::cyan; break;
                case 5: vertexColor = Qt::magenta; break;
            }
        }
        QGraphicsEllipseItem* vertex = scene->addEllipse(x, y, 2 * radius, 2 * radius, QPen(Qt::black), QBrush(vertexColor));
        QGraphicsTextItem* label = scene->addText(QString::number(i));
        label->setPos(x + radius - 5, y + radius - 10);
    }
}
void MainWindow::drawEdges() {
    for (int i = 0; i < graph.getVertices(); ++i) {
        for (int neighbor : graph.getAdjacencyList()[i]) {
            float angle1 = 2 * M_PI * i / graph.getVertices();
            float x1 = 400 + 200 * std::cos(angle1);
            float y1 = 300 + 200 * std::sin(angle1);

            float angle2 = 2 * M_PI * neighbor / graph.getVertices();
            float x2 = 400 + 200 * std::cos(angle2);
            float y2 = 300 + 200 * std::sin(angle2);
            scene->addLine(x1, y1, x2, y2, QPen(Qt::black));
        }
    }
}