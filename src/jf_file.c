#include "jf_file.h"

#include <stdlib.h>
#include <string.h>

#include "dirent.h"
#include "jf_string.h"

FILE *find_open_in_workingdir(char *path, char *fopen_argument,
                              char *working_directory) {
    FILE *file;
    file = fopen(path, fopen_argument);
    if (file != NULL) {
        return file;
    }
    fclose(file);
    struct dirent *entry;
    DIR *dir;
    dir = opendir(working_directory);
    if (dir == NULL) {
        perror("opendir");
        exit(1);
    }

    while ((entry = readdir(dir)) != NULL) {
        int entry_is_directory = entry->d_type == DT_DIR;
        char *directory_name = entry->d_name;

        char *new_working_dir = strdup(working_directory);
        append_string(&new_working_dir, "/");
        append_string(&new_working_dir, directory_name);
        // printf("%s\n", new_working_dir);
        if (entry_is_directory) {
            int entry_is_valid = strcmp(".", directory_name) != 0 && strcmp(
                                     "..", directory_name) != 0;
            if (entry_is_valid) {
                // char *new_working_dir = strdup(working_directory);
                // append_string(&new_working_dir, "/");
                // append_string(&new_working_dir, directory_name);
                file = find_open_in_workingdir(path, fopen_argument,
                                               new_working_dir);
                if (file != NULL) {
                    return file;
                }
            }
        } else {
            if (strcmp(directory_name, path) == 0) {
                file = fopen(new_working_dir, fopen_argument);
                printf("%s\n", new_working_dir);
                closedir(dir);
                return file;
            }
        }
        // free(directory_name);
        free(new_working_dir);
    }
    closedir(dir);
    return NULL;
}
