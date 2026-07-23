#include "bfs.hpp"
#include <queue>
#include <vector>
#include <iostream>

namespace Algorithms
{

    void bfs(const Graph& graph, int startVertex)
    {
        int numVertices = graph.getVertexCount();

        if (startVertex < 0 || startVertex >= numVertices) {
            return;
        }

        std::vector<bool> visitados(numVertices, false);

        std::queue<int> fila;

        visitados[startVertex] = true;
        fila.push(startVertex);



        while (!fila.empty()) {

            int atual = fila.front();
            fila.pop();

            const Vertex& dados = graph.getVertexData(atual);

            std::cout << "Visitando ID: " << atual
            << " | Nome: " << dados.name << "\n";

            const auto& vizinhos = graph.getOutEdges(atual);

            for (const auto& edge : vizinhos) {

                if (!visitados[edge.targetId]) {
                    visitados[edge.targetId] = true;
                    fila.push(edge.targetId);
                }
            }
        }

    }
}
