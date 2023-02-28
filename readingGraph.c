#include <stdio.h>
#include <stdlib.h>
#include <gconio.h>
#include "graph.h"

// Já é possível abrir o arquivo e ler o número de vértices.

void readGraph(/* Passar o nome do arquivo por parâmetro*/) {
  FILE *file;
  char Line[1000];
  char *result;
  int i;
  clrscr();

  // Abre um arquivo TEXTO para LEITURA
  file = fopen("./novos_exemplos/ex1.txt", "rt");
  if (file == NULL)  // Se houve erro na abertura
  {
     printf("Problemas na abertura do arquivo\n");
     return;
  }

  i = 0;

  while (!feof(file))
  {
	// Lê uma linha (inclusive com o '\n')
      result = fgets(Line, 1000, file);  // o 'fgets' lê até 999 caracteres ou até o '\n'
      if (result)
        if (i == 0) { // Se foi possível ler
          int num_vertex = atoi(Line);
          printf("%d\n", num_vertex);
	        // printf("Line %d : %s",i,Line);
        }
      i++;
  }

  fclose(file);
}

void main()
{
  readGraph();
}


// Referência: https://www.inf.pucrs.br/~pinho/LaproI/Arquivos/Arquivos.htm#Leitura