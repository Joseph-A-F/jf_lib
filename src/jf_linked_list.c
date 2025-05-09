#include "jf_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

void print_statement(void) {
}

Linked_List *new_blank_jf_linked_list() {
    Linked_List *new_list = (Linked_List *)
            malloc(sizeof(Linked_List));
    if (!new_list) {
        printf("error");
        exit(1);
    }

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
    }


    // linked_list *new_list = new_blank_jf_linked_list();
    // new_list->data = data;
    // new_list->next = NULL;
    //
    // if (*list == NULL || (*list)->data == NULL) {
    //     *list = new_list;
    // } else {
    //     linked_list *tmp = *list;
    //     while (tmp->next != NULL) {
    //         tmp = tmp->next;
    //     }
    //     tmp->next = new_list;
    // }
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

