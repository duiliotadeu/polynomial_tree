#include <stdio.h>
#include <stdlib.h>
#include "set.h"

typedef struct node {
    set_t element;
    struct node* next;
} node_t;

node_t* node_create(set_t element) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    if (new_node == NULL) {
        printf("Erro ao alocar memória para o nó.\n");
        exit(1);
    }
    new_node->element = element;
    new_node->next = NULL;
    return new_node;
}

void node_add_element(node_t** head, set_t element) {
    node_t* new_node = node_create(element);
    if (*head == NULL) {
        *head = new_node;
    } else {
        node_t* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void node_print(node_t* head) {
    node_t* current = head;
    while (current != NULL) {
        set_print(current->element);  
        current = current->next;
    }
}

void node_free(node_t** head) {
    node_t* current = *head;
    while (current != NULL) {
        node_t* temp = current;
        current = current->next;
        set_free(temp->element); 
        free(temp);
    }
    *head = NULL;
}

int node_exist_set(set_t element, node_t* list) {
    node_t* current = list;

    while (current != NULL) {
        if (current->element == element) {
            return TRUE; // Element exists in the list
        }
        current = current->next;
    }

    return FALSE; // Element does not exist in the list
}