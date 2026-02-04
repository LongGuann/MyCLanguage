#include <stdio.h>
int main()
{
  // 判断一个数是否是质数
  int num, flag;
  printf("请输入一个数：");
  scanf("%d", &num);
  for (int i = 2; i < num; i++)
  {
    if (num % i == 0)
    {
      flag++;
      break; //break可以跳出循环，一旦flag不为0，终止循环，减少循环次数
    }
  }
  if (flag == 0)
  {
    printf("%d是质数", num);
  }
  else
  {
    printf("%d不是质数", num);
  }

  return 0;
}