#include <stdio.h>

void xuanZePaiXu(int *num, int n) {
  //选择排序
  //每次循环判断出最小值后与base位调换位置,然后开始下一次循环
  for (int i = 0; i < n - 1; i++) //n-1是下标索引的最大值,
  {
    int minInx = i;// 定义一个最小下标变量
    for (int j = i; j < n; j++)  //内循环从i开始,避免重复排序
    {
      if(num[j] < num[minInx]) {  //如果数组中有数据小于最小下标变量对应的数据,将它的下标赋给最小下标变量
        minInx = j;
      }
    }
    //数据替换
    int temp = num[i];
    num[i] = num[minInx];
    num[minInx] = temp;
  }
  
}

int main(int argc, char const *argv[])
{
  int arr[] = {1,3,6,3,6,2,4,7};

  int len = sizeof(arr) / sizeof(arr[0]);

  xuanZePaiXu(arr, len);

  for (int i = 0; i < len; i++)
  {
    printf("%d",arr[i]);
  }
  

  return 0;
}

