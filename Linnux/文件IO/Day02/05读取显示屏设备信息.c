#include "myhead.h"
#include <stdbool.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <linux/fb.h>

int lcd;
struct fb_fix_screeninfo fixinfo;
struct fb_var_screeninfo varinfo;

void get_fixinfo()
{
    int ret = ioctl(lcd, FBIOGET_FSCREENINFO, &fixinfo);
    if (ret == -1)
    {
        perror("get fix info failed!");
    }
}

void get_varinfo()
{
    int ret = ioctl(lcd, FBIOGET_VSCREENINFO, &varinfo);
    if (ret == -1)
    {
        perror("get fix info failed!");
    }
}

void show_info()
{
    printf("\n获取LCD设备固定属性信息成功：\n");
    printf("[ID]: %s\n", fixinfo.id);
    printf("[FB类型]: ");
    switch (fixinfo.type)
    {
    case FB_TYPE_PACKED_PIXELS:
        printf("组合像素\n");
        break;
    case FB_TYPE_PLANES:
        printf("非交错图层\n");
        break;
    case FB_TYPE_INTERLEAVED_PLANES:
        printf("交错图层\n");
        break;
    case FB_TYPE_TEXT:
        printf("文本或属性\n");
        break;
    case FB_TYPE_VGA_PLANES:
        printf("EGA/VGA图层\n");
        break;
    }

    printf("[FB视觉]: ");
    switch (fixinfo.visual)
    {
    case FB_VISUAL_MONO01:
        printf("灰度. 1=黑;0=白\n");
        break;
    case FB_VISUAL_MONO10:
        printf("灰度. 0=黑;1=白\n");
        break;
    case FB_VISUAL_TRUECOLOR:
        printf("真彩色\n");
        break;
    case FB_VISUAL_PSEUDOCOLOR:
        printf("伪彩色\n");
        break;
    case FB_VISUAL_DIRECTCOLOR:
        printf("直接彩色\n");
        break;
    case FB_VISUAL_STATIC_PSEUDOCOLOR:
        printf("只读伪彩色\n");
        break;
    }

    printf("[行宽]: %d 字节\n", fixinfo.line_length);
    // 获取LCD设备硬件var属性
    printf("\n获取LCD设备可变属性信息成功：\n");
    printf("[可见区分辨率]: %d×%d\n", varinfo.xres, varinfo.yres);
    printf("[虚拟区分辨率]: %d×%d\n", varinfo.xres_virtual, varinfo.yres_virtual);
    printf("[从虚拟区到可见区偏移量]: (%d,%d)\n", varinfo.xoffset, varinfo.yoffset);
    printf("[色深]: %d bits\n", varinfo.bits_per_pixel);
    printf("[像素内颜色结构]:\n");
    printf("  [红] 偏移量:%d, 长度:%d bits\n", varinfo.red.offset, varinfo.red.length);
    printf("  [绿] 偏移量:%d, 长度:%d bits\n", varinfo.green.offset, varinfo.green.length);
    printf("  [蓝] 偏移量:%d, 长度:%d bits\n", varinfo.blue.offset, varinfo.blue.length);
    printf("  [透明度] 偏移量:%d, 长度:%d bits\n", varinfo.transp.offset, varinfo.transp.length);
    printf("\n");
}

int main(int argc, char const *argv[])
{
    lcd = open("/dev/fb0", O_RDWR);

    if (lcd == -1)
    {
        perror("open /dev/fb0 failed!");
        return -1;
    }

    get_fixinfo();
    get_varinfo();
    show_info();

    return 0;
}
