#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "graph.h"
#include "set.h"

typedef struct setlist {
    set_t elements;
    struct setlist* next;
} setlist_t;

setlist_t* setlist_create(int size) {
    setlist_t* list = (setlist_t*) malloc(sizeof(setlist_t));
    if (list == NULL) {
        printf("Erro: Falha na alocacao de memoria em setlist_create.\n");
        return NULL;
    }

    list->elements = set_new(size);
    list->next = NULL;

    return list;
}


void setlist_add_element(setlist_t* list, graph_t* g) {
    if (list == NULL) {
        printf("Erro: Lista de conjuntos invalida em setlist_add_element.\n");
        return;
    }

    setlist_t* new_set = (setlist_t*) malloc(sizeof(setlist_t));
    if (new_set == NULL) {
        printf("Erro: Falha na alocacao de memoria em setlist_add_element.\n");
        return;
    }

    new_set->elements = set_copy(NULL, g->valid_vertex);
    new_set->next = NULL;

    setlist_t* current = list;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_set;
}


bool setlist_exists_list(setlist_t* list, graph_t* g) {
    if (list == NULL) {
        printf("Erro: Lista de conjuntos invalida em setlist_exists_list.\n");
        return false;
    }

    setlist_t* current = list;

    while (current != NULL) {
        bool found = true;

        for (int i = 0; i < g->n; i++) {
            if (!SET_CONTAINS_FAST(g->valid_vertex, i)) {
                continue; 
            }

            if (!SET_CONTAINS_FAST(current->elements, i)) {
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

void setlist_print(setlist_t* list) {
    if (list == NULL) {
        printf("Erro: Lista de conjuntos invalida em setlist_print.\n");
        return;
    }

    setlist_t* current = list->next;
    while (current != NULL) {
        set_print_new(current->elements);
        current = current->next;
    }
}

