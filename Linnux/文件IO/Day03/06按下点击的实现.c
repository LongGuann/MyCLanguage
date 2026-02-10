#include "myhead.h"

int main(int argc, char const *argv[])
{
    int t_fd = open("/dev/input/event0", O_RDONLY);

    if (t_fd == -1)
    {
        perror("open /dev/input/event0 failed!");
        return -1;
    }

    struct input_event evt;

    int x = -1, y = -1;
    while (1)
    {
        read(t_fd, &evt, sizeof(evt));

        if (evt.type == EV_ABS)
        {
            // x == -1存储x坐标的变量还没有赋值
            if (x == -1 && evt.code == ABS_X)
            {
                x = evt.value;  // 蓝色板子
                // x = 800/ 1024 * evt.value;// 黑色板子
            }

            if (y == -1 && evt.code == ABS_Y)
            {
                y = evt.value;
                // y = 480/600 * evt.value; // 黑色板子
            }
        }

        if (evt.type == EV_KEY && evt.code == BTN_TOUCH && evt.value == 1 && x != -1 && y != -1 )
        {
            printf("clicked x:%d y:%d \n", x, y);
           
        }
        // 手指松开还原x y
        if (evt.type == EV_KEY && evt.code == BTN_TOUCH && evt.value == 0)
        {
            x = -1;
            y = -1;
        }
    }

    return 0;
}
