#include <stdio.h>
// 教程 https://www.hello-algo.com/chapter_sorting/selection_sort/
void selectionSort(int *arr, int n)
{
    // 最外层循环确定总的循环次数
    // i 的取值范围 0 ~ n-2
    for (int i = 0; i < n - 1; i++)
    {
        // 需要从 i ~ n-1 区间找最小值
        // i 的取值范围 0 ~ n-1
        int k = i; // 用于记录最小元素的下标
        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[k])
            {
                k = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[k];
        arr[k] = temp;
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {4, 1, 3, 1, 5, 2, 12, 9, 8, 16, 24, 0, 6};

    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}
