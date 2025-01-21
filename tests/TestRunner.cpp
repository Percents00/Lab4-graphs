#include "TestRunner.h"
#include <iostream>
void testGraph();
void testGraphColoring();
void testGraphGenerator();

void runTests() {
    std::cout << "Running tests..." << std::endl;
    testGraph();
    testGraphColoring();
    testGraphGenerator();

    std::cout << "All tests passed!" << std::endl;
}