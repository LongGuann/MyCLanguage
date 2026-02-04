#include <stdio.h>
#include <ctype.h>
int main()
{
  // int num[26] = {0}, i;
  // char c;
  // while (c = getchar() != '#')
  //   if (c >= 'A' && c <= 'Z')
  //     num[c - 'A'] += 1;
  // for (i = 0; i < 26; i++)
  //   printf("%c:%d\t", i + 'A', num[i]);

  // char b[17] = {"0123456789ABCDEF"};
  // int c[64], d, i = 0, base;
  // base = 16;
  // long n;
  // printf("Enter a number : \n");
  // scanf("%ld", &n);
  // do
  // {
  //   c[i] = n % base;
  //   i++;
  //   n = n / base;
  // } while (n != 0);
  // printf("Transmite new base:\n");
  // for (--i; i >= 0; --i)
  // {
  //   d = c[i];
  //   printf("%c", b[d]);
  // }
  // printf("\n");

  // int x[4][4], n = 0, i, j;
  // for (j = 0; j < 4; j++)
  //   for (i = 3; i >= j; i--)
  //   {
  //     n++;
  //     x[i][j] = n;
  //   }
  // for (i = 0; i < 4; i++)
  // {
  //   for (j = 0; j <= i; j++)
  //     printf("%3d", x[i][j]);
  //   printf("\n");
  // }

  int a[10], i, j, t, n = 10;
  printf("Enter %d num:\n");
  for (i = 0; i < n; i++)
  {
    /* code */
    scanf("%d", &a[i]);
  }
  for (i = 0, j = 9; i < j; i++, j--)
  {
    t = a[i];
    a[i] = a[j];
    a[j] = t;
  }
  for (i = 0; i < n; i++)
  {
    /* code */
    printf("%d\t", a[i]);
  }
}
