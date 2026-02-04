#include <stdio.h>

int main(int argc, char const *argv[])
{
    int arr1[6] = {1, 2, 3, 4, 5};
    // 计算数组的长度
    // 数组总大小 除以 首个元素的大小(每个元素大小相等),数组内元素的个数
    int arr1_len = sizeof(arr1) / sizeof(arr1[0]);

    for (int i = 0; i < arr1_len; i++)
    {
        printf("arr1[%d] = %d \n", i, arr1[i]);
    }

    int arr2[] = {1, 3, 5, 7, 9, 11, 13};
    int arr2_len = sizeof(arr2) / sizeof(arr2[0]);

    for (int i = 0; i < arr2_len; i++)
    {
        printf("arr2[%d] = %d \n", i, arr2[i]);
    }

    return 0;
}
