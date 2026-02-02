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
    MAIN_OUT_LOG,
};

void main_menu(GoodsSystem *Goods)
{
    while (1)
    {
        enum MAINMENU select;
        system("clear");

        printf("\n------------欢迎来到线上仓库------------\n");
        printf("1. \t物品查询\n");
        printf("2. \t物品信息更新\n");
        printf("3. \t删除物品\n");
        printf("4. \t物品入库\n");
        printf("5. \t物品出库\n");
        printf("6. \t报表生成\n");
        printf("7. \t入库记录查询\n");
        printf("8. \t退出系统\n");

        printf("请选择需要查询的方式: \n");
        scanf("%d", (int *)&select);
        clear_input_buffer();

        switch (select)
        {
        case MAIN_FIND_GOODS:
            find_goods_menu(Goods);
            break;

        case MAIN_UPDATA_GOODS:
        {
            find_Goods_All_id(Goods);
            char scanf_id[20];
            printf("请输入待更新的物品ID: \n");
            scanf("%s", scanf_id);
            clear_input_buffer();
            update_Goods(Goods, scanf_id);
            break;
        }

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
        case MAIN_OUT_LOG:
            return;
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
    FIND_OUT,
};

// 物品查询菜单
void find_goods_menu(GoodsSystem *Goods)
{
    while (1)
    {
        int select;
        system("clear");

        printf("\n-------------欢迎来到物品查询页面----------\n");
        printf("1. \t物品编号\n");
        printf("2. \t物品名称\n");
        printf("3. \t物品类别\n");
        printf("4. \t物品位置\n");
        printf("5. \t全部物品\n");
        printf("6. \t退出查询\n");

        printf("请选择需要查询的方式: \n");
        scanf("%d", &select);
        clear_input_buffer();

        switch (select)
        {
        case FIND_ID:
        {
            char find_id[20];
            printf("请输入要查询的物品编号：");
            scanf("%s", find_id);
            find_Goods_by_id(Goods, find_id);
            break;
        }

        case FIND_NAME:
        {
            char find_name[20];
            printf("请输入要查询的物品名称：");
            scanf("%s", find_name);
            find_Goods_by_name(Goods, find_name);
            break;
        }
        case FIND_CATEGORY:
        {
            char find_category[20];
            printf("请输入要查询的物品类别：");
            scanf("%s", find_category);
            find_Goods_by_category(Goods, find_category);
            break;
        }
        case FIND_LOCATION:
        {
            char find_location[20];
            printf("请输入要查询的物品存放位置：");
            scanf("%s", find_location);
            find_Goods_by_location(Goods, find_location);
            break;
        }
        case FIND_ALL:
            find_Goods_All(Goods);
            break;
        case FIND_OUT:
            return;
            break;
        default:
            break;
        }
    }
}

// 物品更新变量
/*
    char goods_id[20];       // 物品编号
    char goods_name[20];     // 物品名称
    char goods_category[20]; // 类别
    char goods_location[20]; // 存放位置
    char goods_colour[20];   // 物品颜色
    char goods_texture[20];  // 物品材质
    int goods_quantity;      // 数量
    double goods_weight;     // 物品重量
    DateTime put_time;       // 入库时间
     */
enum UPDATAGOODSMENU
{
    UPDATA_ID = 1,
    UPDATA_NAME,
    UPDATA_CATEGORY,
    UPDATA_LOCATION,
    UPDATA_COLOUR,
    UPDATA_TEXTURE,
    UPDATA_QUANTIRY,
    UPDATA_WEIGHT,
    UPDATA_LOGOUT,
};

// 物品更新菜单
void updata_goods_menu(GoodsSystem *goods, Goods *updata_goods)
{
    system("clear");
    printf("当前物品在仓信息如下\n");
    printGoodsInfo(updata_goods);
    menuout();
    while (1)
    {
        system("clear");
        enum UPDATAGOODSMENU select;

        printf("\n----------请选择需要修改的仓储数据---------\n");
        printf("1. \t物品编号\n");
        printf("2. \t物品名称\n");
        printf("3. \t物品类别\n");
        printf("4. \t物品位置\n");
        printf("5. \t物品颜色\n");
        printf("6. \t物品材质\n");
        printf("7. \t物品重量\n");
        printf("9. \t退出修改\n");

        printf("请选择需要修改的物品数据: \n");
        scanf("%d", (int *)&select);
        clear_input_buffer();

        switch (select)
        {
        case UPDATA_ID:
        {
            char new_id[20];
            printf("请输入需要更新成为的编号：");
            scanf("%s", new_id);
            clear_input_buffer();
            updata_goods_id(goods, updata_goods->goods_id, new_id);
            return;
            break;
        }

        case UPDATA_NAME:
        {
            char new_name[20];
            printf("请输入需要更新成为的名称：");
            scanf("%s", new_name);
            clear_input_buffer();
            updata_goods_name(goods, updata_goods->goods_name, new_name);
            return;
            break;
        }

        case UPDATA_CATEGORY:
        {
            char new_category[20];
            printf("请输入需要更新成为的编号：");
            scanf("%s", new_category);
            clear_input_buffer();
            updata_goods_name(goods, updata_goods->goods_category, new_category);
            return;
            break;
        }
        case UPDATA_LOCATION:
            /* code */
            break;
        case UPDATA_COLOUR:
            /* code */
            break;
        case UPDATA_TEXTURE:
            /* code */
            break;
        case UPDATA_WEIGHT:
            /* code */
            break;
        case UPDATA_LOGOUT:
            return;
            break;
        default:

            break;
        }
    }
}
