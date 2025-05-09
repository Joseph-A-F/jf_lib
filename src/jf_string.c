#include "jf_string.h"

#include <iso646.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void append_string(char **destination, const char *addition) {
    if (*destination == NULL) {
        *destination = (char *) malloc(strlen(addition) + 1);
        if (!*destination) {
            printf("WHY...");
            exit(1);
        }

        strcpy(*destination, addition);
        return;
    }

    char *new_string = (char *) malloc(
        strlen(*destination) + strlen(addition) + 1);
    strcpy(new_string, *destination);
    strcat(new_string, addition);

    free(*destination);
    *destination = new_string;
    // free(addition);
}

int get_token_size(char *str, char *token) {
    int count = 0;

    char *str_cpy = strdup(str);
    char *token_string = strtok(str_cpy, token);

    while (token_string != NULL) {
        count++;
        token_string = strtok(NULL, token);
    }
    free(str_cpy);
    return count;
}

char *generate_substring_from_token(const char *string, const char *token,
                                    int start,
                                    int end) {
    int index = 0;
    int token_size = get_token_size(string, token);
    if (token_size == 0) return NULL;
    if (start < 0) start = token_size + start;
    if (end == 0) end = token_size;
    if (end < 0) end = token_size + end;
    char *string_cpy = strdup(string);


    char *new_string = malloc(sizeof(string));
    char *token_string = strtok(string_cpy, token);

    while (token_string != NULL && index < end) {
        if (index >= start) {
            strcat(new_string, token_string);
        }


        index++;
        if (index < end) {
            strcat(new_string, " ");
        }
        token_string = strtok(NULL, token);
    }

    return new_string;
}
