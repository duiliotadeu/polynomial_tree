#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define LINE_SIZE 1000

// Como os grafos que utilizaremos são esparsos, a estrutura utilizada é a da Lista de Adjacência.

// Definindo a estrutura do nó da lista de vizinhos
struct neighbor {
    int vertex_index;
    struct neighbor* next;
};

// Definindo a estrutura do nó da lista de adjacência
struct vertex {
    struct neighbor* neighbors;
    bool valid;
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
        graph->vertex[i].valid = true;
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
    printf("Maximal: \n");
    for (i = 0; i < graph->num_vertex; i++) {
        struct neighbor* cur_neighbor = graph->vertex[i].neighbors;
        if (graph->vertex[i].valid == true)
        {
            printf("Vertex %d: ", i);
            while (cur_neighbor != NULL) {
                printf("%d ", cur_neighbor->vertex_index);
                cur_neighbor = cur_neighbor->next;
            }
            printf("\n");
        }
    }
    printf("\n");
}

struct graph* readGraph(const char* nome) {
  FILE *file;
  char Line[LINE_SIZE];
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
  result = fgets(Line, LINE_SIZE, file);
  int num_vertex = atoi(Line);
  if (num_vertex <= 1)
  {
    printf("Número de vértices inválido, corrija o arquivo.");
    return 0;
  }
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
      result = fgets(Line, LINE_SIZE, file);
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

int adjacency_list_not_empty(struct graph* graph) {
    for (int i = 0; i < graph->num_vertex; i++) {
        if (graph->vertex[i].neighbors != NULL) {
            return i; // retorna o índice do vértice com vizinhos na lista de adjacência
        }
    }
    return -1; // retorna -1 caso nenhum vértice tenha vizinhos na lista de adjacência
}

void delete_vertex(struct graph* graph, int vertex_index) {
    // Percorre a lista de vizinhos do vértice a ser deletado
    struct neighbor* current_neighbor = graph->vertex[vertex_index].neighbors;
    while (current_neighbor != NULL) {
        // Para cada vizinho, percorre a lista de vizinhos desse vizinho
        int neighbor_index = current_neighbor->vertex_index;
        struct neighbor* next_neighbor = current_neighbor->next;
        struct neighbor* previous_neighbor = NULL;
        struct neighbor* current_neighbor2 = graph->vertex[neighbor_index].neighbors;
        while (current_neighbor2 != NULL) {
            // Quando encontra o vértice a ser deletado na lista de vizinhos do vizinho, o remove
            if (current_neighbor2->vertex_index == vertex_index) {
                if (previous_neighbor == NULL) {
                    graph->vertex[neighbor_index].neighbors = current_neighbor2->next;
                } else {
                    previous_neighbor->next = current_neighbor2->next;
                }
                free(current_neighbor2);
                break;
            }
            previous_neighbor = current_neighbor2;
            current_neighbor2 = current_neighbor2->next;
        }
        free(current_neighbor);
        current_neighbor = next_neighbor;
    }
    // Define o ponteiro de vizinhos do vértice a ser deletado como NULL e seu campo "valid" como falso
    graph->vertex[vertex_index].neighbors = NULL;
    graph->vertex[vertex_index].valid = false;
}

void delete_adj_vertex(struct graph* graph, int vertex_index) {
    struct neighbor* current_neighbor = graph->vertex[vertex_index].neighbors;
    while (current_neighbor != NULL) {
        delete_vertex(graph, current_neighbor->vertex_index);
        current_neighbor = current_neighbor->next;
    }
}
void copy_graph(struct graph* source_graph, struct graph** target_graph_ptr) {
    // Criando o grafo alvo
    struct graph* target_graph = create_graph(source_graph->num_vertex);
    
    // Copiando os dados de cada vértice do grafo fonte para o grafo alvo
    for (int i = 0; i < source_graph->num_vertex; i++) {
        // Copiando a flag de validade
        target_graph->vertex[i].valid = source_graph->vertex[i].valid;
        
        // Copiando a lista de vizinhos
        struct neighbor* source_neighbor = source_graph->vertex[i].neighbors;
        while (source_neighbor != NULL) {
            struct neighbor* target_neighbor = (struct neighbor*) malloc(sizeof(struct neighbor));
            target_neighbor->vertex_index = source_neighbor->vertex_index;
            target_neighbor->next = NULL;
            
            if (target_graph->vertex[i].neighbors == NULL) {
                target_graph->vertex[i].neighbors = target_neighbor;
            } else {
                struct neighbor* current_neighbor = target_graph->vertex[i].neighbors;
                while (current_neighbor->next != NULL) {
                    current_neighbor = current_neighbor->next;
                }
                current_neighbor->next = target_neighbor;
            }
            
            source_neighbor = source_neighbor->next;
        }
    }
    
    // Atribuindo o grafo alvo ao ponteiro fornecido
    *target_graph_ptr = target_graph;
}