#include <stdio.h>

int main(int argc, char const *argv[])
{
    int array[] = {10, 20, 30, 40, 50, 60};
    // 定义一个指针变量存储数组的首元素的地址（存储的所有方法罗列出来）
    int *p = array;
    // 通过数组名array 和 指针变量  将所有能够打印出50的值的方法都罗列出来
    printf("%d \n", array[4]);

    printf("%d \n", *(array + 4));
    printf("%d \n", 4 [array]);

    printf("%d \n", p[4]);

    printf("%d \n", *(p + 4));
    printf("%d \n", 4 [p]);


    // 注意以下方法了解就行
    char *p1 = (char *)p;

    printf("%d \n", *(int *)(p1 + 16));

    int (*p2)[6] = &array;
    // 先 *p2 解引用把整个数组地址范围缩小为 首元素地址
    // 再 +4 解引用, 拿到第四个子元素
    printf("%d \n", *(*p2 + 4));
    printf("%d \n", p2[0][4]);
     printf("%d \n", (*p2)[4]);


    return 0;
}
