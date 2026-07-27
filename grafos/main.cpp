#include <iostream>
#include "core/graph.hpp"
#include "io/GraphLoader.hpp"
#include "algorithms/bfs.hpp"
#include "algorithms/dfs.hpp"

int main()
{
    Graph meu_grafo;

    GraphLoadError status = GraphLoader::loadFromEdgeList("data/exemplo3_ciclico.edges", meu_grafo);

    if (status != GraphLoadError::SUCCESS) {
        return 1;
    }

    Algorithms::bfs(meu_grafo, 1);
    Algorithms::dfs(meu_grafo, 1);

    return 0;
}
