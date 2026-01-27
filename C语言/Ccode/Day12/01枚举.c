#include <stdio.h>

enum CAR_MOVE
{
    MOVE_UP = 7, // 枚举第一个成员没有赋值,默认为0, 后一个成员的值默认是前一个成员的值+1
    MOVE_DOWN,
    MOVE_LEFT = 12,
    MOVE_RIGHT,
};
// 不管是使用宏来定义常量，还是使用枚举来定义常量，目的只有一个：增强程序的可读性。
int main(int argc, char const *argv[])
{
    // 定义一个枚举型变量
    enum CAR_MOVE m = MOVE_LEFT;

    printf("MOVE_UP %d \n", MOVE_UP);
    printf("MOVE_DOWN %d \n", MOVE_DOWN);
    printf("MOVE_LEFT %d \n", MOVE_LEFT);
    printf("MOVE_RIGHT %d \n", MOVE_RIGHT);

    switch (m)
    {
    case MOVE_UP:
        printf("向上 \n");
        break;
    case MOVE_LEFT:
        printf("向左 \n");
        break;
    case MOVE_RIGHT:
        printf("向右 \n");
        break;
    case MOVE_DOWN:
        printf("向下 \n");
        break;
    default:
        break;
    }
    return 0;
}
