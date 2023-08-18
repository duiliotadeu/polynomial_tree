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
    struct graph* graph_s1 = (struct graph*) malloc(sizeof(struct graph));
    copy_graph(graph, &graph_s1);
    delete_vertex(graph_s1, empty);
    deallocate_graph(graph_s1);

    print_adj_list(graph_s1);
}

int main() {
    char* fileName = reading();
    struct graph* graph = readGraph(fileName);
    free(fileName);
    maximals(graph);
    return 0;
}