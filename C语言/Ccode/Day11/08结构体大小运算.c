#include <stdio.h>

struct node
{
    short a;
    double b;
    char c;
};

struct node1
{
    short a; // 对齐边界 2
    long double b; //  对齐边界 16
    char c; // 对齐边界 1
};


int main(int argc, char const *argv[])
{
    printf("%ld \n", sizeof(struct node));

    printf("%ld \n", sizeof(long double));
    printf("%ld \n", sizeof(struct node1));

    struct node1 n;

    printf("%ld \n",&(n.a));
    printf("%ld \n",&(n.b));
    return 0;
}
