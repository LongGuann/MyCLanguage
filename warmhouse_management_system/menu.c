#include "menu.h"

enum MAINMENU
{
    MAIN_FIND_GOODS = 1,
    MAIN_UPDATA_GOODS,
    MAIN_DEL_GOODS,
    MAIN_PUT_GOODS,
    MAIN_OUT_GOODS,
    MAIN_GENERATION,
    MAIN_FIND_PUT_RECORD,
};

void main_menu(GoodsSystem *Goods)
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
        printf("\t8. 退出系统\n");

        printf("请选择需要查询的方式: \n");
        scanf("%d", (int *)&select);
        clear_input_buffer();

        switch (select)
        {
        case MAIN_FIND_GOODS:
            find_goods_menu(Goods);
            break;
        case MAIN_UPDATA_GOODS:
            /* code */
            break;
        case MAIN_DEL_GOODS:
            /* code */
            break;
        case MAIN_PUT_GOODS:
            /* code */
            break;
        case MAIN_OUT_GOODS:
            /* code */
            break;
        case MAIN_GENERATION:
            /* code */
            break;
        case MAIN_FIND_PUT_RECORD:
            /* code */
            break;

        default:
            break;
        }
    }
}

// 物品查询变量
enum FINDGOODENMU
{
    FIND_ID = 1,
    FIND_NAME,
    FIND_CATEGORY,
    FIND_LOCATION,
    FIND_ALL,
};

void find_goods_menu(GoodsSystem *Goods)
{
    while (1)
    {
        int select;
        system("clear");

        printf("\n-------------欢迎来到物品查询页面----------\n");
        printf("\t 1. 物品编号\n");
        printf("\t 2. 物品名称\n");
        printf("\t 3. 物品类别\n");
        printf("\t 4. 物品位置\n");
        printf("\t 5. 全部物品\n");
        printf("\t 6. 退出查询\n");

        printf("请选择需要查询的方式: \n");
        scanf("%d", &select);
        clear_input_buffer();

        switch (select)
        {
        case FIND_ID:
            /* code */
            break;
        case FIND_NAME:
            /* code */
            break;
        case FIND_CATEGORY:
            /* code */
            break;
        case FIND_LOCATION:
            /* code */
            break;
        case FIND_ALL:
            find_Goods_All(Goods);
            break;
        default:
            return;
            break;
        }
    }
}