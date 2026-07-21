#ifndef GRAPH_LOADER_HPP
#define GRAPH_LOADER_HPP

#include <string>
#include "graph.hpp"


enum class GraphLoadError {
    SUCCESS = 1,
    FILE_NOT_FOUND = -1,
    FILE_EMPTY = -2,
    MALFORMED_DATA = -3,
    INVALID_NEGATIVE_WEIGHT = -4
};

class GraphLoader {
public:
    static GraphLoadError loadFromEdgeList(const std::string& filename, Graph& graph);
};

#endif
