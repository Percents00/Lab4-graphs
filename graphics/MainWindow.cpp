#include "MainWindow.h"
#include "../include/DirectedGraph.h"
#include "../include/UndirectedGraph.h"
#include "../include/GraphGenerator.h"
#include "../include/GraphColoring.h"
#include "GraphRenderer.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QGraphicsView>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), graph(nullptr) {
    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);

    // Настройка элементов управления
    QHBoxLayout* inputLayout = new QHBoxLayout();
    verticesSpinBox = new QSpinBox(this);
    verticesSpinBox->setRange(1, 100);
    verticesSpinBox->setValue(5);
    inputLayout->addWidget(new QLabel("Вершины:"));
    inputLayout->addWidget(verticesSpinBox);

    edgesSpinBox = new QSpinBox(this);
    edgesSpinBox->setRange(1, 1000);
    edgesSpinBox->setValue(7);
    inputLayout->addWidget(new QLabel("Рёбра:"));
    inputLayout->addWidget(edgesSpinBox);

    graphTypeComboBox = new QComboBox(this);
    graphTypeComboBox->addItem("Неориентированный");
    graphTypeComboBox->addItem("Ориентированный");
    inputLayout->addWidget(graphTypeComboBox);

    generateButton = new QPushButton("Сгенерировать", this);
    inputLayout->addWidget(generateButton);

    colorButton = new QPushButton("Раскрасить", this);
    inputLayout->addWidget(colorButton);

    pentagramButton = new QPushButton("Пентаграмма", this);
    inputLayout->addWidget(pentagramButton);

    completeGraphButton = new QPushButton("Полный граф", this);
    inputLayout->addWidget(completeGraphButton);

    ringGraphButton = new QPushButton("Кольцо", this);
    inputLayout->addWidget(ringGraphButton);

    mainLayout->addLayout(inputLayout);

    scene = new QGraphicsScene(this);
    graphicsView = new QGraphicsView(scene, this);
    graphicsView->setRenderHint(QPainter::Antialiasing);
    mainLayout->addWidget(graphicsView);

    connect(generateButton, &QPushButton::clicked, this, &MainWindow::onGenerateButtonClicked);
    connect(colorButton, &QPushButton::clicked, this, &MainWindow::onColorButtonClicked);
    connect(pentagramButton, &QPushButton::clicked, this, &MainWindow::onPentagramButtonClicked);
    connect(completeGraphButton, &QPushButton::clicked, this, &MainWindow::onCompleteGraphButtonClicked);
    connect(ringGraphButton, &QPushButton::clicked, this, &MainWindow::onRingGraphButtonClicked);

    scene->setSceneRect(0, 0, 800, 600);
    graphicsView->setFixedSize(800, 600);

    setWindowTitle("Графы");
    resize(800, 600);
}

MainWindow::~MainWindow() {
    delete scene;
    delete graph;
}

void MainWindow::onGenerateButtonClicked() {
    const int vertices = verticesSpinBox->value();
    const int edges = edgesSpinBox->value();
    const bool isDirected = (graphTypeComboBox->currentIndex() == 1);

    const int maxEdges = isDirected ? vertices * (vertices - 1) : vertices * (vertices - 1) / 2;
    if (edges < vertices - 1 || edges > maxEdges) {
        QMessageBox::warning(this, "Ошибка", "Некорректное количество рёбер!");
        return;
    }

    delete graph;
    graph = GraphGenerator::generateRandomGraph(vertices, edges, isDirected);
    drawGraph();
}

void MainWindow::onColorButtonClicked() {
    if (!graph || graph->getVertices().empty()) {
        QMessageBox::warning(this, "Ошибка", "Сначала сгенерируйте граф!");
        return;
    }

    if (graph->isDirected()) {
        QMessageBox::warning(this, "Ошибка", "Раскраска только для неориентированных графов!");
        return;
    }

    colors = GraphColoring::colorGraph(dynamic_cast<const UndirectedGraph<int, int>&>(*graph));
    drawGraph();
    scene->update();
}

void MainWindow::onPentagramButtonClicked() {
    delete graph;
    graph = GraphGenerator::generatePentagram();
    if (!graph) {
        QMessageBox::critical(this, "Ошибка", "Не удалось создать пентаграмму!");
        return;
    }
    drawGraph();
}

void MainWindow::onCompleteGraphButtonClicked() {
    const int vertices = verticesSpinBox->value();
    const bool isDirected = (graphTypeComboBox->currentIndex() == 1);
    delete graph;
    graph = GraphGenerator::generateCompleteGraph(vertices, isDirected);
    drawGraph();
}

void MainWindow::onRingGraphButtonClicked() {
    const int vertices = verticesSpinBox->value();
    const bool isDirected = (graphTypeComboBox->currentIndex() == 1);
    delete graph;
    graph = GraphGenerator::generateRingGraph(vertices, isDirected);
    drawGraph();
}

void MainWindow::drawGraph() {
    if (!graph) return;
    scene->clear();
    GraphRenderer renderer(scene);
    renderer.renderGraph(graph, colors);
}
