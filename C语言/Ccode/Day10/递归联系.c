#include <stdio.h>

// 求斐波那契第n位的值
// 0 1 1 2 3 5 8 == n = (n -1) + (n - 2)

int fibonacci(int n);

int main(){
  printf("%d", fibonacci(4));
  return 0;
}

int fibonacci(int n){
  if (n > 2)
    return fibonacci(n - 1) + fibonacci(n - 2);
  else if (n == 2 || n == 3){
    return 1;
  }
  else
    return 0;
}