#include "jf_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

void print_statement(void)
{
}

jf_linked_list *new_blank_jf_linked_list()
{
    jf_linked_list *new_list = (jf_linked_list*)malloc(sizeof(jf_linked_list));
    if (!new_list){
        printf("error");
        exit(1);
    }
    
    return new_list;
}
