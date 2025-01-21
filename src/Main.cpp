#include <QApplication>
#include "../include/Graph.h"
#include "../include/GraphGenerator.h"
#include "../include/GraphColoring.h"
#include "../graphics/GraphVisualizer.h"
#include "../graphics/MainWindow.h"
#include <iostream>
#include "../tests/TestRunner.h"

int main(int argc, char *argv[]) {
    runTests();
    std::cout << "All tests passed! Starting GUI..." << std::endl;
    QApplication app(argc, argv);
    MainWindow window;
    window.setWindowTitle("Генератор графов");
    window.resize(800, 600);
    window.show();

    return app.exec();
}