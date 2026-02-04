#include <stdio.h>

int a(int month);

int main()
{
  int month;
  scanf("%d", &month);
  a(month);
  
  return 0;
}

int a( int month)
{
  switch (month == 2 || month == 3 || month == 4 ? 1 : 
    month == 5 || month == 6 || month == 7 ? 2 : 
    month == 8 || month == 9 || month == 10  ? 3: 
    month == 11 || month == 12 || month == 1 ? 4: 0)
  {
  case 1:
    printf("春季 \n");
    break;
  case 2:
    printf("夏季 \n");
    break;
  case 3:
    printf("秋季 \n");
    break;
  case 4:
    printf("冬季 \n");
    break;
  default:
    printf("输入错误");
    break;
  }
  return 0;
}

