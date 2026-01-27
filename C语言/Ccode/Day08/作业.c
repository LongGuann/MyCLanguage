/*
1、
3、
6、
*/
#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
  /*编写一个程序，该程序读取输入直到遇到#字符，
  然后报告读取的空格数目、读取的换行符数目以及读取的所有其他字符数目。
    例如：输入:a 3 b
          c%#
      输出:spaces = 2, lines = 1, characters= 5*/

  // char c;
  // int spaces = 0, lines = 0, characters = 0;
  // while ((c = getchar()) != '#')
  // {

  //   if (c == ' '){
  //     spaces++;
  //   }
  //   else if (c == '\n'){
  //     lines++;
  //   }
  //   else{
  //     characters++;
  //   }
  // }
  // printf("%d\t%d\t%d", spaces, lines, characters);

  /*
  编写一个程序，清除用户输入字符串中的空格符并将之输出。（例如用户输入”a b”，输出”ab”）
  */
  // char c;
  // char *ch;
  // int num = 0;
  // while ((c = getchar()) != '\n')
  // {
  //   if (c == ' ')
  //   {
  //     ch[num] = '\0';
  //     num++;
  //     continue;
  //   }

  //   ch[num] = c;
  //   num++;
  // }
  // for (size_t i = 0; i < num; i++)
  // {
  //   printf("%c", ch[i]);
  // }

  /*
  将字符串中的重复字符删除，并输出新字符串。
   例如： gooogggle --->  输出 gole
  */
  // char str[] = {"gooogggle"};
  // char minStr[20];
  // char Chunfang[20];
  // int end = 0;
  // for (int i = 0; i < strlen(str); i++)
  // {
  //   if (str[i] != str[i + 1])
  //   {
  //     minStr[end] = str[i];
  //     end++;
  //   }
  // }
  // minStr[end] = '\0';
  // //printf("%s", minStr);
  // int k = 0;
  // int found;
  // for (int i = 0; i < strlen(minStr); i++)
  // {
  //   found = 0;
  //   for (int j = 0; j < k; j++)
  //   {
  //     if (minStr[i] == Chunfang[j])
  //     {
  //       found = 1;
  //       break;
  //     }
  //   }
  //   if (!found)
  //   {
  //     Chunfang[k] = minStr[i];
  //     k++;
  //   }
  // }
  // Chunfang[k] = '\0';
  // printf("%s", Chunfang);


  int ASCII[128] = {0}, len, dec;
    char arr[] = "gooogggle"; // gooogggle
    len = sizeof(arr);
    for (int i = 0,j = 0; i < len; i++)
    {
        dec = arr[i];
        ASCII[dec]++;
        if (ASCII[dec] == 1){
            arr[j++] = arr[i];
            //ch[dec]--;
        }
    }
    printf("%s",arr);
    // for (int i = 0; i < len; i++) printf("%c",arr[i]);
    

  // char str[] = "gooogggle";
  // char *p = str; // 指向字符串开头
  // char result[100];
  // int j = 0;

  // // 遍历字符串
  // while (*p != '\0')
  // {
  //   // 如果当前字符与下一个字符不同
  //   if (*p != *(p + 1))
  //   {
  //     result[j] = *p;
  //     j++;
  //   }
  //   p++; // 移动到下一个字符
  // }
  // result[j] = '\0';

  // printf("删除连续重复字符后: %s\n", result);
  return 0;
}
