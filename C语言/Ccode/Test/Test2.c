#include <stdio.h>
void fake_array(char s[6])//数组在作为函数参数时会退化为指针
/*
void func1(char s[6])   // 看起来是数组，实际上是指针
void func2(char s[])    // 不指定大小的指针
void func3(*s)          // 明确声明为指针

这三种声明方式实际上是等价的


*/
{
  printf("%d\n", sizeof(s));
}

int main(void)
{
  char s[6] = "12345";
  for (int i = 0; i < 5; i++)
  {
    printf("%d\t", s[i]); // 遍历数组元素
  }
  fake_array(s);
  char v = 'a';
  printf("%d", v);
  return 0;
}