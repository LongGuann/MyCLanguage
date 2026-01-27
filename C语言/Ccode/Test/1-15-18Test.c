#include <stdio.h>

int main(int argc, char const *argv[])
{
  char *p = "abcdef";
  printf("%c ", *(p + 2));
  p += 2;
  *p = 'm';
  printf("%c\n", *p);
  return 0;
}
