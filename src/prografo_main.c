#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

#include "include/prografo.h"

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

    run_prografo(argv[1], full_path);

    return 0;
}
