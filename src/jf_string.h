#ifndef JF_STRING_H
#define JF_STRING_H

void append_string(char **destination, const char *addition);

// generate_substring_from_token(character_name_path, "|", 0, 1);
char *generate_substring_from_token(char *string, char *token, int start, int end);

#endif