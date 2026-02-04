#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char str[100] = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
    char src_str[100] = "hello world";

    size_t src_len = strlen(src_str);

    for (int i = 0; i <= src_len; i++)
    {
        str[i] = src_str[i];
    }
    
    printf("%s \n", str);

    return 0;
}
