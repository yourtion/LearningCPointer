#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int get_word(char *buf, int buf_size, FILE *fp) {
  
  int len;
  int ch;
  
  /// 跳过读取空白字符
  while ((ch = getc(fp)) != EOF && !isalnum(ch));
  
  if (ch == EOF) return EOF;
  
  /// 此时，ch 中保存了单词的初始字符。
  len = 0;
  do {
    buf[len] = ch;
    len++;
    if (len >= buf_size) {
      /// 由于单词太长，提示错误
      fprintf(stderr, "word too long.\n");
      exit(1);
    }
  } while ((ch = getc(fp)) != EOF && isalnum(ch));
  buf[len] = '\0';
  
  return len;
}

int main(int argc, char *argv[]) {
  
  char buf[256];
  
  while(get_word(buf, 256, stdin) != EOF) {
    printf("<<%s>>\n", buf);
  }

  return 0;
}
