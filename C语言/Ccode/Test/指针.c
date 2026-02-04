#include <stdio.h>
int main()
{
  int *p1;    // 用于存储 int  型数据的地址，p1 被称为 int  型指针，或称整型指针
  char *p2;   // 用于存储 char 型数据的地址，p2 被称为 char 型指针，或称字符指针
  double *p3; // 用于存储double型数据的地址，p3 被称为 double 型指针

  int a = 100;
  p1 = &a; // 将一个整型地址，赋值给整型指针p1

  char c = 'x';
  p2 = &c; // 将一个字符地址，赋值给字符指针p2

  double f = 3.14;
  p3 = &f; // 将一个浮点地址，赋值给浮点指针p3

  printf("%d\n%c\n%f\n", a, c, f);

  *p1 = 200;
  *p2 = 'y';
  *p3 = 4.54;

  printf("%d\n%c\n%f\n", a, c, f);
  return 0;
}