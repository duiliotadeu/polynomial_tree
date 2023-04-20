#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "graph.h"

char* reading() {
    char* fileName = malloc(sizeof(char) * 100);
    printf("Digite o nome do arquivo (max. 100 caracteres): ");
    fgets(fileName, 100, stdin);
    fileName[strcspn(fileName, "\n")] = '\0'; // Remove o caractere '\n' do final da string
    return fileName;
}

void maximals(struct graph* graph) {
    int empty = adjacency_list_not_empty(graph);
    int vertex_index = vertex_with_most_neighbors(graph);
    if (empty != -1)
    {
        // Passo 1
        struct graph* graph_s1 = (struct graph*) malloc(sizeof(struct graph));
        copy_graph(graph, &graph_s1);
        delete_adj_vertex(graph_s1, vertex_index);
        maximals(graph_s1);
        deallocate_graph(graph_s1);

        // Passo 2 até k+1
        struct neighbor* current_neighbor = graph->vertex[vertex_index].neighbors;
        while (current_neighbor != NULL) {
            struct graph* graph_sk = (struct graph*) malloc(sizeof(struct graph));
            copy_graph(graph, &graph_sk);
            delete_adj_vertex(graph_sk, current_neighbor->vertex_index);
            delete_vertex(graph_sk, vertex_index);
            maximals(graph_sk);
            deallocate_graph(graph_sk);
            current_neighbor = current_neighbor->next;
        }
    } else
    {
        print_adj_list(graph);
    }
}

int main() {
    char* fileName = reading();
    struct graph* graph = readGraph(fileName);
    free(fileName);
    maximals(graph);
    return 0;
}