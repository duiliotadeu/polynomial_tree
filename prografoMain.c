#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// #include "tree.h"
#include "graph.h"

char* reading() {
    char* fileName = malloc(sizeof(char) * 100);
    printf("Digite o nome do arquivo (max. 100 caracteres): ");
    fgets(fileName, 100, stdin);
    fileName[strcspn(fileName, "\n")] = '\0'; // Remove o caractere '\n' do final da string
    return fileName;
}

void maximals(struct graph* graph) {
    int vertex_index = adjacency_list_not_empty(graph);
    if (vertex_index != -1)
    {
        // Passo 1
        struct graph* graph_s1 = (struct graph*) malloc(sizeof(struct graph));
        copy_graph(graph, &graph_s1);
        delete_vertex(graph_s1, vertex_index);
        maximals(graph_s1);
        free(graph_s1);

        // Passo 2
        struct graph* graph_s2 = (struct graph*) malloc(sizeof(struct graph));
        copy_graph(graph, &graph_s2);
        delete_adj_vertex(graph_s2, vertex_index);
        maximals(graph_s2);
        free(graph_s2);
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