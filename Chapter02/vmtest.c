#include <stdio.h>

int main(int argc, char *argv[]) {
  
  int hoge;
  char buf[256];
  
  printf("&hoge..%p\n", &hoge);
  
  printf("Input initial value.\n");
  fgets(buf, sizeof(buf), stdin);
  sscanf(buf, "%d", &hoge);
  
  for (;;) {
    printf("hoge..%d\n", hoge);
    /*
    * getchar()让控制台处于等待输入的状态
    * 每次敲入回车键，增加hoge的值
    */
    getchar();
    hoge++;
  }

  return 0;
}
