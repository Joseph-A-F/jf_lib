//
// Created by NausetJF on 5/9/25.
//
#include "jf_obsidian.h"

#include <stdlib.h>
#include <string.h>

#include "jf_file.h"
#include "jf_string.h"

char *isolate_markdown_link_from_line(char *line) {
    char *pointer_to_start = strstr(line, "[[");
    if (pointer_to_start == NULL) {
        return NULL;
    }
    pointer_to_start += 2;
    char *new_string = strdup(pointer_to_start);
    char *end_of_name = strstr(new_string, "]]");
    memset(end_of_name, 0, sizeof(end_of_name));
    //   printf("%s \n", new_string);
    return new_string;
}

FILE *get_obsidian_file(char *name, char *fopen_argument) {
    char *name_with_type = strdup(name);
    append_string(&name_with_type, ".md");
    FILE *open_in_workingdir = find_open_in_workingdir(
        name_with_type, fopen_argument, ".");
    free(name_with_type);
    return open_in_workingdir;
}
