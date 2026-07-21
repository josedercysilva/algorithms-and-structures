#include "GraphLoader.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

GraphLoadError GraphLoader::loadFromEdgeList(const std::string& filename, Graph& graph) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        return GraphLoadError::FILE_NOT_FOUND;
    }

    std::string line;
    int max_vertex_id = -1;
    bool has_data = false;

    struct TempEdge {
        int source;
        int target;
        double weight;
    };

    std::vector<TempEdge> temp_edges;

    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;

        std::istringstream iss(line);
        int u, v;
        double w;

        /*
         Nota: a condição do if usa stream extraction operator e significa em palavras: "Extraia o primeiro pedaço de dado de iss e salve na variável u. Depois, extraia o próximo pedaço e salve em v. Por fim, extraia o último pedaço e salve em w"
         */
        if (!(iss >> u >> v >> w)) {
            return GraphLoadError::MALFORMED_DATA;
        }


        if (w < 0.0) {
            return GraphLoadError::INVALID_NEGATIVE_WEIGHT;
        }

        temp_edges.push_back({u, v, w});
        max_vertex_id = std::max({max_vertex_id, u, v});
        has_data = true;
    }

    file.close();

    if (!has_data) {
        return GraphLoadError::FILE_EMPTY;
    }


    for (int i = 0; i <= max_vertex_id; ++i) {
        graph.addVertex(Vertex("Nó " + std::to_string(i), 0));
    }

    for (const auto& edge : temp_edges) {
        graph.addEdge(edge.source, edge.target, edge.weight);
    }

    return GraphLoadError::SUCCESS;
}
