#include "common.h"
#include "item.h"
#include "menu.h"

void menuout()
{
    printf("\n按任意键继续...\n");
    getchar();
    getchar();
}

void clear_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n')
        ;
}

int is_datetime(int year, int month, int day, int hour, int minute)
{
    if (month < 1 || month > 12)
        return 0;
    if (day < 1 || day > 31)
        return 0; // 简化验证
    if (hour < 0 || hour > 23)
        return 0;
    if (minute < 0 || minute > 59)
        return 0;
    return 1;
}

Goods *newGoods(char *goods_id,       // 物品编号
                char *goods_name,     // 物品名称
                char *goods_category, // 类别
                char *goods_colour,   // 物品颜色
                char *goods_texture,  // 物品材质
                double goods_weight,  // 物品重量
                int goods_quantity,   // 数量
                char *goods_location, // 存放位置
                DateTime put_time)    // 入库时间
{
    Goods *g = malloc(sizeof(Goods));
    if (g == NULL)
    {
        perror("new good failed !\n");
        return NULL;
    }

    strcpy(g->goods_id, goods_id);
    strcpy(g->goods_name, goods_name);
    strcpy(g->goods_category, goods_category);
    strcpy(g->goods_colour, goods_colour);
    strcpy(g->goods_texture, goods_texture);
    strcpy(g->goods_location, goods_location);
    g->goods_quantity = goods_quantity;
    g->goods_weight = goods_weight;
    g->put_time = put_time;
    strcpy(g->out_time, "暂无出库记录");
    return g;
}

GoodsSystem *initGoods()
{
    DateTime time = {};
    Goods *head = newGoods("", "", "", "", "", 0, 0, "", time);
    INIT_LIST_HEAD(&head->list);

    GoodsSystem *s = malloc(sizeof(GoodsSystem));
    if (s == NULL)
    {
        perror("InitGoods failed !\n");
        free(head);
        return NULL;
    }

    s->goods_head = head;
    return s;
}

void moco_data(GoodsSystem *goods)
{
    DateTime date = {
        .year = 2026,  // 年
        .month = 2,    // 月
        .day = 10,     // 日
        .hour = 9,     // 时
        .minute = 45}; // 分

    Goods *g = newGoods("SCP001", "始源", "未知异常", "NULL", "NULL", 30, 1, "Earth", date);
    list_add_tail(&g->list, &(goods->goods_head->list));
}

void printGoodsInfo(Goods *g)
{
    printf("========== 物品信息 ==========\n");
    printf("物品编号: %s\n", g->goods_id);
    printf("物品名称: %s\n", g->goods_name);
    printf("物品类别: %s\n", g->goods_category);
    printf("物品颜色: %s\n", g->goods_colour);
    printf("物品材质: %s\n", g->goods_texture);
    printf("物品重量: %.2f kg\n", g->goods_weight);
    printf("物品数量: %d\n", g->goods_quantity);
    printf("存放位置: %s\n", g->goods_location);
    printf("入库时间: %04d-%02d-%02d %02d:%02d\n",
           g->put_time.year, g->put_time.month,
           g->put_time.day,
           g->put_time.hour, g->put_time.minute);
    printf("===============================\n");
}

void find_Goods_All(GoodsSystem *goods)
{
    system("clear");

    struct list_head *head = (&goods->goods_head->list);
    Goods *g;

    list_for_each_entry(g, head, list)
    {
        printGoodsInfo(g);
    }
    menuout();
}

void find_Goods_All_id(GoodsSystem *goods)
{
    struct list_head *head = (&goods->goods_head->list);
    Goods *g;
    int count = 0;
    list_for_each_entry(g, head, list)
    {
        printf("-------------------------------\n");
        printf("%d. 物品编号  %s\n", ++count, g->goods_id);
        printf("-------------------------------\n");
    }
}

void find_Goods_by_id(GoodsSystem *goods, const char *id)
{
    system("clear");

    struct list_head *head = (&goods->goods_head->list);
    Goods *g;

    list_for_each_entry(g, head, list)
    {
        if (strcmp(g->goods_id, id) == 0)
        {
            printGoodsInfo(g);
            menuout();
            return;
        }
    }

    printf("未查询到编号为%s的物品\n", id);
    menuout();
}

