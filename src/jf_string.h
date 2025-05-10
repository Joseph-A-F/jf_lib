#ifndef JF_STRING_H
#define JF_STRING_H

void append_string(char **destination, const char *addition);


int get_token_size(char *str, char *token);


char *generate_substring_from_token(const char *string, const char *token,
                                    int start, int end);


#endif
