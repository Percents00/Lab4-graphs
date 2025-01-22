#include "TestRunner.h"
#include "../include/DirectedGraph.h"
#include "../include/UndirectedGraph.h"
#include "../include/GraphColoring.h"
#include "../include/GraphGenerator.h"
#include <cassert>
#include <iostream>

void testGraphGenerator() {
    IGraph<int, int>* directedGraph = GraphGenerator::generateRandomGraph(5, 7, true);
    std::cout << "Vertices count: " << directedGraph->getVerticesCount() << std::endl;
    assert(directedGraph->getVerticesCount() == 5);
    delete directedGraph;

    std::cout << "All GraphGenerator tests passed!" << std::endl;
}


void testUndirectedGraph() {
    UndirectedGraph<int, int> graph;

    graph.addVertex(0);
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addEdge(0, 1, 10);
    graph.addEdge(1, 2, 20);

    assert(graph.getVerticesCount() == 3);
    assert(graph.hasEdge(0, 1) == true);
    assert(graph.hasEdge(1, 0) == true);
    assert(graph.hasEdge(0, 2) == false);

    graph.removeEdge(0, 1);
    assert(graph.hasEdge(0, 1) == false);
    assert(graph.hasEdge(1, 0) == false);

    std::vector<int> neighbors = graph.getNeighbors(1);
    assert(neighbors.size() == 1);
    assert(neighbors[0] == 2);

    std::cout << "All UndirectedGraph tests passed!" << std::endl;
}

void testDirectedGraph() {
    DirectedGraph<int, int> graph;

    graph.addVertex(0);
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addEdge(0, 1, 10);
    graph.addEdge(1, 2, 20);

    assert(graph.getVerticesCount() == 3);
    assert(graph.hasEdge(0, 1) == true);
    assert(graph.hasEdge(1, 0) == false);
    assert(graph.hasEdge(0, 2) == false);

    graph.removeEdge(0, 1);
    assert(graph.hasEdge(0, 1) == false);

    std::vector<int> neighbors = graph.getNeighbors(1);
    assert(neighbors.size() == 1);
    assert(neighbors[0] == 2);

    std::cout << "All DirectedGraph tests passed!" << std::endl;
}

void testGraphColoring() {
    UndirectedGraph<int, int> undirectedGraph;
    undirectedGraph.addVertex(0);
    undirectedGraph.addVertex(1);
    undirectedGraph.addVertex(2);
    undirectedGraph.addEdge(0, 1, 0);
    undirectedGraph.addEdge(1, 2, 0);
    undirectedGraph.addEdge(2, 0, 0);

    std::vector<int> colors = GraphColoring::colorGraph(undirectedGraph);
    assert(GraphColoring::isColoringValid(undirectedGraph, colors) == true);

    std::cout << "All GraphColoring tests passed!" << std::endl;
}


void runTests() {
    std::cout << "Running tests..." << std::endl;
    testGraphGenerator();
    testUndirectedGraph();
    testDirectedGraph();
    testGraphColoring();
    std::cout << "All tests passed!" << std::endl;
}