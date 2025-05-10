//
// Created by NausetJF on 5/9/25.
//

#ifndef JF_FILE_H
#define JF_FILE_H
#include <stdio.h>


FILE *find_open_in_workingdir(char *path, char *fopen_argument,
                              char *working_directory);


#endif //JF_FILE_H
