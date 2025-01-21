#include "../include/GraphColoring.h"
#include <queue>
#include <algorithm>
std::vector<int> GraphColoring::colorGraph(const Graph& graph) {
    int vertices = graph.getVertices();
    std::vector<int> colors(vertices, -1);

    for (int i = 0; i < vertices; ++i) {
        std::vector<bool> availableColors(vertices, true);
        for (int neighbor : graph.getAdjacencyList()[i]) {
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

    return colors;
}
bool GraphColoring::isColoringValid(const Graph& graph, const std::vector<int>& colors) {
    for (int i = 0; i < graph.getVertices(); ++i) {
        for (int neighbor : graph.getAdjacencyList()[i]) {
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