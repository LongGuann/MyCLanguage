#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char str[100];
    // scanf("%[^\n]", str);
    char *p = str;
    // scanf("%[^\n]", p);

    char *p1 = malloc(sizeof(char) * 100);

    printf("请输入一段文本 \n");

    scanf("%[^\n]", p1);

    // "a b    c d ef"

    size_t len = strlen(p1);

    // <= len目的是遍历到\0
    for (int i = 0, j = 0; i <= len; i++)
    {
        if (p1[i] != ' ')
        {
            p1[j] = p1[i];
            j++;
        }
    }

    printf("%s。\n", p1);

    return 0;
}
