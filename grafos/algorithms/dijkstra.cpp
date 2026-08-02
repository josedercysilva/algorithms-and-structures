#include "dijkstra.hpp"
#include <queue>
#include <limits>
#include <iostream>
#include <algorithm>

namespace Algorithms {

    struct NodeRecord {
        double distancia;
        int id;
        bool operator>(const NodeRecord& outro) const
        {
            return this->distancia > outro.distancia;
        }
    };


    DijkstraResult dijkstra(const Graph& graph, int startVertex)
    {
        int numVertices = graph.getVertexCount();

        double infinito = std::numeric_limits<double>::infinity();
        std::vector<double> distancias(numVertices, infinito);
        std::vector<int> predecessores(numVertices, -1);

        if (startVertex < 0 || startVertex >= numVertices) {
            return {distancias, predecessores};
        }

        std::priority_queue<NodeRecord, std::vector<NodeRecord>, std::greater<NodeRecord>> filaPrioridade;

        distancias[startVertex] = 0.0;

        filaPrioridade.push({0.0, startVertex});

        std::cout << " Iniciando Dijkstra a partir do ID " << startVertex << " \n";

        while (!filaPrioridade.empty()) {

            NodeRecord registro = filaPrioridade.top();
            filaPrioridade.pop();

            if (registro.distancia > distancias[registro.id]) {
                continue;
            }

            const auto& vizinhos = graph.getOutEdges(registro.id);
            for (const auto& edge : vizinhos) {

                double novaDistancia = distancias[registro.id] + edge.weight;

                if (novaDistancia < distancias[edge.targetId]) {

                    distancias[edge.targetId] = novaDistancia;

                    predecessores[edge.targetId] = registro.id;

                    filaPrioridade.push({novaDistancia, edge.targetId});
                }
            }
        }

        std::cout << " Dijkstra Concluido \n\n";

        return {distancias, predecessores};
    }




    std::vector<int> reconstructPath(const std::vector<int>& predecessores, int targetVertex, int startVertex)
    {
        std::vector<int> path;

        bool foraDosLimites = targetVertex < 0 || targetVertex >= predecessores.size();
        if (foraDosLimites) {
            return path;
        }

        bool inalcancavel = (predecessores[targetVertex] == -1) && (targetVertex != startVertex);
        if (inalcancavel) {
            return path;
        }

        for (int at = targetVertex; at != -1; at = predecessores[at]) {
            path.push_back(at);
        }

        std::reverse(path.begin(), path.end());

        return path;
    }

}
