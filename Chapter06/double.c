#include <stdio.h>

void sub_func();

void func(d)
double d;
{
  sub_func(&d);
}
