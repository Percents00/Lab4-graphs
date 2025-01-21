#include "../include/Graph.h"
#include "../include/GraphColoring.h"
#include "../include/GraphGenerator.h"
#include <cassert>
#include <iostream>
#include <algorithm>

void testGraph() {
    Graph graph(5, false);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 0);

    assert(graph.hasEdge(0, 1) == true);
    assert(graph.hasEdge(1, 0) == true);
    assert(graph.hasEdge(0, 2) == false);
    graph.removeEdge(0, 1);
    assert(graph.hasEdge(0, 1) == false);
    assert(graph.hasEdge(1, 0) == false);
    assert(graph.isConnected() == true);

    graph.removeEdge(2, 3);
    assert(graph.isConnected() == false);

    std::cout << "All Graph tests passed!" << std::endl;
}
void testGraphColoring() {
    Graph graph = GraphGenerator::generateRingGraph(4);
    std::vector<int> colors = GraphColoring::colorGraph(graph);
    assert(GraphColoring::isColoringValid(graph, colors) == true);
    int maxColor = *std::max_element(colors.begin(), colors.end());
    assert(maxColor <= 1);

    std::cout << "All GraphColoring tests passed!" << std::endl;
}
void testGraphGenerator() {
    Graph completeGraph = GraphGenerator::generateCompleteGraph(5);
    assert(completeGraph.getVertices() == 5);
    assert(completeGraph.isConnected() == true);
    Graph ringGraph = GraphGenerator::generateRingGraph(5);
    assert(ringGraph.getVertices() == 5);
    assert(ringGraph.isConnected() == true);
    Graph randomGraph = GraphGenerator::generateRandomGraph(10, 15);
    assert(randomGraph.getVertices() == 10);

    std::cout << "All GraphGenerator tests passed!" << std::endl;
}