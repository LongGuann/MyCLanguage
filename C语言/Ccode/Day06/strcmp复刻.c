/*
  strcmp功能的实现
  -------
  比较数组遇到相同字符串返回0
  -----遇到不同字符串返回第一个不同字符的差值
*/

#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
  char arr1[] = {"AOGOGO"};
  char arr2[] = {"AOGOGO"};
  int i = 0;
  while (1)
  {
    if (arr1[i] != arr2[i])
    {
      printf("第一个不同字符的差值为：%d", arr1[i] - arr2[i]);
      break;
    }
    if (arr1[i] == '\0' && arr2[i] == '\0')
    {
      printf("0");
      break;
    }
    i++;
  }
  return 0;
}
