#ifndef PROGRAFO_H
#define PROGRAFO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

#include "cliquer/graph.h"
#include "setlist.h"

int run_prografo(char* executionType, char* filePath);
graph_t *prografo_read_dimacs(FILE *fp);
graph_t *prografo_read_dimacs_file(char *file);
char* prografo_reading_file_name();
char* prografo_reading_file_path(const char* file_name);

graph_t *prografo_new(int n);
void prografo_free(graph_t *g);
graph_t* prografo_copy(graph_t* graph);

int prografo_find_vertex_with_max_edges(graph_t* graph);
void prografo_delete_edges(graph_t *g, int v);
void prografo_delete_neighbors_edges(graph_t *g, int v);
boolean prografo_is_empty(graph_t* graph);

void prografo_maximum(graph_t *g, set_t maximum);
void prografo_maximum_paralel(graph_t *g, set_t* maximum);
void prografo_maximals(graph_t *g, setlist_t* maximal_list, set_t maximum);

void prografo_print_maximal(graph_t *g);

#endif /* !PROGRAFO_H */