#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Como os grafos que utilizaremos são esparsos, a estrutura utilizada é a da Lista de Adjacência.

// Definindo a estrutura do nó da lista de vizinhos
struct neighbor {
    int vertex_index;
    struct neighbor* next;
};

// Definindo a estrutura do nó da lista de adjacência
struct vertex {
    struct neighbor* neighbors;
};

// Definindo a estrutura do grafo
struct graph {
    int num_vertex;
    struct vertex* vertex;
};

// Função para criar um grafo vazio
struct graph* create_graph(int num_vertex) {
    struct graph* graph = (struct graph*) malloc(sizeof(struct graph));
    graph->num_vertex = num_vertex;
    graph->vertex = (struct vertex*) malloc(num_vertex * sizeof(struct vertex));
    for (int i = 0; i < num_vertex; i++) {
        graph->vertex[i].neighbors = NULL;
    }
    return graph;
}

void add_edge(struct graph* graph, int vertex1, int vertex2) {
    // Adicionando vertex2 na lista de vizinhos de vertex1
    struct neighbor* new_neighbor = (struct neighbor*) malloc(sizeof(struct neighbor));
    new_neighbor->vertex_index = vertex2;
    new_neighbor->next = graph->vertex[vertex1].neighbors;
    graph->vertex[vertex1].neighbors = new_neighbor;

    // Adicionando vertex1 na lista de vizinhos de vertex2 (considerando que o grafo não é direcionado)
    new_neighbor = (struct neighbor*) malloc(sizeof(struct neighbor));
    new_neighbor->vertex_index = vertex1;
    new_neighbor->next = graph->vertex[vertex2].neighbors;
    graph->vertex[vertex2].neighbors = new_neighbor;
}

// Função para imprimir a lista de adjacência do grafo
void print_adj_list(struct graph* graph) {
    int i;
    for (i = 0; i < graph->num_vertex; i++) {
        struct neighbor* cur_neighbor = graph->vertex[i].neighbors;
        printf("Vertex %d: ", i);
        while (cur_neighbor != NULL) {
            printf("%d ", cur_neighbor->vertex_index);
            cur_neighbor = cur_neighbor->next;
        }
        printf("\n");
    }
}