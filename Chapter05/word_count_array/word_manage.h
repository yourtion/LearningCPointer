#ifndef WORD_MANAGE_H_INCLUDED
#define WORD_MANAGE_H_INCLUDED
#include <stdio.h>

void word_initialize(void);
void add_word(char *word);
void dump_word(FILE *fp);
void word_finalize(void);

#endif /* WORD_MANAGE_H_INCLUDED */
