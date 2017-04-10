#include <stdio.h>

int main(int argc, char *argv[]) {
  
  int hoge = 5;
  int *hoge_p;
  
  /// 将指向 hoge 的指针赋予 hoge_p
  hoge_p = & hoge;
  /// 输出 hoge_p 的值
  printf("hoge_p...%p\n", hoge_p);
  /// 给 hoge_p 加1
  hoge_p++;
  /// *输出 hoge_p 的值
  printf("hoge_p..%p\n", hoge_p);
  /// 输出 hoge_p 加3后的值
  printf("hoge_p..%p\n", hoge_p + 3);

  return 0;
}
