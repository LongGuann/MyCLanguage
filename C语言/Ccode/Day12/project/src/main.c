#include <stdio.h>
#include "tool.h"
#include "test.h"

int main(int argc, char const *argv[])
{
    printf("add %d \n", add(7, 8));
    printf("minus %d \n", minus(7, 8));
    test(10, 15);
    return 0;
}
