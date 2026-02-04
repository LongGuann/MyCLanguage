#include <stdio.h>
#include <string.h>

int main()
{
  int source[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int destination[10];

  int numbers[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  int fill_me_with_numbers[10];
  memcpy(fill_me_with_numbers, numbers, sizeof(numbers));

  // 复制整个数组
  memcpy(destination, source, 10 * sizeof(int));

  for (int i = 0; i < 10; i++)
  {
    printf("%d ", destination[i]); // 输出: 0 1 2 3 4 5 6 7 8 9
  }
  printf("\n");
  for (int i = 0; i < 10; i++)
  {
    printf("%d ", fill_me_with_numbers[i]);
  }

  return 0;
}