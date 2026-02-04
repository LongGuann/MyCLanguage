#include <stdio.h>
int main()
{
  int a[3] = {1, 2, 3};

  int *p = a; // 此处，a 是一个指针，指向 a[0] （即：此处a等价于 &a[0]）
  p = a + 1;  // 此处，a 是一个指针，指向 a[0] （即：此处a等价于 &a[0]）
  // function(a);      // 此处，a 是一个指针，指向 a[0] （即：此处a等价于 &a[0]）
  // scanf("%d\n", a); // 此处，a 是一个指针，指向 a[0] （即：此处a等价于 &a[0]）

  printf("%d\n", sizeof(a)); // 此处，a 不是指向 a[0] 的指针，a是整个数组
  printf("%p\n", sizeof(&a[0]));
  printf("%p\n", &a); // 此处，a 不是指向 a[0] 的指着，a是整个数组，&a是整个数组的地址
  for (int i = 0; i < 3; i++)
  {
    printf("%p\t", &a[i]);
  }
  printf("\n");
  for (int i = -1; i < 2; i++)
  {
    printf("%p\t", *(p + i)); //遍历数组元素
  }
  return 0;
}