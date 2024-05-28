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

setlist_t* setlist_create(int size);
void setlist_add_element(setlist_t* list, graph_t* g);
bool setlist_exists_list(setlist_t* list, graph_t* g);
void setlist_print(FILE *arquivo, setlist_t* list);
void setlist_print_max(FILE *arquivo, setlist_t* list, int size);
int set_compare_vertices(set_t set1, set_t set2);
void setlist_insertion_sort(setlist_t* list);

#endif /* !SETLIST_H */