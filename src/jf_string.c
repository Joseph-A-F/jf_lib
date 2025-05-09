#include "jf_string/jf_string.h"

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
        sizeof(destination) + sizeof(addition) + 1);
    strcpy(new_string, *destination);
    strcat(new_string, addition);

    free(*destination);
    *destination = new_string;
    // free(addition);
}

char *generate_substring_from_token(char *string, char *token, int start,
                                    int end) {
    char *new_string = malloc(sizeof(string));
    char *token_string = strtok(string, token);
    int index = 0;

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

    // if (token_string == NULL) {
    //     strcpy(new_string, string);
    //     return new_string;
    // }
    // strcpy(new_string, token_string);
    // token_string = strtok(NULL, token);
    //
    // while (token_string != NULL) {
    //     strcat(new_string, token_string);
    //     token_string = strtok(NULL, token);
    // }

    return new_string;
}
