#include <stdio.h>
#include <stdlib.h>

// 零长数组让结构体内部支持 边长数组的一种替代方案
// 零长数组必须是最后一个成员
struct node
{
    int a;
    int b;
    int arr[0];
};

int main(int argc, char const *argv[])
{
    // 变长数组的替代方案
    int *arr = malloc(sizeof(int) * 10);

    struct node *n = malloc(sizeof(struct node) + sizeof(int) * 10);

    n->a = 10;
    n->b = 12;
    for (int i = 0; i < 10; i++)
    {
        n->arr[i] = i + 1;
        printf("%d ", n->arr[i]);
    }



    

    return 0;
}
