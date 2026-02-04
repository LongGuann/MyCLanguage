#include <stdio.h>

struct dog
{
    char a;
    double b;
    int c;
};

struct cat
{
    char a;
    int c;
    double b;
};

int main(int argc, char const *argv[])
{
    printf("dog size %ld \n",sizeof(struct dog));
    printf("cat size %ld \n",sizeof(struct cat));

    struct cat Tom1;

    struct cat Tom2;

    struct cat Tom3;

    printf("%ld \n", &Tom1);
    printf("%ld \n", &Tom2);
    printf("%ld \n", &Tom3);

    return 0;
}

