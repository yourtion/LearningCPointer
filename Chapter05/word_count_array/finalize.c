#include <stdlib.h>
#include "word_manage_p.h"

/*********************************************************
 * 管理单词部分的结束处理
*********************************************************/

void word_finalize(void)
{
  int i;
  
  /// 释放单词部分的内存区域
  for (i = 0; i < num_of_word; i++) {
    free(word_array[i].name);
  }
  
  num_of_word = 0;
}
