
#include <stdio.h>
int main()
{
  // 打印九九乘法表
  int i, j;
  for (i = 1; i <= 9; i++)
  {
    for (j = 1; j <= i; j++)
    {
      printf("%d * %d = %d\t", i, j, i * j);
    }
    printf("\n");
  }
  return 0;
}