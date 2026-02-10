#include "myhead.h"
#include <linux/input.h>

int main(int argc, char const *argv[])
{
    int t_fd = open("/dev/input/event0", O_RDONLY);
    if (t_fd == -1)
    {
        perror("open /dev/input/event0 failed!\n");
        return -1;
    }
    /*
    struct input_event{
        struct timeval time;
        __u16 type;
        __u16 code;
        __s32 value;
    }
    */

    struct input_event evt;
    // 创建一个死循环不断的读取用户的触摸信息
    int flag_x = 0, flag_y = 0, click = 0;
    while (1)
    {
        read(t_fd, &evt, sizeof(evt));

        /*
        Event types
        #define EV_SYN			0x00  可以将其理解为输入设备产生大量数据的","号
        #define EV_KEY			0x01  键盘(按键)事件
        #define EV_REL			0x02  鼠标相对移动事件
        #define EV_ABS			0x03  触摸屏的移动绝对位移

        对于触摸屏有用的就是  EV_KEY 和  EV_ABS
        */
        // printf("type %d \n", evt.type);
        // 此时触摸屏触发了按下/松开事件
        
        if (evt.type == EV_KEY && evt.code == BTN_TOUCH)
        {
            if (evt.value == 1)
            {
                printf("按下 \n");
            }
        }
        // EV_ABS触摸屏事件
        if (evt.type == EV_ABS)
        {
            if (evt.code == ABS_X && flag_x == 0)
            {
                flag_x = evt.value;
            }
            if (evt.code == ABS_Y && flag_y == 0)
            {
                flag_y = evt.value;
            }
        }
        if(flag_x != 0 && flag_y != 0 && click == 0){
            printf("获取坐标为x: %d y: %d", flag_x,flag_y);
            click++;
        }

        // 手指松开还原x y
        if(evt.type == EV_KEY && evt.code == BTN_TOUCH && evt.value == 0){
            flag_x = 0; flag_y = 0; click = 0;
        }
    }

    return 0;
}
