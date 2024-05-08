#include "setlist.h"

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
void setlist_print(FILE *arquivo, setlist_t* list) {
    if (list == NULL) {
        printf("Erro: Lista de conjuntos invalida em setlist_print.\n");
        return;
    }

    setlist_t* current = list->next;
    int actual_size = 0;
    int old_size = 0;
    bool set_size_printed = false;
    int counter;

    while (current != NULL) {
        if (actual_size != set_size(current->elements)) {
            actual_size = set_size(current->elements);
            if (!set_size_printed) {
                if (old_size > 0) {
                    fprintf(arquivo,"Total de elementos de %d vértices igual a: %d\n\n", old_size, counter);
                }

                fprintf(arquivo,"\nn = %d\n", actual_size);
                counter = 0;
                old_size = actual_size;
            }
        }
        set_print_new(arquivo, current->elements);
        current = current->next;

        counter++;
    }

    fprintf(arquivo,"Total de elementos de %d vértices igual a: %d\n\n", old_size, counter);
}

/*
 * setlist_print_max()
 *
 * Prints sets (graphs) in the set list with a specific size.
 * Returns void.
 */
void setlist_print_max(FILE *arquivo, setlist_t* list, int size) {
    if (list == NULL) {
        printf("Erro: Lista de conjuntos invalida em setlist_print.\n");
        return;
    }

    setlist_t* current = list->next;
    while (current != NULL) {
        if (set_size(current->elements) == size)
            set_print_new(arquivo, current->elements);
        current = current->next;
    }
}

/*
 * set_compare_vertices()
 *
 * Compare the sets based on vertices.
 * Returns a negative value if set1 < set2, 0 if set1 == set2, and a positive value if set1 > set2.
 */
int set_compare_vertices(set_t set1, set_t set2) {
    for (int i = 0; i < SET_MAX_SIZE(set1); i++) {
        if (SET_CONTAINS(set1, i) && !SET_CONTAINS(set2, i)) {
            return -1; 
        } else if (!SET_CONTAINS(set1, i) && SET_CONTAINS(set2, i)) {
            return 1;   
        }
    }

    return 0;  
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

    setlist_t* sorted = NULL; 

    setlist_t* current = list->next;

    while (current != NULL) {
        setlist_t* next = current->next;

        if (sorted == NULL || set_size(current->elements) < set_size(sorted->elements) ||
            (set_size(current->elements) == set_size(sorted->elements) &&
             set_compare_vertices(current->elements, sorted->elements) < 0)) {
            current->next = sorted;
            sorted = current;
        } else {
            setlist_t* search = sorted;
            while (search->next != NULL && (set_size(current->elements) > set_size(search->next->elements) ||
                                            (set_size(current->elements) == set_size(search->next->elements) &&
                                             set_compare_vertices(current->elements, search->next->elements) > 0))) {
                search = search->next;
            }
            current->next = search->next;
            search->next = current;
        }

        current = next;
    }

    list->next = sorted;
}