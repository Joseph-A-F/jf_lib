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

    Node *prev = NULL;
    for (int i = 0; i < size; i++) {
        Node *node = (Node *) malloc(sizeof(Node));
        node->data = NULL;
        node->next = NULL;
        if (prev) {
            prev->next = node;
        } else {
            list->head = node;
        }
        prev = node;
    }

    return list;
}

Linked_List *new_blank_linked_list() {
    Linked_List *new_list = (Linked_List *)
            malloc(sizeof(Linked_List));
    if (!new_list) {
        printf("error");
        exit(1);
    }
    new_list->size = 0;

    return new_list;
}

void append_list(Linked_List **list, void *data) {
    Node *new_node = malloc(sizeof(Node));
    if (!new_node) {
        printf("error");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
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

void delete_list_node(Linked_List **list, void *data) {
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
    check_index(list, index);
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

void check_index(Linked_List *list, int i) {
    if (i > list->size) {
        printf("error: %d is larger then list size %i", i, list->size);
        exit(1);
    }
}

void set_index(Linked_List *list, int i, void *data) {
    check_index(list, i);
    Node *tmp = get_node(list, i);
    if (!tmp) {
        printf("error");
        exit(1);
    }
    tmp->data = strdup(data);
    free(data);
}