void find_Goods_by_name(GoodsSystem *goods, const char *name) // name查询物品
{
    system("clear");

    struct list_head *head = (&goods->goods_head->list);
    Goods *g;

    list_for_each_entry(g, head, list)
    {
        if (strcmp(g->goods_name, name) == 0)
        {
            printGoodsInfo(g);
            menuout();
            return;
        }
    }
    printf("未查询到名称为%s的物品\n", name);
    menuout();
}

void find_Goods_by_category(GoodsSystem *goods, const char *category) // 类别查询物品
{
    system("clear");

    struct list_head *head = (&goods->goods_head->list);
    Goods *g;

    list_for_each_entry(g, head, list)
    {
        if (strcmp(g->goods_category, category) == 0)
        {
            printGoodsInfo(g);
            menuout();
            return;
        }
    }
    printf("未查询到类别为%s的物品\n", category);
    menuout();
}

void find_Goods_by_location(GoodsSystem *goods, const char *location) // 存放位置查询物品
{
    system("clear");

    struct list_head *head = (&goods->goods_head->list);
    Goods *g;

    list_for_each_entry(g, head, list)
    {
        if (strcmp(g->goods_location, location) == 0)
        {
            printGoodsInfo(g);
            menuout();
            return;
        }
    }
    printf("未查询到%s存放有物品\n", location);
    menuout();
}

void add_Goods(GoodsSystem *goods) // 添加物品
{
}

void update_Goods(GoodsSystem *goods, const char *updated_goods) // 更新物品信息
{
    if (goods == NULL || goods->goods_head == NULL)
    {
        printf("仓库未初始化");
        sleep(1);
        return;
    }

    system("clear");
    struct list_head *head = &(goods->goods_head->list);
    Goods *p;
    Goods *temp = NULL;
    list_for_each_entry(p, head, list)
    {
        if (strcmp(p->goods_id, updated_goods) == 0)
        {
            temp = p;
            break;
        }
    }
    if (temp == NULL)
    {
        printf("未找到编号为%s的物品\n", updated_goods);
        menuout();
        return;
    }
    updata_goods_menu(goods, p);
}

void updata_goods_id(GoodsSystem *goods, char *goods_id, char *new_id) // 更新物品编号
{
    struct list_head *head = &(goods->goods_head->list);
    Goods *g;
    char old_id[20];
    list_for_each_entry(g, head, list)
    {
        if (strcmp(g->goods_id, goods_id) == 0)
        {
            strcpy(old_id, goods_id);
            strcpy(g->goods_id, new_id);
            printf("\n已经更新物品的编号%s ----> %s\n", old_id, g->goods_id);
            menuout();
            system("clear");
            return;
        }
    }
}

void updata_goods_name(GoodsSystem *goods, char *goods_name, char *new_name) // 更新物品名称
{
    struct list_head *head = &(goods->goods_head->list);
    Goods *g;
    char old_name[20];
    list_for_each_entry(g, head, list)
    {
        if (strcmp(g->goods_name, goods_name) == 0)
        {
            strcpy(old_name, goods_name);
            strcpy(g->goods_name, new_name);
            printf("\n已经更新物品的名称%s ----> %s\n", goods_name, g->goods_name);
            menuout();
            system("clear");
            return;
        }
    }
}

void updata_goods_category(GoodsSystem *goods, char *goods_category, char *new_category) // 更新物品类别
{
    struct list_head *head = &(goods->goods_head->list);
    Goods *g;
    char old_category[20];
    list_for_each_entry(g, head, list)
    {
        if (strcmp(g->goods_category, goods_category) == 0)
        {
            strcpy(old_category, goods_category);
            strcpy(g->goods_category, new_category);
            printf("\n已经更新物品的类别%s ----> %s\n", old_category, g->goods_category);
            menuout();
            system("clear");
            return;
        }
    }
}

void delete_Goods(GoodsSystem *goods, const char *delete_goods_id) // 删除物品
{
}

void display_Goods(GoodsSystem goods) // 显示物品信息
{
}
