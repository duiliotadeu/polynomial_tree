#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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
    /*new_neighbor = (struct neighbor*) malloc(sizeof(struct neighbor));
    new_neighbor->vertex_index = vertex1;
    new_neighbor->next = graph->vertex[vertex2].neighbors;
    graph->vertex[vertex2].neighbors = new_neighbor;*/
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

struct graph* readGraph(const char* nome) {
  FILE *file;
  char Line[1000];
  char *result;
  int i;

  char nomeDoArquivo[] = "./novos_exemplos/";
  char str[] = ".txt";
    
  strcat(nomeDoArquivo, nome);
  strcat(nomeDoArquivo, str);

  // Abre um arquivo TEXTO para LEITURA
  file = fopen(nomeDoArquivo, "rt");
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