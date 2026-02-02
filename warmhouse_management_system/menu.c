#include "menu.h"

// 更新输入缓冲区
void clear_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

enum MAINMENU
{
    MAIN_FIND_GOODS = 1,
};

void main_menu(GoodsSystem *goods)
{
    while (1)
    {
        enum MAINMENU select;
        system("clear");

        printf("\n------------欢迎来到线上仓库------------\n");
        printf("\t1. 物品查询\n");
        printf("\t2. 物品信息更新\n");
        printf("\t3. 删除物品\n");
        printf("\t4. 物品入库\n");
        printf("\t5. 物品出库\n");
        printf("\t6. 报表生成\n");
        printf("\t7. 入库记录查询\n");

        printf("请选择需要查询的方式: \n");
        sacnf("%d", (int *)select);
    }
}

// 物品查询变量
enum FINDGOODENMU
{
    FIND_ID = 1,
    FIND_NAME,
    FIND_CATEGORY,
    FIND_LOCATION,
};

void find_goods_menu(GoodsSystem *s)
{
    while (1)
    {
        enum FINDGOODENMU select;
        system("clear");

        printf("\n-------------欢迎来到物品查询页面----------\n");
        printf("\t 1. 物品编号\n");
        printf("\t 2. 物品名称\n");
        printf("\t 3. 物品类别\n");
        printf("\t 4. 物品位置\n");

        printf("请选择需要查询的方式: \n");
        sacnf("%d", (int *)select);
    }
}