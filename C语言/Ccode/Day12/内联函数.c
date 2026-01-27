#include <stdio.h>

//使用extern
extern inline int add(int a,int b){
  return a + b;
}

int main(int argc, char const *argv[])
{
  int a = 10, b = 5;
  int num = add(a,b);
  printf("num = %d",num);
  return 0;
}
