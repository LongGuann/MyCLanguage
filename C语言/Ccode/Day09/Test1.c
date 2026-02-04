#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
  char str[] = {"aaabbbccbbccab"};
  char minStr[20];
  char Chunfang[20];
  int end = 0;
  for (int i = 0; i < strlen(str); i++)
  {
    if (str[i] != str[i + 1])
    {
      minStr[end] = str[i];
      end++;
    }
  }
  minStr[end] = '\0';
  printf("%s", minStr);

  return 0;
}
