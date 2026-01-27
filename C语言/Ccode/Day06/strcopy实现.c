/*
  strcopy
  功能的实现
  -------
  比较数组遇到相同字符串返回0
  -----遇到不同字符串返回第一个不同字符的差值
*/
#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
  char arr1[] = {"AOGOG"};
  char arr2[] = {"OOOOOO0"};
  int i = 0;
  size_t len = strlen(arr1);
  while (1)
  {
    if (arr1[i] != arr2[i])
    {
      arr1[i] = arr2[i];
    }

    i++;
    while (arr1[i] == '\0' && arr2[i] == '\0')
    {
      goto ch;
    }
  }
ch:
  printf("%s", arr1);
  return 0;
}
