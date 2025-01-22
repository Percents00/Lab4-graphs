#include "../include/GraphColoring.h"
#include <queue>
#include <algorithm>
#include <iostream>

std::vector<int> GraphColoring::colorGraph(const UndirectedGraph<int, int>& graph) {
    int vertices = graph.getVertices().size();
    std::vector<int> colors(vertices, -1);

    for (int i = 0; i < vertices; ++i) {
        std::vector<bool> availableColors(vertices, true);
        for (int neighbor : graph.getNeighbors(i)) {
            if (colors[neighbor] != -1) {
                availableColors[colors[neighbor]] = false;
            }
        }
        for (int color = 0; color < vertices; ++color) {
            if (availableColors[color]) {
                colors[i] = color;
                break;
            }
        }
    }

    std::cout << "Colors assigned: ";
    for (int c : colors) std::cout << c << " ";
    std::cout << std::endl;

    return colors;
}

bool GraphColoring::isColoringValid(const UndirectedGraph<int, int>& graph, const std::vector<int>& colors) {
    for (int i = 0; i < graph.getVerticesCount(); ++i) {
        for (int neighbor : graph.getNeighbors(i)) {
            if (colors[i] == colors[neighbor]) {
                return false;
            }
        }
    }
    return true;
}

void GraphColoring::printColoring(const std::vector<int>& colors) {
    std::cout << "Graph coloring:" << std::endl;
    for (size_t i = 0; i < colors.size(); ++i) {
        std::cout << "Vertex " << i << " has color " << colors[i] << std::endl;
    }
}