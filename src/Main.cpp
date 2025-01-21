#include <QApplication>
#include "../include/Graph.h"
#include "../include/GraphGenerator.h"
#include "../include/GraphColoring.h"
#include "../graphics/GraphVisualizer.h"
#include "../include/Chronometer.h"
#include <iostream>
#include "../graphics/MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow window;
    window.setWindowTitle("Генератор графов");
    window.resize(800, 600);
    window.show();

    return app.exec();
}