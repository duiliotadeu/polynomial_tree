#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// #include "tree.h"
#include "graph.h"

int main() {
    int num_vertex = 6;
    struct graph* graph = create_graph(num_vertex);

    // Adicionando arestas ao grafo
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 4);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 1, 4);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);
    add_edge(graph, 4, 5);

    // Imprimindo a lista de adjacência do grafo
    print_adj_list(graph);

    return 0;
}