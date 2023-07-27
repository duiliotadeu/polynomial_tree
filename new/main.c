#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graph.h"
#include "setlist.h"

setlist_t* maximal_list;
set_t biggest_maximal;

// Pendências:
//      Resolver problema de consumo de RAM.
//      Isolar a biblioteca do cliquer.
//      Melhorar a modularização.
//      Documentar testes.

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
        if (new_graph->edges[i] == NULL) {
            printf("Erro: Falha na alocacao de memoria em graph_copy (aresta %d).\n", i);
            graph_free(new_graph);
            return NULL;
        }
    }

    new_graph->valid_vertex = set_copy(NULL, graph->valid_vertex);
    if (new_graph->valid_vertex == NULL) {
        printf("Erro: Falha na alocacao de memoria em graph_copy (vertices validos).\n");
        graph_free(new_graph);
        return NULL;
    }

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
    if (g == NULL) {
        printf("Erro: Ponteiro de grafo NULL em graph_maximals.\n");
        return;
    }

    int vertex = graph_find_vertex_with_max_edges(g);
    
    if (!graph_is_empty(g)) {
        graph_t *g1 = graph_copy(g);
        graph_delete_neighbors_edges(g1, vertex);
        graph_maximals(g1);
        graph_free(g1);

        for (int i = 0; i < g->n; i++) {
            graph_t *g2 = graph_copy(g);
            if (SET_CONTAINS(g2->edges[vertex], i)) {
                graph_delete_neighbors_edges(g2, i);
                graph_maximals(g2);
            }
            graph_free(g2);
        }
    } else {
        if (set_size(g->valid_vertex) > set_size(biggest_maximal)) {
            biggest_maximal = set_copy(NULL, g->valid_vertex); 
            if (!setlist_exists_list(maximal_list, g)) {
                setlist_add_element(maximal_list, g);
            }
        }
    }
}

char* graph_reading_file_name() {
    char* fileName = malloc(sizeof(char) * 100);
    if (fileName == NULL) {
        printf("Erro: Falha na alocacao de memoria em graph_reading_file_name.\n");
        return NULL;
    }

    printf("Digite o nome do arquivo (max. 100 caracteres): ");
    fgets(fileName, 100, stdin);
    fileName[strcspn(fileName, "\n")] = '\0'; 
    return fileName;
}

char* graph_reading_file_path(const char* file_name) {
    const char* file_path = "./examples/";
    char* full_path = malloc(strlen(file_path) + strlen(file_name) + 1);

    if (full_path == NULL) {
        printf("Erro: Falha na alocacao de memoria em graph_reading_file_path.\n");
        return NULL;
    }

    strcpy(full_path, file_path);
    strcat(full_path, file_name);
    
    return full_path;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Erro: Insira pelo menos um argumento.\n");
        return 1;
    }

    char* file_name = graph_reading_file_name();
    if (file_name == NULL) {
        return 1;
    }

    char* full_path = graph_reading_file_path(file_name);
    free(file_name);
    if (full_path == NULL) {
        return 1;
    }

    graph_t* g = graph_read_dimacs_file(full_path);
    free(full_path);
    if (g == NULL) {
        printf("Erro: Falha ao ler o grafo do arquivo.\n");
        return 1;
    }

    maximal_list = setlist_create(g->n);
    biggest_maximal = set_new(g->n);

    graph_maximals(g);
    graph_free(g);

    if (strcmp(argv[1], "-a") == 0) {
        printf("A razao de independencia do grafo e %d/%d e um conjunto independente maximo e: ", set_size(biggest_maximal), set_size(g->valid_vertex));
        set_print_new(biggest_maximal);
    } else if (strcmp(argv[1], "-b") == 0) {
        printf("A razao de independencia do grafo e %d/%d e os conjuntos independentes maximos sao: \n\n", set_size(biggest_maximal), set_size(g->valid_vertex));
        setlist_print(maximal_list);
    } else {
        printf("Erro: Argumento invalido. Escolha -a ou -b.\n");
        return 1;
    }

    return 0;
}
