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

/*
 * setlist_add_element()
 *
 * Adds a new set (graph) to the set list.
 * Returns void.
 */
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

/*
 * setlist_exists_list()
 *
 * Checks if a set (graph) already exists in the set list.
 * Returns true if the set exists; otherwise, returns false.
 */
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

/*
 * setlist_print()
 *
 * Prints all sets (graphs) in the set list.
 * Returns void.
 */
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

/*
 * setlist_print_max()
 *
 * Prints sets (graphs) in the set list with a specific size.
 * Returns void.
 */
void setlist_print_max(setlist_t* list, int size) {
    if (list == NULL) {
        printf("Erro: Lista de conjuntos invalida em setlist_print.\n");
        return;
    }

    setlist_t* current = list->next;
    while (current != NULL) {
        if (set_size(current->elements) == size)
            set_print_new(current->elements);
        current = current->next;
    }
}

/*
 * setlist_insertion_sort()
 *
 * Sorts the setlist in ascending order based on the size of sets.
 * Returns void.
 */
void setlist_insertion_sort(setlist_t* list) {
    if (list == NULL) {
        printf("Erro: Lista de conjuntos inválida em setlist_insertion_sort.\n");
        return;
    }

    setlist_t* sorted = NULL;  // Lista vazia para os conjuntos ordenados

    setlist_t* current = list->next;

    while (current != NULL) {
        setlist_t* next = current->next;

        // Inserir o conjunto atual na lista ordenada
        if (sorted == NULL || set_size(current->elements) <= set_size(sorted->elements)) {
            current->next = sorted;
            sorted = current;
        } else {
            setlist_t* search = sorted;
            while (search->next != NULL && set_size(current->elements) > set_size(search->next->elements)) {
                search = search->next;
            }
            current->next = search->next;
            search->next = current;
        }

        current = next;
    }

    // Atualiza a lista original com os conjuntos ordenados
    list->next = sorted;
}
