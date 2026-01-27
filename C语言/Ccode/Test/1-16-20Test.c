#include<stdio.h>

  void fun(int *n)
{ while( (*n)--);
printf("%d",++(*n));
}
int main()
{ int a=100;
fun(&a);
}

