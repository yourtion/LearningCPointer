#include <stdio.h>

int main(int argc, char *argv[]) {
  
  int hoge = 5;
  int piyo = 10;
  int *hoge_p;
  
  /// 输出每个变量的地址
  printf("&hoge..%p\n", &hoge);
  printf("&piyo..%p\n", &piyo);
  printf("&hoge_p..%p\n", &hoge_p);

  /// 将 hoge 的地址赋予 hoge_p
  hoge_p = &hoge;
  printf("hoge_p..%p\n", hoge_p);
  
  /// 通过 hoge_p 输出 hoge 的内容
  printf("*hoge_p..%d\n", *hoge_p);
  
  /// 通过 hoge_p 修改 hoge 的内容
  *hoge_p = 10;
  printf("hoge..%d\n", hoge);

  return 0;
}
