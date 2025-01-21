#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QSpinBox>
#include <QPushButton>
#include <QGraphicsView>
#include <QLabel>
#include "../include/Graph.h"
#include "../include/GraphGenerator.h"
#include "../include/GraphColoring.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    private slots:
        void onGenerateButtonClicked();
        void onColorButtonClicked();
        void onPentagramButtonClicked();
        void onCompleteGraphButtonClicked();
        void onRingGraphButtonClicked();

private:
    void drawGraph();
    void drawVertices();
    void drawEdges();

    QSpinBox* verticesSpinBox;
    QSpinBox* edgesSpinBox;
    QPushButton* generateButton;
    QPushButton* colorButton;
    QPushButton* pentagramButton;
    QPushButton* completeGraphButton;
    QPushButton* ringGraphButton;
    QGraphicsView* graphicsView;
    QGraphicsScene* scene;

    Graph graph;
    std::vector<int> colors;
};

#endif