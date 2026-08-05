# Algoritmos e Estruturas de Dados Base

Repositório de treinamento contínuo focado na implementação de estruturas de dados e algoritmos fundamentais. O objetivo é consolidar a base teórica de ciência da computação através de código C++ moderno e otimizado.

## Escopo Implementado

* **Teoria dos Grafos:**
  * Representação modular via Listas de Adjacência.
  * Busca em Largura, BFS.
  * Busca em Profundidade, DFS.
  * Roteamento de Caminho Mínimo, Dijkstra.
  * Ordenação Topológica.
* **Árvores de Busca:**
  * B-Tree.

## Arquitetura e Decisões Técnicas

O código prioriza a alocação eficiente de memória e o desacoplamento de responsabilidades lógicas.

* **C++ Moderno e STL:** Utilização de `std::move` para transferência de posse sem cópias espúrias na memória, funções lambda para ordenação customizada e tipagem forte via `enum class`.
* **Gestão de Memória:** Foco em manter as estruturas de dados densas e contíguas na RAM, minimizando *Cache Misses* durante a travessia de grandes volumes de vértices.
* **Modularização Estrita:** A lógica matemática de roteamento e busca é isolada no `namespace Algorithms`, separada do núcleo estrutural (Grafos/Vértices/Arestas) e do motor de parsing de arquivos (I/O).

## Estrutura de Diretórios

- grafos/
  - algorithms/ # Algoritmos de busca e roteamento (BFS, DFS, Dijkstra)
  - core/       # Estruturas base (Graph, Vertex, Edge)
  - data/       # Datasets contendo listas de arestas (.edges) para testes
  - io/         # Validação e carregamento de arquivos com tratamento estrito de erros
  - main.cpp    # Ponto de entrada e orquestração de testes

## Compilação e Uso

O projeto utiliza a biblioteca padrão do C++ e não possui dependências externas. Para compilar o módulo de grafos, execute na raiz do diretório `grafos`:

```bash
g++ main.cpp core/*.cpp algorithms/*.cpp io/*.cpp -std=c++17 -o grafos_exec
./grafos_exec
