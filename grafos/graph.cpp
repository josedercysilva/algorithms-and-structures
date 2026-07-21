#include "graph.hpp"
#include <utility>
#include <iostream>
#include <algorithm>

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


    // Retorna true or false
    auto compareByWeight = [](const Edge& val, const Edge& element) {
        return val.weight < element.weight;
    };


    // outEdges
    Edge newOutEdge(targetId, weight);

    auto beginOutRange = outEdges[sourceId].begin();
    auto endOutRange   = outEdges[sourceId].end();

    auto outIt = std::upper_bound(beginOutRange, endOutRange, newOutEdge, compareByWeight);

    outEdges[sourceId].insert(outIt, newOutEdge);


    //inEdges
    Edge newInEdge(sourceId, weight);

    auto beginInRange = inEdges[targetId].begin();
    auto endInRange   = inEdges[targetId].end();

    auto inIt = std::upper_bound(beginInRange, endInRange, newInEdge, compareByWeight);

    inEdges[targetId].insert(inIt, newInEdge);


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






