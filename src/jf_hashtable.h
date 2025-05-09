//
// Created by NausetJF on 5/9/25.
//

#ifndef JF_HASHTABLE_H
#define JF_HASHTABLE_H

#include "jf_linked_list.h"

typedef Linked_List Hash_Table;

int hashcode(Hash_Table *list, void *code);

void hashmap_init(Hash_Table *dic);

void hashmap_clear(Hash_Table *dic);

void hashmap_rehash(Hash_Table *dic);

void hashmap_put(Hash_Table *dic, void *key, void *value);

void *hashmap_get(void *key);

#endif //JF_DICTIONARY_H
