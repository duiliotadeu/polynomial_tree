#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

struct graph* readGraph(char fileN) {
  FILE *file;
  char Line[1000];
  char *result;
  int i;

  char fileName[] = "./novos_exemplos/";
  char str[] = ".txt";
    
  strcat(fileName, fileN);
  strcat(fileName, str);

  // Abre um arquivo TEXTO para LEITURA
  file = fopen(fileName, "rt");
  if (file == NULL)  // Se houve erro na abertura
  {
     printf("Problemas na abertura do arquivo\n");
     return 0;
  }

  i = 0;

  // Lê o número de vértices do grafo da primeira linha do arquivo e gera o grafo.
  result = fgets(Line, 1000, file);
  int num_vertex = atoi(Line);
  struct graph* graph = create_graph(num_vertex);
  if (graph == NULL)  // Se houve erro na abertura
  {
     printf("Não foi possível gerar o grafo\n");
     return 0;
  }

  i++;

  // Percorre as demais linhas do arquivo incluindo as conexões nos vertices existentes.
  while (!feof(file))
  {
      result = fgets(Line, 1000, file);
      if (result)
      {
        int col = 0;
        for(int j = 0; Line[j] != '\0'; j++) 
        {
          if(Line[j] == '1')
          {
            int k = i-1;
            add_edge(graph, k, col);
          }
          if(Line[j] == '0' || Line[j] == '1')
            col++;
        }
      }
      i++;
  }

  fclose(file);
  return graph;
}


// Referência: https://www.inf.pucrs.br/~pinho/LaproI/Arquivos/Arquivos.htm#Leitura