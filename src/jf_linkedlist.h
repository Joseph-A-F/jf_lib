#ifndef JF_LINKED_LIST_H
#define JF_LINKED_LIST_H

typedef enum { INT_TYPE, FLOAT_TYPE, STRING_TYPE, STRUCT_TYPE } DataType;

void print_statement(void);


typedef struct Node {
    DataType type;
    void *data;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct jf_linkedlist {
    Node *head;
    int size;
} Linked_List;

#define CAST_VOID (void(*)(void *))

Linked_List *gen_linked_list_size(int size);

Linked_List *new_blank_jf_linked_list();

void push_jf_linked_list(Linked_List **list, void *data, DataType type);

void delete_jf_linked_list(Linked_List **list, void *data);

Node *get_node(Linked_List *list, int index);

int get_index(Linked_List *list, void *data);

void foreach_node(Linked_List *list,
                  void (*function)(void *));

void check_index(Linked_List *list, int i);

void set_index(Linked_List *list, int i, void *data);
#endif
