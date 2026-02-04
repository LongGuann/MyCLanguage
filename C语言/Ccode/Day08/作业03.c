#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    // goooooogggle
    // gogle

    char *str = malloc(sizeof(char) * 100);

    strcpy(str, "gooooggggllle");

    // 获取字符串长度
    size_t len = strlen(str);

    for (int i = 1, j = 0; i <= len; i++)
    { // 判断 str[i] 是否在去重字符内
        // str[i]
        // 判断已去重的字符串内部是否已经包含str[i]
        int flag = 0;
        for (int k = 0; k <= j; k++)
        {
            if (str[k] == str[i])
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            str[++j] = str[i];
        }
    }

    printf("%s \n",str);

    return 0;
}
