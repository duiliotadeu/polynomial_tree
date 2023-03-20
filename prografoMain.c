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

int main() {
    char* fileName = reading();
    struct graph* graph = readGraph(fileName);
    free(fileName);
    print_adj_list(graph);
    return 0;
}