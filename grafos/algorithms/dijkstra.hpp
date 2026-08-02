#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include <vector>
#include "../core/graph.hpp"

namespace Algorithms {

    struct DijkstraResult {
        std::vector<double> distancias;
        std::vector<int> predecessores;
    };

    DijkstraResult dijkstra(const Graph& graph, int startVertex);

    std::vector<int> reconstructPath(const std::vector<int>& predecessores, int targetVertex, int startVertex);

}

#endif
