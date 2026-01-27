#include <stdio.h>

void chaRuPaiXu(int *num, int n){
  //对于插入排序来讲,每次指定一个基准数,插入到前面已经排序的数组中
  
  for (int i = 1; i < n; i++)
  {
    int base = num[i];
    int j = i - 1; //默认第一个数组元素已经排序
    while(num[j] >= base && j >= 0) //一旦num[j]大于等于基准值,退出循环(找到比基准值小的数或相等的数停下,然后把基准数放到这个数后面),或是遍历数组
    {
      num[j + 1] = num[j];  //相当于把元素依次向后延后一位
      j--;
    }
    num[j + 1] = base; //把基准数放到比他小或者相等的数后面  ,,循环这个过程,完成数组的排序
  }
  
}


int main(int argc, char const *argv[])
{
  int arr[] = {1,3,6,3,6,2,4,7};

  int len = sizeof(arr) / sizeof(arr[0]);

  chaRuPaiXu(arr, len);

  for (int i = 0; i < len; i++)
  {
    printf("%d",arr[i]);
  }
  

  return 0;
}