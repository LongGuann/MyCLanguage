#include <stdio.h>
#include <string.h>

int main()
{
  char str[] = "aabbccc";
  char str1[100];
  printf("输入: %s\n", str);
  int i = 0, j = 0;
  while (str[i] != '\0')
  {
    char ch = str[i];
    int count = 0;
    // 统计相同字符
    while (str[i] == ch)
    {
      count++;
      i++;
    }
    if (count > 1)
      str1[j++] = count + '0'; // 数字转字符
    str1[j++] = ch;
  }
  str1[j] = '\0';
  if (strlen(str1) == strlen(str))
    printf("输出: %s\n", str);
  else
    printf("输出: %s\n", str1);
  return 0;
}