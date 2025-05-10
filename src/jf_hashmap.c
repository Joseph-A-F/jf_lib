//
// Created by NausetJF on 5/9/25.
//
#include "jf_hashmap.h"

#include <stddef.h>
#include <stdlib.h>

int hashcode(Hash_Map *dic, void *code) {
    int code1 = ((char *) code)[0];
    int size = dic->list->size;
    int index = code1 % size;
    return index;
}

Hash_Map *hashmap_init() {
    Hash_Map *dic = malloc(sizeof(Hash_Map));
    dic->list = gen_linked_list_size(4);
    return dic;
}

void hashmap_rehash(Hash_Map **dic) {
    int new_size = (*dic)->list->size + 1;
    Linked_List *new_list = gen_linked_list_size(new_size);
    for (int i = 0; i < (*dic)->list->size; i++) {
        Node *currentNode = get_node((*dic)->list, i);
    }
    // char *new_code = (char *) malloc(new_size * sizeof(char));
    (*dic)->list = new_list;
}

void hashmap_put(Hash_Map *dic, void *key, void *value) {
    // Linked_List *list = dic->list;
    while (dic->list->size == 0) {
        hashmap_rehash(&dic);
    }
    int index = hashcode(dic, key);
    Node *node;
    while (node == NULL) {
        hashmap_rehash(&dic);
        node = get_node(dic->list, index);
    }
    // node->data = value;
}

void *get_value(Hash_Map *dic, char *field_name) {
    if (dic->list == NULL) {
        return NULL;
    }
    if (dic->list->size == 0) {
        return NULL;
    }
    int index = hashcode(dic, field_name);
    Node *node;
    node = get_node(dic, index);
    if (node == NULL) {
        return NULL;
    }
    return node->data;
}
