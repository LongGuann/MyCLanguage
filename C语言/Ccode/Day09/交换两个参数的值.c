#include <stdio.h>

void change(int *a, int *b)
{
  int *c;
  *c = *a;
  *a = *b;
  *b = *c;
}

int main(int argc, char const *argv[])
{
  int a = 11, b = 22;
  change(&a, &b);
  printf("%d%d", a, b);
  return 0;
}
