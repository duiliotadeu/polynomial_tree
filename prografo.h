#ifndef PROGRAFO_H
#define PROGRAFO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cliquer/graph.h"
#include "setlist.h"

/*
 * GRAPH READING AND LOADING FUNCTIONS
 */

/*
 * run_prografo()
 *
 * The main function.
 */

int run_prografo(char* executionType, char* filePath);

/* 
 * prografo_read_dimacs()
 *
 * Reads a graph in DIMACS format from an open file and returns a pointer to the graph data structure.
 */
graph_t *prografo_read_dimacs(FILE *fp);

/* 
 * prografo_read_dimacs_file()
 *
 * Opens a file with the specified name, reads the graph in DIMACS format from that file,
 * and returns a pointer to the graph data structure.
 */
graph_t *prografo_read_dimacs_file(char *file);

/* 
 * prografo_reading_file_name()
 *
 * Reads the file name from the standard input and returns the string containing the file name.
 */
char* prografo_reading_file_name();

/* 
 * prografo_reading_file_path()
 *
 * Constructs the full path for a file based on the file name.
 * Assumes that files are located in the "./examples/" directory.
 * Returns the full path.
 */
char* prografo_reading_file_path(const char* file_name);

/*
 * MEMORY COPY AND RELEASE FUNCTIONS
 */

/*
 * prografo_new()
 *
 * Returns a newly allocated graph with n vertices all with weight 1,
 * no edges and a empty valid_vertex.
 */
graph_t *prografo_new(int n);

/* 
 * prografo_free()
 *
 * Frees the memory associated with the graph 'g'.
 */
void prografo_free(graph_t *g);

/* 
 * prografo_copy()
 *
 * Creates a deep copy of the input graph 'graph', including edges and valid vertices.
 * Returns the copied graph.
 */
graph_t* prografo_copy(graph_t* graph);

/*
 * GRAPH MANIPULATION FUNCTIONS
 */

/* 
 * prografo_find_vertex_with_max_edges()
 *
 * Finds the vertex in the graph 'graph' with the highest number of incident edges.
 * Returns the index of that vertex.
 */
int prografo_find_vertex_with_max_edges(graph_t* graph);

/* 
 * prografo_delete_edges()
 *
 * Removes all edges incident to vertex 'v' in the graph 'g'.
 */
void prografo_delete_edges(graph_t *g, int v);

/* 
 * prografo_delete_neighbors_edges()
 *
 * Removes all edges incident to neighbors of vertex 'v' in the graph 'g'
 * and removes those neighbors from the list of valid vertices.
 */
void prografo_delete_neighbors_edges(graph_t *g, int v);

/* 
 * prografo_is_empty()
 *
 * Checks if the graph 'graph' is empty, i.e., it has no edges.
 * Returns true if the graph is empty, false otherwise.
 */
boolean prografo_is_empty(graph_t* graph);
/*
 * MAXIMAL SETS FUNCTIONS
 */

/* 
 * prografo_maximum()
 *
 * Finds a maximal set in the graph 'g' using a recursive algorithm.
 * The resulting maximal set is stored in 'maximum'.
 */
void prografo_maximum(graph_t *g, set_t maximum);

/* 
 * prografo_maximals()
 *
 * Finds all maximal sets in the graph 'g' and stores them in a list of sets 'maximal_list'.
 * The largest maximal set found is stored in 'maximum'.
 */
void prografo_maximals(graph_t *g, setlist_t* maximal_list, set_t maximum);

/*
 * PRINTING AND DISPLAY FUNCTIONS
 */

/* 
 * prografo_print_maximal()
 *
 * Prints the number of vertices and the maximal set of the graph 'g' to the standard output.
 */
void prografo_print_maximal(graph_t *g);

#endif /* !PROGRAFO_H */