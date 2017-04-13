#include <stdio.h>
#include <stdlib.h>

void type_one_file(FILE *fp)
{
  int ch;
  while ((ch = getc(fp)) != EOF) {
    putchar(ch);
  }
}

int main(int argc, char *argv[])
{
  if (argc == 1) {
    type_one_file(stdin);
  } else {
    int i;
    FILE *fp;
    
    for (i = 1; i < argc; i++) {
      fp = fopen(argv[i], "rb");
      if (fp == NULL) {
        fprintf(stderr, "%s:%s can not open\n", argv[0], argv[i]);
        exit(1);
      }
      type_one_file(fp);
      fclose(fp);
    }
  }
  
  return 0;
}
