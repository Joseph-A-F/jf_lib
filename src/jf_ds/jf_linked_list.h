#ifndef JF_LINKED_LIST_H
#define JF_LINKED_LIST_H

void print_statement(void);

typedef struct jf_linked_list
{
    void* data;
    struct jf_linked_list *next;
    /* data */
} jf_linked_list;

jf_linked_list * new_jf_linked_list(void* data);
jf_linked_list * new_blank_jf_linked_list();

void push_jf_linked_list(void* data);
void delete_jf_linked_list(void* data);


#endif
