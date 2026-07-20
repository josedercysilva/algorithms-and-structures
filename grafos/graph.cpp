#include "graph.hpp"
#include <utility>
#include <iostream>

Graph::Graph() = default;


int Graph::addVertex(Vertex v)
{
    int id = vertices.size();

    //std::move serve apenas para o C++ não fazer uma cópia e sim pegar o original.
    //O dado v é passado para o proximo "dono"
    vertices.push_back(std::move(v));

    outEdges.emplace_back();
    inEdges.emplace_back();

    return id;
}

int Graph::addEdge(int sourceId, int targetId, double weight)
{
    if (sourceId < 0 || sourceId >= outEdges.size()) return -1;
    if (targetId < 0 || targetId >= inEdges.size())  return -2;
    if (weight <= 0.0) return -3;

    if (sourceId == targetId) return -4;


    for (const auto& edge : outEdges[sourceId]) {
        if (edge.targetId == targetId) {
            std::cerr << " Erro Edge from " << sourceId <<
            " to " << targetId << "already exists. \n";
            return -5;
        }
    }

    outEdges[sourceId].emplace_back(targetId, weight);
    inEdges[targetId].emplace_back(sourceId, weight);

    return 1;
}

const std::vector<Edge>& Graph::getOutEdges(int vertexId) const
{
    return outEdges[vertexId];
}

const std::vector<Edge>& Graph::getInEdges(int vertexId) const
{
    return inEdges[vertexId];
}

const Vertex& Graph::getVertexData(int vertexId) const
{
    return vertices[vertexId];
}






