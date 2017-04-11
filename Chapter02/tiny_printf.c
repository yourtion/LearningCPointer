#include <stdio.h>
#include <stdarg.h>
#include <assert.h>

void tiny_printf(char *format, ...) {

  int i;
  va_list ap;
  
  va_start(ap, format);
  for (i = 0; format[i] != '\0'; i++) {
    switch (format[i]) {
    	case 's':
        printf("%s ", va_arg(ap, char *));
        break;
      case 'd':
        printf("%d ", va_arg(ap, int));
        break;
      default:
        assert(0);
    }
  }
  va_end(ap);
  putchar('\n');
}

int main(int argc, char *argv[]) {
  
  tiny_printf("sdd", "result..", 3, 5);
  
  return 0;
}
