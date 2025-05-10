//
// Created by NausetJF on 5/9/25.
//

#ifndef JF_OBSIDIAN_H
#define JF_OBSIDIAN_H

typedef struct ObsidianFile {
} ObsidianFile;

typedef struct Link {
} Link;


char *isolate_markdown_link_from_line(char *line);

char **get_obsidian_links();


#endif //JF_OBSIDIAN_H
