#include "myhead.h"
#include "bmp.h"

// 参数四 原屏幕上的像素画面
void show_bmp(char *src_pash, int offset_x, int offset_y, int (*buf)[800]){
    int bmp_fd = open(src_pash, O_RDONLY);
    if(bmp_fd == -1){
        perror("bmp open failed");
        return;
    }

    struct tagBITMAPFILEHEADER bmp_header;

    ssize_t ret = read(bmp_fd, &bmp_header, sizeof(bmp_header));
    if(bmp_header.bfType != 0x4D42){
        printf("%s 不是一个bmp图\n");
        close(bmp_fd);
        return;
    }
    struct tagBITMAPINFOHEADER bmp_info;
    ret = read(bmp_fd, &bmp_info, sizeof(bmp_info));
   
    int width = bmp_info.biWidth;
    int hight = bmp_info.biHeight;
    // 装小图片的数组
    //char *bmp_buf = mmap(NULL, width * hight * 3, PROT_READ|PROT_WRITE, MAP_SHARED,bmp_fd, 0);
     char *bmp_buf = malloc(width * hight *3);

    ret = read(bmp_fd, bmp_buf, width* hight *3);
    // 遍历小图片的像素
    for(int y = 0; y < hight; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int i = y * width + x;
            unsigned char b = bmp_buf[i *3 + 0];
            unsigned char g = bmp_buf[i *3 + 1];
            unsigned char r = bmp_buf[i *3 + 2];

            if((hight - 1- y) + offset_y < 480 && (x + offset_x) < 800){
                
                // 指定屏幕左上角x0，y0的位置
                buf[(hight - 1- y)+offset_y][x + offset_x] = 0x0 | b | g << 8 | r << 16;
            }
        }
    }
    
   
    close(bmp_fd);
}

int main(int argc, char const *argv[])
{
    int lcd_fd = open("/dev/fb0", O_RDWR);
    if(lcd_fd == -1){
        return -1;
    }

    int (*buf)[800] = mmap(NULL, 800 * 480 * 4, PROT_READ|PROT_WRITE, MAP_SHARED,lcd_fd, 0);
    
    if(buf == (void *)-1){return -1;}

    
    //show_bmp("./4.bmp", 500, 350, buf);
    show_bmp("./1.bmp", 0, 0, buf);
    //show_bmp("./3.bmp", 50, 0, buf);
    

    munmap(buf,800*480*4);
    buf == NULL;

    close(lcd_fd);
    return 0;
}