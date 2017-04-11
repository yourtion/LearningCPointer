#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
  
  int *int_p;
  
  int_p = malloc(sizeof(int));
  
  *int_p = 12345;
  
  free(int_p);
  
  printf("*int_p..%d\n", *int_p);
  
  return 0;
}
