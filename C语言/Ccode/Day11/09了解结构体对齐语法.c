#include <stdio.h>

struct node1
{
    char a : 4;
    // char b : 4;
    short c : 4;
    
};

struct node2
{
    char a;
   
    short c;
   
};

int main(int argc, char const *argv[])
{
    printf("%ld \n", sizeof(struct node1));
    printf("%ld \n", sizeof(struct node2));
    return 0;
}
