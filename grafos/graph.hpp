#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "edge.hpp"
#include "vertex.hpp"

class Graph {
private:
    std::vector<Vertex> vertices;
    std::vector<std::vector<Edge>> outEdges;
    std::vector<std::vector<Edge>> inEdges;

public:
    Graph();

    int addVertex(Vertex v);
    int addEdge(int sourceId, int targetId, double weight);

    const std::vector<Edge>& getOutEdges(int vertexId) const;
    const std::vector<Edge>& getInEdges(int vertexId) const;

    const Vertex& getVertexData(int vertexId) const;
};

#endif
