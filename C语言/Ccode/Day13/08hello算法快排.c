#include <stdio.h>

void swap(int *nums, int i, int j)
{
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

int partition(int nums[], int left, int right)
{
    // 创建哨兵
    int i = left, j = right;
    // 定义基准数
    int base = nums[left];

    while (i < j)
    {

        // 必须让j先走
        while (nums[j] >= base && i < j)
        {
            j--;
        }

        while (nums[i] <= base && i < j)
        {
            i++;
        }

        swap(nums, i, j);
    }

    // 两个哨兵巡逻完碰面, 碰面的位置要与 base进行交换
    swap(nums, left, i);

    return i;
}

void quickSort(int *nums, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int k = partition(nums, left, right);

    // 左子数组
    quickSort(nums, left, k - 1);

    // 右子数组
    quickSort(nums, k + 1, right);
}

int main(int argc, char const *argv[])
{
    int arr[] = {4, 8, 1, 2, 6, 0, 3, 5};

    quickSort(arr, 0, 7);

    for (int i = 0; i < 8; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
    
    return 0;
}
