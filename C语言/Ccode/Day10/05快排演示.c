#include <stdio.h>
#include <stdlib.h>


int current_sort_func(const void *a, const void *b) {
    // 自己定义排序规则一个回调函数
    // a 前一个元素    b后一个元素
    // return *a - *b   若 a > b 此时 *a - *b > 0 此时a的值向后排
    //                     a < b 此时 *a - *b < 0 此时a的值向前排
    // 此时实现升序
    // return *b - *a   若 a > b 此时 *b - *a < 0 此时a的值向前排
    //                     a < b 此时 *b - *a > 0 此时a的值向后排
    // 此时实现降序
    return  *(int *)b - *(int *)a;
}

int main(int argc, char const *argv[])
{
    int arr[] = {33, 7, 19, 3, 55, 2, 16, 40, 1, 20, 4, 43};

    qsort(arr,12,sizeof(int),current_sort_func);

    for (int i = 0; i < 12; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
    
    return 0;
}
