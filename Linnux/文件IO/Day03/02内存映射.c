#include "myhead.h"

int main(int argc, char const *argv[])
{
    int lcd_fd = open("/dev/fb0", O_RDWR);
    if (lcd_fd == -1)
    {
        perror("open lcd fd failed!");
        return -1;
    }

    /*
      addr：  不为NULL  -> 用户选择内存空间的起始地址  0.00001%

                 NULL      -> 系统为用户去自动分配某一块空间       99.99999%

    length： 映射的内存大小，例如：lcd液晶   800*480*4

    prot：

    PROT_EXEC  Pages may be executed.

        PROT_READ  Pages may be read.

        PROT_WRITE Pages may be written.

        PROT_NONE  Pages may not be accessed.

    如果需要多个权限，则使用"|"连接在一起，例如：   PROT_READ|PROT_WRITE



    flags：

        当有多个进程同时映射这块内存时，该参数可以决定在某一个进程内使映射内存的数据发生变更时是否影响其他进程，也决定是否影响其对应的文件数据。

        MAP_SHARED：1、进程共享内存          2、内存数据的变更同步到对应的文件

        MAP_PRIVATE：1、内存私有          2、内存数据的变更不会影响到对应的内存

    fd：文件描述符

    offset：文件偏移量（从文件的哪个地方开始进行映射）

    */
    int (*buf)[800] = mmap(NULL, 800 * 480 * 4, PROT_READ | PROT_WRITE, MAP_SHARED, lcd_fd, 0);

    if (buf == (void *)-1)
    {
        perror("mmap lcd_fd failed!");
        return -1;
    }
    

    while (1)
    {
        sleep(1);
        for (int y = 0; y < 480; y++)
        {
            for (int x = 0; x < 800; x++)
            {
                buf[y][x] = 0x00ff0000;
            }
            
        }

        sleep(1);
        for (int y = 0; y < 480; y++)
        {
            for (int x = 0; x < 800; x++)
            {
                buf[y][x] = 0x000000ff;
            }
            
        }
        
    }
    

    return 0;
}
