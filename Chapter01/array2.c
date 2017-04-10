#include <stdio.h>

int main(int argc, char *argv[]) {
  
  int array[5];
  int *p;
  int i;
  
  /// 为数组 array 的各元素设值
  for (i = 0; i < 5; i++) {
    array[i] = i;
  }
  
  /// 输出数组各元素的值（指针版）
  for (p = &array[0]; p != &array[5]; p++) {
    printf("%d\n", *p);
  }
  
  /// 利用指针输出数组各元素的值——改写版
  p = &array[0];
  for (i = 0; i < 5; i++) {
    printf("%d\n", *(p + i));
  }

  return 0;
}
