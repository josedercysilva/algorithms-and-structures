#include "dfs.hpp"
#include <stack>
#include <vector>
#include <iostream>

namespace Algorithms {

    void dfs(const Graph& graph, int startVertex)
    {

        int numVertices = graph.getVertexCount();

        if (startVertex < 0 || startVertex >= numVertices) {
            return;
        }

        std::vector<bool> descobertos(numVertices, false);
        std::stack<int> pilha;

        pilha.push(startVertex);

        std::cout << "\nIniciando Busca Em profundidade\n\n";

        while (!pilha.empty()) {
            int atual = pilha.top();
            pilha.pop();


            if (!descobertos[atual]) {
                descobertos[atual] = true;

                const Vertex& dados = graph.getVertexData(atual);
                std::cout << "Visitando ID: " << atual
                << " | Nome: " << dados.name << "\n";

                const auto& vizinhos = graph.getOutEdges(atual);

                for (auto it = vizinhos.rbegin(); it != vizinhos.rend(); ++it) {
                    if (!descobertos[it->targetId]) {
                        pilha.push(it->targetId);
                    }
                }
            }
        }

    }

}
