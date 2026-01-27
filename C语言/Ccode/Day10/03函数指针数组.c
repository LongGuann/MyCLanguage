#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int minus(int a, int b)
{
    return a - b;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int main(int argc, char const *argv[])
{
    int (*p)(int, int) = add;

    int (*arr[3])(int, int) = {add, minus, max};

    printf("%d \n", arr[0](7, 8));
    printf("%d \n", arr[1](17, 8));
    printf("%d \n", arr[2](77, 98));
    return 0;
}
