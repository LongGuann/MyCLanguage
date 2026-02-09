#include <stdio.h>

void func(int *p)
{
  p++;
}
int main()
{
  int a[] = {1, 2, 3, 4, 5};
  int *p = a;
  func(p);
  printf("%d\n", *(++p));
  return 0;
}
