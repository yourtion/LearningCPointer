#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define ALLOC_SIZE (256) 
#include "read_line_v2.h"

char **add_line(char **text_data, char *line, int *line_alloc_num, int *line_num)
{
  assert(*line_alloc_num >= *line_num);
  if (*line_alloc_num >= *line_num) {
    text_data = realloc(text_data, (*line_alloc_num + ALLOC_SIZE) * sizeof(char*));
    *line_alloc_num += ALLOC_SIZE;
  }
  text_data[*line_num] = line;
  (*line_num)++;
  
  return text_data;
}

char **read_file(FILE *fp, int *line_num_p)
{
  char **text_data = NULL;
  int line_num = 0;
  int line_alloc_num = 0;
  char *line;
  
  while (read_line(fp, &line) != READ_LINE_EOF) {
    text_data = add_line(text_data, line, &line_alloc_num, &line_num);
  }
  
  /// 将 text_data 缩小到实际需要的大小
  text_data = realloc(text_data, line_num * sizeof(char*));
  *line_num_p = line_num;
  
  return text_data;
}

int main(int argc, char *argv[])
{
  char **text_data;
  int line_num;
  int i;
  
  text_data = read_file(stdin, &line_num);
  
  printf("read_file_v2: \n");
  
  for (i = 0; i < line_num; i++) {
    printf("%s\n", text_data[i]);
  }
  
  return 0;
}
