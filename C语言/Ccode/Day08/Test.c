#include <stdio.h>
int main(int argc, char const *argv[])
{
  int arr[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  int (*p)[4] = arr;
  int (*p1)[3][4] = &arr;
  printf("%d \n", *(*p + 6));
  printf("%d", *(*(*p1 + 1) + 2));
  return 0;
}
