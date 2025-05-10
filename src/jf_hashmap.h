//
// Created by NausetJF on 5/9/25.
//

#ifndef JF_HASHTABLE_H
#define JF_HASHTABLE_H

#include "jf_linkedlist.h"

typedef struct hashmap {
    Linked_List keys;
    Linked_List *list;
} Hash_Map;

int hashcode(Hash_Map *dic, void *code);

Hash_Map *hashmap_init();

void hashmap_clear(Hash_Map *dic);

void hashmap_rehash(Hash_Map **dic);

void hashmap_put(Hash_Map *dic, void *key, void *value);

void *get_value(Hash_Map *dic, char *field_name);


void *hashmap_get(void *key);

#endif //JF_DICTIONARY_H
