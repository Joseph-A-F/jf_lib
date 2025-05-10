#include "jf_linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <_string.h>

void print_statement(void) {
}

Linked_List *gen_linked_list_size(int size) {
    Linked_List *list = (Linked_List *) malloc(sizeof(Linked_List));
    list->size = size;
    list->head = NULL;
    int count = 0;
    Node *tmp = list->head;
    while (count < size) {
        tmp = malloc(sizeof(Node));
        tmp = tmp->next;
        count++;
    }
}

Linked_List *new_blank_jf_linked_list() {
    Linked_List *new_list = (Linked_List *)
            malloc(sizeof(Linked_List));
    if (!new_list) {
        printf("error");
        exit(1);
    }
    new_list->size = 0;

    return new_list;
}

void push_jf_linked_list(Linked_List **list, void *data, DataType type) {
    Node *new_node = malloc(sizeof(Node));
    if (!new_node) {
        printf("error");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    new_node->type = type;
    //
    if ((*list)->head == NULL) {
        (*list)->head = new_node;
    } else {
        Node *tmp = (*list)->head;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = new_node;
        new_node->prev = tmp;
    }
    (*list)->size++;
}

void delete_jf_linked_list(Linked_List **list, void *data) {
    Node *tmp = (*list)->head;
    while (tmp != NULL) {
        if (tmp->data == data) {
            Node *deleted_node = tmp;
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            free(deleted_node);
            (*list)->size--;
        }
        tmp = tmp->next;
    }
}

Node *get_node(Linked_List *list, int index) {
    Node *tmp = list->head;
    int i = 0;
    while (tmp != NULL) {
        if (i == index) {
            return tmp;
        }
        i++;
        tmp = tmp->next;
    }
    return NULL;
}

int get_index(Linked_List *list, void *data) {
    Node *tmp = list->head;
    int i = 0;
    while (tmp != NULL) {
        if (tmp->data == data) {
            return i;
        }
        tmp = tmp->next;
        i++;
    }
    return -1;
}

void foreach_node(Linked_List *list,
                  void (*function)(void *)) {
    if (!list || !function) {
        printf("error");
        exit(1);
    }
    Node *node = list->head;
    while (node != NULL) {
        function(node->data);
        node = node->next;
    }
}

void write_data_to_node_index(Linked_List *list, int i, void *data) {
    Node *tmp = get_node(list, i);
    if (!tmp) {
        printf("error");
        exit(1);
    }
    tmp->data = strdup(data);
    free(data);
}


