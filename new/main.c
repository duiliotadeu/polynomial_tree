#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "setlist.h"

setlist_t* maximal_list;

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

    new_graph->valid_vertex = set_copy(NULL, graph->valid_vertex);
    
    // for (int i = 0; i < graph->n; i++) {
    //     new_graph->weights[i] = graph->weights[i];

    return new_graph;
}

void delete_edges(graph_t *g, int v) {
    int i;
    
    for (i = 0; i < g->n; i++) {
        if (i != v) {
            GRAPH_DEL_EDGE(g, i, v);
        }
    }
}

void delete_neighbors_edges(graph_t *g, int v) {
    set_t edges = g->edges[v];
    for (int i = 0; i < g->n; i++) {
        if (SET_CONTAINS(edges, i)) {
            delete_edges(g, i);
            SET_DEL_ELEMENT(g->valid_vertex, i);
        }
    }
}

void maximals(graph_t *g) {
    int vertex = graph_find_vertex_with_max_edges(g);
    
    if (!graph_is_empty(g)) {
        // Passo 1
        graph_t *g1 = graph_copy(g);
        delete_neighbors_edges(g1, vertex);
        maximals(g1);
        graph_free(g1);

        // Passo 2
        for (int i = 0; i < g->n; i++) {
            graph_t *g2 = graph_copy(g);
            if (SET_CONTAINS(g2->edges[vertex], i)) {
                delete_neighbors_edges(g2, i);
                maximals(g2);
            }
            graph_free(g2);
        }
    } else {
        if (!isVertexListInSetList(maximal_list, g))
        {
            addToSetList(maximal_list, g);
            graph_print(g);
        }
    }
}

int main () {
    maximal_list = setlist_create();
    graph_t *g = graph_read_dimacs_file("ex1_new.col");
    maximals(g);
    graph_free(g);

    return 0;
}
