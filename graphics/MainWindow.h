#pragma once

#include <QMainWindow>
#include <QGraphicsScene>
#include <QSpinBox>
#include <QPushButton>
#include <QComboBox>
#include "../include/IGraph.h"

class QGraphicsView;

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
    std::vector<int> colors;
    QSpinBox* verticesSpinBox;
    QSpinBox* edgesSpinBox;
    QPushButton* generateButton;
    QPushButton* colorButton;
    QPushButton* pentagramButton;
    QPushButton* completeGraphButton;
    QPushButton* ringGraphButton;
    QComboBox* graphTypeComboBox;
    QGraphicsView* graphicsView;
    QGraphicsScene* scene;

    IGraph<int, int>* graph;
};
