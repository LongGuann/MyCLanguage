/*
  字符串压缩。利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能。
  比如，字符串aabcccccaaa会变为2ab5c3a。若“压缩”后的字符串没有变短，则返回原先的字符串。
  你可以假设字符串中只包含大小写英文字母（a至z）。例:
  输入：“aabcccccaaa”
  输出：“2ab5c3a”
*/
#include <stdio.h>
int main(int argc, char const *argv[])
{
  int ASCII[255] = {0}, dec;
  char arr[] = "abbbcc"; 
  for (int i = 0, j = 0; i < sizeof(arr); i++){
    dec = arr[i];
    ASCII[dec]++;
    if (ASCII[dec] > 1) arr[i] = '\0';
  }
  for(int i = 0;i<sizeof(arr);i++){
    if(arr[i] == '\0') continue;
    printf("%d%c",ASCII[arr[i]],arr[i]);
  } 
  return 0;
}
