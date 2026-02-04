#include <stdio.h>

int main()
{
  int c[2][3][3] = {{{2, 3, 4}, {2, 3, 5}, {3, 4, 6}}, {{5, 1, 1}, {3, 2, 2}, {3, 3, 3}}};
  for (int i = 0; i < 2;)
  {
    printf("%d]\n", c[1][i][0]);
    i++;
  }
  
  return 0;
}
