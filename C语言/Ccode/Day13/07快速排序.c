#include <stdio.h>
// https://www.hello-algo.com/chapter_sorting/quick_sort/#__tabbed_1_9
// nums 整个数组首元素地址
// left 当前递归子数组 最左边下标
// right 当前递归子数组 最右边下标
void quickSort(int *nums, int left, int right)
{

    // 子数组长度为 1 或 为 0 无需继续递归
    if (right <= left)
    {
        return;
    }

    // 创建哨兵
    int i = left, j = right;
    // 定义基准数
    int base = nums[left];

    // 大循环控制哨兵必须碰面才可以停下
    while (i < j)
    {
        // 必须让j先走
        while (nums[j] >= base && i < j)
        {
            j--;
        }
        // 再让i走
        while (nums[i] <= base && i < j)
        {
            i++;
        }
        // 两个都停下找了需要交换的数,进行交换
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    int temp = nums[left];
    nums[left] = nums[j];
    nums[j] = temp;
    // 左子数组
    quickSort(nums,left, j - 1);
     // 右子数组
    quickSort(nums,j + 1, right);
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
