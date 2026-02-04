#include<stdio.h>

#define TEST 0
#define TEST1 1

int main(int argc, char const *argv[])
{
  
  #if TEST
   printf("1");
  #elif TEST1
   printf("2");
  #endif
  
  return 0;
}
