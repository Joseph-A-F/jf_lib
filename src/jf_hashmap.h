//
// Created by NausetJF on 5/9/25.
//

#ifndef JF_HASHTABLE_H
#define JF_HASHTABLE_H

#include "jf_linkedlist.h"

int hashcode(Linked_List *list, void *code);

void hashmap_init(Linked_List *dic);

void hashmap_clear(Linked_List *dic);

void hashmap_rehash(Linked_List **dic);

void hashmap_put(Linked_List *dic, void *key, void *value);

void *hashmap_get(void *key);

#endif //JF_DICTIONARY_H
