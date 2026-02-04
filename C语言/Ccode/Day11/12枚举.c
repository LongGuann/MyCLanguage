#include <stdio.h>
enum DIRECTION
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

int main(int argc, char const *argv[])
{
    // int direction = 0; // 0上 1下 2左 3右

    enum DIRECTION d = RIGHT;

    switch (d)
    {
    case UP:
        printf("向上 \n");
        break;
    case DOWN:
        printf("向下 \n");
        break;
    case LEFT:
        printf("向左 \n");
        break;
    case RIGHT:
        printf("向右 \n");
        break;
    default:
        break;
    }
    return 0;
}
