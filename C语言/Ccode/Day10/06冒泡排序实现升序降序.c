#include <stdio.h>

int ascorder(int a, int b)
{
    return a > b;
}

int descorder(int a, int b)
{
    return a < b;
}


int bubblesort(int *arr, int len, int (*order)(int a, int b))
{
    // 循环1控制冒泡次数
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (order(arr[j], arr[j + 1]))
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {33, 7, 19, 3, 55, 2, 16, 40, 1, 20, 4, 43};

    bubblesort(arr, 12, descorder);

    printf("冒泡后: ");

    for (int i = 0; i < 12; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}
