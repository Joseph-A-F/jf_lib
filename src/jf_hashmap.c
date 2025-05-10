//
// Created by NausetJF on 5/9/25.
//
#include "jf_hashmap.h"

#include <stddef.h>
#include <stdlib.h>

int hashcode(Linked_List *list, void *code) {
    return (int) code % list->size;
}

void hashmap_init(Linked_List *dic) {
    if (dic == NULL) {
        dic = (Linked_List *) malloc(sizeof(Linked_List));
    }
    dic->size = 0;
}

void hashmap_rehash(Linked_List **dic) {
    int new_size = (*dic)->size + 1;
    Linked_List *new_dic = gen_linked_list_size(new_size);
    for (int i = 0; i < (*dic)->size; i++) {
        Node *currentNode = get_node(dic, i);
        write_data_to_node_index(new_dic, i, currentNode->data);
    }
}

void hashmap_put(Linked_List *dic, void *key, void *value) {
    int index = hashcode(dic, key);
    Node *node = get_node(dic, index);
    if (node != NULL) {
        hashmap_rehash(&dic);
    }
}
