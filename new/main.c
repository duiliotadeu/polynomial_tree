#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

// Entender a alocação do grafo; X
// Entender a estrutura de dados do grafo; X
// Entender a estrutura de dados dos sets; X

int graph_find_vertex_with_max_edges(graph_t* graph) {
    int max_edges = 0;
    int max_vertex = -1;

    for (int i = 0; i < graph->n; i++) {
        int num_edges = graph_vertex_degree(graph, i);
        if (num_edges > max_edges) {
            max_edges = num_edges;
            max_vertex = i;
        }
    }

    return max_vertex;
}

boolean graph_is_empty(graph_t* graph) {
    return (graph_edge_count(graph) == 0);
}


graph_t* graph_copy(graph_t* graph) {
    graph_t* new_graph = graph_new(graph->n); 
    
    for (int i = 0; i < graph->n; i++) {
        new_graph->edges[i] = set_copy(NULL, graph->edges[i]);
    }
    
    // for (int i = 0; i < graph->n; i++) {
    //     new_graph->weights[i] = graph->weights[i];
    // }
    
    return new_graph;
}

void graph_delete_edges_of_vertex(graph_t *g, int v) {
    int i;
    set_t *edges_v = g->edges[v];
    // WARNING: Tipos incompatíveis?
}


int main () {
    graph_t *g = graph_read_dimacs_file("ex1_new.col");
    int vertex = graph_find_vertex_with_max_edges(g);

    if (!graph_is_empty(g))
    {
        // Passo 1
        graph_t *g1 = graph_copy(g);
        graph_print(g1);
    }
    

    graph_free(g);

    return 0;
}
