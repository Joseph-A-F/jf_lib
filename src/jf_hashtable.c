//
// Created by NausetJF on 5/9/25.
//
#include "jf_hashtable.h"

int hashcode(Hash_Table *list, void *code) {
    return (int) code % list->size;
}

void hashmap_put(Hash_Table *dic, void *key, void *value) {
    int index = hashcode(dic, key);
}
