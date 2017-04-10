#include <stdio.h>

int main(int argc, char *argv[]) {
  
  int array[5];
  int i;
  
  /// 为数组 array 的各元素设值
  for (i = 0; i < 5; i++) {
    array[i] = i;
  }
  
  /// 输出数组各元素的值
  for (i = 0; i < 5; i++) {
    printf("%d\n", array[i]);
  }
  
  /// 输出数组各元素的值
  for (i = 0; i < 5; i++) {
    printf("&array[%d]... %p\n", i, &array[i]);
  }

  return 0;
}
