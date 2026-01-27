#include <stdio.h>

int main(void)
{
  unsigned char a, b, c;
  a = 0x3;
  b = a | 0x8;
  c = b << 1;

  printf("%d%d\n", b, c);
}