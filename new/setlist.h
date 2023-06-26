#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "set.h"

typedef struct setlist {
    int elements[16];
    struct setlist* next;
} setlist_t;

setlist_t* setlist_create() {
    setlist_t* list = (setlist_t*) malloc(sizeof(setlist_t));
    for (int i = 0; i < 16; i++)
    {
        list->elements[i] = -1;
    }
    list->next = NULL;
    return list;
}

void addToSetList(setlist_t* list, graph_t* g) {
    if (list == NULL) {
        return;
    }

    setlist_t* newSet = (setlist_t*) malloc(sizeof(setlist_t));


    for (int i = 0; i < 16; i++)
    {
        if (!SET_CONTAINS_FAST(g->valid_vertex, i)) {
            continue; // Ignorar vértices que não pertencem a valid_vertex
        }
        list->elements[i] = i;
    }

    newSet->next = NULL;

    setlist_t* current = list;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newSet;
}

#include <stdbool.h>

bool isVertexListInSetList(setlist_t* list, graph_t* g) {
    setlist_t* current = list;

    while (current != NULL) {
        bool found = true;

        for (int i = 0; i < g->n; i++) {
            if (!SET_CONTAINS_FAST(g->valid_vertex, i)) {
                continue; 
            }

            if (current->elements[i] != i) {
                found = false;
                break;
            }
        }

        if (found) {
            return true; 
        }

        current = current->next;
    }

    return false; 
}

