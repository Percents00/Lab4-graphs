#include <QApplication>
#include "../include/GraphGenerator.h"
#include "../include/GraphColoring.h"
#include "../graphics/MainWindow.h"
#include <iostream>
#include "../tests/TestRunner.h"

int main(int argc, char *argv[]) {
    runTests();
    std::cout << "All tests passed! Starting GUI..." << std::endl;
    QApplication app(argc, argv);


    MainWindow mainWindow;
    mainWindow.setWindowTitle("Генератор графов");
    mainWindow.resize(800, 600);
    mainWindow.show();

    return app.exec();
}