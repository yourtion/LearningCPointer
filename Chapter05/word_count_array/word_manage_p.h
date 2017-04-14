#ifndef WORD_MANAGE_P_H_INCLUDED
#define WORD_MANAGE_P_H_INCLUDED
#include "word_manage.h"

typedef struct {
  char *name;
  int count;
} Word;

#define WORD_NUM_MAX (1000)

extern Word word_array[];
extern int num_of_word;

#endif /* WORD_MANAGE_P_H_INCLUDED */
