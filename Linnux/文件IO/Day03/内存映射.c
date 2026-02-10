#include "myhead.h"

int main(int argc, char const *argv[])
{
    int lcd_fd = open("/dev/fb0", O_RDWR);
    if(lcd_fd == -1){return -1;}

    int (*buf)[800] = mmap(NULL, 800 * 480 * 4, PROT_READ|PROT_WRITE, MAP_SHARED,lcd_fd, 0);
    if(buf == (void *)-1){return -1;}

    while (1)
    {
        for (int y = 0; y < 480; y++)
        {
            for(int x = 0; x < 800; x++)
            {
                buf[y][x] = 0xe581f0;
            }
        }sleep(2);
        for (int y = 0; y < 480; y++)
        {
            for(int x = 0; x < 800; x++)
            {
                buf[y][x] = 0x167bff;
            }
        }sleep(2);
        for (int y = 0; y < 480; y++)
        {
            for(int x = 0; x < 800; x++)
            {
                buf[y][x] = 0xc3453e;
            }
        }
        sleep(2);
    }
    
    return 0;
}
