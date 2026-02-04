#include <stdio.h>

// void print_arr1(int (*p)[3], int row, int col) {}

void print_arr1(int *p, int row, int col)
{

    int count = row * col;
    for (int i = 0; i < count; i++)
    {
        printf("p[%d]: %d ", i, p[i]);
    }
    printf("\n");
}

void print_arr2(int *p, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("p[%d][%d] == p[%d] == %d \t", i, j, i * col + j, p[i * col + j]);
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    int arr[5][3] = {
        {11, 22, 33},
        {77, 78, 99},
        {55, 32, 78},
        {32, 23, 18},
        {12, 19, 44}};
    print_arr2((int *)arr, 5, 3);
    // int arr[6][7];
    return 0;
}
