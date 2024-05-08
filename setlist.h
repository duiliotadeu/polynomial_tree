#ifndef SETLIST_H
#define SETLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "cliquer/graph.h"
#include "cliquer/set.h"

/*
 * setlist_t
 *
 * Represents a linked list structure for sets.
 */
typedef struct setlist {
    set_t elements;
    struct setlist* next;
} setlist_t;

/*
 * setlist_create()
 *
 * Creates and initializes a new entry in the set list with a given size.
 * Returns a pointer to the newly created setlist_t.
 */
setlist_t* setlist_create(int size);

/*
 * setlist_add_element()
 *
 * Adds a new set (graph) to the set list.
 * Returns void.
 */
void setlist_add_element(setlist_t* list, graph_t* g);

/*
 * setlist_exists_list()
 *
 * Checks if a set (graph) already exists in the set list.
 * Returns true if the set exists; otherwise, returns false.
 */
bool setlist_exists_list(setlist_t* list, graph_t* g);

/*
 * setlist_print()
 *
 * Prints all sets (graphs) in the set list.
 * Returns void.
 */
void setlist_print(FILE *arquivo, setlist_t* list);

/*
 * setlist_print_max()
 *
 * Prints sets (graphs) in the set list with a specific size.
 * Returns void.
 */
void setlist_print_max(FILE *arquivo, setlist_t* list, int size);

/*
 * set_compare_vertices()
 *
 * Compare the sets based on vertices.
 * Returns a negative value if set1 < set2, 0 if set1 == set2, and a positive value if set1 > set2.
 */
int set_compare_vertices(set_t set1, set_t set2);

/*
 * setlist_insertion_sort()
 *
 * Sorts the setlist in ascending order based on the size of sets.
 * Returns void.
 */
void setlist_insertion_sort(setlist_t* list);

#endif