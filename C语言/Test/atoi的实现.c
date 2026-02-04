#include <stdio.h>
#include <stdlib.h>

char *decToBin(int dec)
{
  if (dec == 0)
  {
    return 0;
  }
  int i = 0;
  char *bin = malloc(sizeof(char) * 10);
  while (dec != 0)
  {
    int data = 0;
    data = dec % 2;
    if (data)
      bin[i] = '1';
    else
      bin[i] = '0';
    dec = dec / 2;
    i++;
  }
  bin[i] = '\0';
  return bin;
}

int main(int argc, char const *argv[])
{

  char *st;
  st = decToBin(123456);
  printf("%s", st);

  return 0;
}
