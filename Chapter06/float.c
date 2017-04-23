#include <stdio.h>

void sub_func();

void func(f)
float f;
{
  sub_func(&f);
}
