#include <stdio.h>

int main(int argc, char const *argv[])
{
    // & 取地址符
    // * 解引用符

    // 这两个符号是一对, &返回指定变量(内存)的地址, *根据内存地址找到这段内存获取其值

    int arr[5] = {1, 2, 3, 4, 5};

    printf("%d \n", *arr); // arr表示首元素的地址, *根据首元素地址找到首元素获取他的值

    // arr  == &(arr[0])
    // *arr == *&(arr[0]) 因为 *&是一对互相抵消 arr[0]
    // *arr == arr[0]

    printf("%p \n", *&arr); // arr 首元素地址

    // & *的另一种理解方法
    // & 取地址,如果是地址向上扩大其范围
    // * 解引用,缩小范围,范围缩到不能再缩小时取值

    // 再看下标运算符  array[i] 是代码 *(array + i)
    int array[5] = {1, 2, 3, 4, 5};

    printf("%d \n", array[2]);

    printf("%d \n", *(array + 2));

    printf("%d \n", *(2 + array));
    // a[b]语法是个简写, c语言中展开为 *(a + b)
    printf("%d \n", 2 [array]);

    printf("%d \n", array[0]);

    printf("%d \n", *(array + 0));
    
    printf("%d \n", *array);

    printf("%d \n", *(0 + array));
    // a[b]语法是个简写, c语言中展开为 *(a + b)
    printf("%d \n", 0 [array]);

    return 0;
}
