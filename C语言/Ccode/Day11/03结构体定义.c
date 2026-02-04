#include <stdio.h>

// 创建一个结构体数据类型
struct dog
{
    // unsigned char color;
    char name[20];
    int age;
    int weight;
};

typedef struct
{
    char name[20];
    int age;
} Student; // 结构体类型名可以省略，但是分号; 一定不能漏掉

int main(int argc, char const *argv[])
{
    // 结构体类型别名
    Student jack;
    // 定义结构体变量
    // 结构体初始化 按定义时的顺序依次初始化，用逗号隔开
    struct dog myDog = {
        "旺财",
        4,
        20
    };

    // 不按定义时的顺序，指定成员初始化
    /*
    指定成员初始化的好处：
        - 成员初始化的次序可以改变。
        - 可以初始化一部分成员。
        - 结构体新增了成员之后初始化语句仍然可用。(可维护性)
    */
    struct dog myDog2 = {
        .age = 3,
        .name = "阿福"
    };

    return 0;
}
