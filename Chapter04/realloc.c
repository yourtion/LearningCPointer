#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int *variable_array = NULL;
  int size = 0;
  char buf[256];
  int i;
  
  while (fgets(buf, 256, stdin) != NULL) {
    size++;
    variable_array = realloc(variable_array, sizeof(int) * size);
    sscanf(buf, "%d", &variable_array[size-1]);
  }
  
  for (i = 0; i < size; i++) {
    printf("variable_array[%d]..%d\n", i, variable_array[i]);
  }
  
  return 0;
}
