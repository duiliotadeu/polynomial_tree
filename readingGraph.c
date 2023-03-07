#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

  fgets(Line, sizeof(Line), file);
  int num_vertex = atoi(Line);
  struct graph* graph = create_graph(num_vertex);

  i++;

  while (!feof(file))
  {
    result = fgets(Line, 1000, file);
    if (result && i > 0)
    {
      for (int j = 0; j < 1000; j++)
      {
        if (Line[j] == '1')
        {
          add_edge(graph, i, j);
        }
      } // Percorre as colunas
    }
    i++;
  } // Percorre as colunas do arquivo

  print_adj_list(graph);

  fclose(file);

  return;
} 

int main()
{
  readGraph();

  return 0;
}


// Referência: https://www.inf.pucrs.br/~pinho/LaproI/Arquivos/Arquivos.htm#Leitura