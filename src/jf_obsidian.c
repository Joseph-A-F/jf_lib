//
// Created by NausetJF on 5/9/25.
//
#include "jf_obsidian.h"

#include <string.h>

char *isolate_markdown_link_from_line(char *line) {
    char *pointer_to_start = strstr(line, "[[");
    pointer_to_start += 2;
    char *new_string = strdup(pointer_to_start);
    char *end_of_name = strstr(new_string, "]]");
    memset(end_of_name, 0, sizeof(end_of_name));
    //   printf("%s \n", new_string);
    return new_string;
}
