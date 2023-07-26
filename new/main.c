#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graph.h"
#include "setlist.h"

// Criar função para percorrer o setlist e determinar os conjuntos máximos.

setlist_t* maximal_list;
set_t biggest_maximal;


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

void graph_delete_edges(graph_t *g, int v) {
    int i;
    
    for (i = 0; i < g->n; i++) {
        if (i != v) {
            GRAPH_DEL_EDGE(g, i, v);
        }
    }
}

void graph_delete_neighbors_edges(graph_t *g, int v) {
    set_t edges = g->edges[v];
    for (int i = 0; i < g->n; i++) {
        if (SET_CONTAINS(edges, i)) {
            graph_delete_edges(g, i);
            SET_DEL_ELEMENT(g->valid_vertex, i);
        }
    }
}

void graph_maximals(graph_t *g) {
    int vertex = graph_find_vertex_with_max_edges(g);

    if (set_size(g->valid_vertex) < set_size(biggest_maximal))
    {
        return;
    }
    
    if (!graph_is_empty(g)) {
        // Passo 1
        graph_t *g1 = graph_copy(g);
        graph_delete_neighbors_edges(g1, vertex);
        graph_maximals(g1);
        graph_free(g1);

        // Passo 2
        for (int i = 0; i < g->n; i++) {
            graph_t *g2 = graph_copy(g);
            if (SET_CONTAINS(g2->edges[vertex], i)) {
                graph_delete_neighbors_edges(g2, i);
                graph_maximals(g2);
            }
            graph_free(g2);
        }
    } else {
        if (set_size(g->valid_vertex) > set_size(biggest_maximal))
        {
           biggest_maximal = set_copy(NULL, g->valid_vertex);
            if (!setlist_exists_list(maximal_list, g))
            {
                setlist_add_element(maximal_list, g);
                set_print_maximal(g->valid_vertex);
            }
        }
    }
}

char* graph_reading_file_name() {
    char* fileName = malloc(sizeof(char) * 100);
    printf("Digite o nome do arquivo (max. 100 caracteres): ");
    fgets(fileName, 100, stdin);
    fileName[strcspn(fileName, "\n")] = '\0'; // Remove o caractere '\n' do final da string
    return fileName;
}

char* graph_reading_file_path(const char* file_name) {
    const char* file_path = "./examples/";
    char* full_path = malloc(strlen(file_path) + strlen(file_name) + 1);

    strcpy(full_path, file_path);
    strcat(full_path, file_name);
    
    return full_path;
}

int main () {
    char* file_name = graph_reading_file_name();
    char* full_path = graph_reading_file_path(file_name);

    graph_t *g = graph_read_dimacs_file(full_path);
    maximal_list = setlist_create(g->n);
    biggest_maximal = set_new(g->n);

    graph_print(g);
    printf("\n\n");

    graph_maximals(g);

    printf("\n\n Maior: ");
    set_print(biggest_maximal);

    graph_free(g);

    return 0;
}
