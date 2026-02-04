#include <stdio.h>

#define TOSTRING(p) #p
#define STRCAT(a, b) a##b

int main(int argc, char const *argv[])
{
    char *p = "hello "
              "world";

    printf("%s \n", p);

    char *str = TOSTRING(123456);

    printf("%s \n", str);

    double d = 3.1415926;

    char *str1 = TOSTRING(d);
    printf("%s \n", str1); // "d"

    int p6 = 1234;

    printf("%d \n", STRCAT(p, 6)); // 变成了p6

    return 0;
}
