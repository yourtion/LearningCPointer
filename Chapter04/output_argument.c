#include <stdio.h>

void func(int *a, double *b) 
{
  *a = 5;
  *b = 3.5;
}

int main(int argc, char *argv[]) 
{
  int a;
  double b;
  
  func(&a, &b);
  
  printf("a..%d b..%f\n", a, b);
  
  return 0;
}
