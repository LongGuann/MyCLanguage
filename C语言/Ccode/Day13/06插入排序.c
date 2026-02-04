#include <stdio.h>

// https://www.hello-algo.com/chapter_sorting/insertion_sort/#1141

void insertionSort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        // 从右向左移动
        int base = arr[i];
        // int j = i - 1;
        // 条件 base要么从头遍历到尾 要么找到第一个<=他的元素就停止循环
        // while (j >= 0 && arr[j] > base)
        // {
        //     arr[j + 1] = arr[j];
        //     j--;
        // }

        // arr[j + 1] = base;
        int j;
        
        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] > base)
            {
                // 向右移动
                arr[j + 1] = arr[j];
            }
            else
            { // 找到第一个比他小的就要停下

                break;
            }
        }

        arr[j + 1] = base;
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {4, 1, 8, 3, 7, 5, 0, 2, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}
