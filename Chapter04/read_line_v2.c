#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "read_line_v2.h"
#define ALLOC_SIZE (256)

/// 读取行的缓冲，必要时进行扩展。但是区域不会被缩小。调用 free_buffer() 释放。
static char *st_line_buffer = NULL;

/// 在 st_line_buffer 前方被分配的内存区域的大小。
static int st_current_buffer_size = 0;

/// st_line_buffer 中现在保存的字符的大小。
static int st_current_used_size = 0;

/*
 * 如有必要，扩展 st_line_buffer 前方的内存区域。
 * 在 st_line_buffer 末尾追加一个字符。
 */
static ReadLineStatus add_character(int ch)
{
  /// 此函数每次被调用，st_current_used_size都必定会增加1，正常的情况下，下面的断言肯定不会出错。
  assert(st_current_buffer_size >= st_current_used_size);
  
  /// st_current_used_size达到st_current_buffer_size的时候，扩展缓冲区的内存区域。
  if (st_current_buffer_size == st_current_used_size) {
    char *temp;
    temp = realloc(st_line_buffer, (st_current_buffer_size + ALLOC_SIZE) * sizeof(char));
    if (temp == NULL) {
      return READ_LINE_OUT_OF_MEMORY;
    }
    st_line_buffer = temp;
    st_current_buffer_size += ALLOC_SIZE;
  }
  /// 在缓冲区末尾追加一个字符
  st_line_buffer[st_current_used_size] = ch;
  st_current_used_size++;
  
  return READ_LINE_SUCCESS;
}

/*
 * 从fp读取一行字符，一旦读到文件末尾，就返回NULL。
 */
ReadLineStatus read_line(FILE *fp, char **line)
{
    int ch;
    ReadLineStatus status = READ_LINE_SUCCESS;
    
    st_current_used_size = 0;
    while ((ch = getc(fp)) != EOF) {
      if (ch == '\n') {
        add_character('\0');
        if (status != READ_LINE_SUCCESS) {
          goto FUNC_END;
        }
        break;
      }
      add_character(ch);
      if (status != READ_LINE_SUCCESS) {
        goto FUNC_END;
      }
    }
    if (ch == EOF) {
      if (st_current_used_size > 0) {
        status = add_character('\0');
        if (status != READ_LINE_SUCCESS) {
          goto FUNC_END;
        }
      } else {
        status = READ_LINE_EOF;
        goto FUNC_END;
      }
    }
    
    *line = malloc(sizeof(char) * st_current_used_size);
    if (*line == NULL) {
      status = READ_LINE_OUT_OF_MEMORY;
      goto FUNC_END;
    }
    strcpy(*line, st_line_buffer);
    
    FUNC_END:
      if (status != READ_LINE_SUCCESS && status != READ_LINE_EOF) {
        free_buffer();
      }
      return status;
}

/*
 * 释放缓冲区内存。其实即使不调用这个函数也不会有什么问题，
 * 但对于那些抱有“程序结束时，最好使用free()释放掉malloc()分配的内存区域”这种想法的人，
 * 可以调用这个函数。
 */

void free_buffer(void)
{
  free(st_line_buffer);
  st_line_buffer = NULL;
  st_current_buffer_size = 0;
  st_current_used_size = 0;
}
