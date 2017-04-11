#include <stdio.h>

void hello(void) {

  fprintf(stderr, "hello!\n");
  
}

void func(void) {
  
  void *buf[10];
  static int i;
  
  for (i = 0; i < 100; i++) {
    buf[i] = hello;
  }
}


int main(int argc, char *argv[]) {
  
  int buf[1000];
  
  func();
  
  return 0;
}
