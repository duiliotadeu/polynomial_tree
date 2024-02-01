#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

#include "prografo.h"

int main(int argc, char* argv[]) {
    
    if (argc < 2) {
        printf("Erro: Insira pelo menos um argumento.\n");
        return 1;
    }

    char* file_name = prografo_reading_file_name();
    if (file_name == NULL) {
        return 1;
    }

    char* full_path = prografo_reading_file_path(file_name);
    free(file_name);
    if (full_path == NULL) {
        return 1;
    }

    graph_t* g = prografo_read_dimacs_file(full_path);
    free(full_path);
    if (g == NULL) {
        printf("Erro: Falha ao ler o grafo do arquivo.\n");
        return 1;
    }

    setlist_t* maximal_list;
    maximal_list = setlist_create(g->n);
    set_t maximum;
    maximum = set_new(g->n);

    FILE *arquivo;

    arquivo = fopen("saida.txt", "w");

    if (arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo.\n");
        return 1; 
    }

    if (strcmp(argv[1], "-a") == 0) {
        prografo_maximum(g, maximum);
        fprintf(arquivo, "A razao de independencia do grafo e %d/%d e um conjunto independente maximo e: ", set_size(maximum), set_size(g->valid_vertex));
        set_print_new(arquivo, maximum);
    } else if (strcmp(argv[1], "-b") == 0) {
        prografo_maximals(g, maximal_list, maximum);
        fprintf(arquivo, "A razao de independencia do grafo e %d/%d e os conjuntos independentes maximos sao: \n\n", set_size(maximum), set_size(g->valid_vertex));
        setlist_insertion_sort(maximal_list);
        setlist_print_max(arquivo, maximal_list, set_size(maximum));
    } else if (strcmp(argv[1], "-c") == 0) {
        prografo_maximals(g, maximal_list, maximum);
        fprintf(arquivo, "A razao de independencia do grafo e %d/%d e os conjuntos independentes maximais sao: \n\n", set_size(maximum), set_size(g->valid_vertex));
        setlist_insertion_sort(maximal_list);
        setlist_print(arquivo, maximal_list);
    } else {
        printf("Erro: Argumento invalido. Escolha -a, -b ou -c.\n");
        fclose(arquivo);
        graph_free(g);
        return 1;
    }
    
    graph_free(g);

    return 0;
}
