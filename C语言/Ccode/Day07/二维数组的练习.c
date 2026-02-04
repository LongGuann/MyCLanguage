/* 练习2： 定义一个3行4列的二维数组，并初始化值为
{4,4,34,37,3,12,2,6,5,17,9,11} ,
输出该二维数组的和、
最小值以及最小值的下标。
打印每个值的地址 */

#include <stdio.h>
int main(int argc, char const *argv[])
{
  int num = 0, i = 0, j = 0;
  int arr[3][4] = {4, 4, 34, 37, 3, 12, 2, 6, 5, 17, 9, 11};
  int max = arr[0][0], min = arr[0][0];
  int row = sizeof(arr)/sizeof(arr[0]);
  int col = sizeof(arr[0])/sizeof(arr[0][0]);
  for (i = 0; i < row; i++)
  {
    for (j = 0; j < col; j++)
    {
      if (arr[i][j] > max){max = arr[i][j];}
      if (arr[i][j] < min){min = arr[i][j];}
      num += arr[i][j];
    }
  }
  printf("二维数组的和为%d\n最小值的下标为%d\n最小值为 %d\n最小值的地址为%p", num, i, min, &min);
  return 0;
}
