#include "common.h"
#include "item.h"

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
    g->out_time.day = 0;
    g->out_time.hour = 0;
    g->out_time.minute = 0;
    g->out_time.month = 0;
    g->out_time.year = 0;
    return 0;
}

GoodsSystem *initGoods()
{
    DateTime time = {};
    Goods *head = newGoods("", "", "", "", "", 0, 0, "", time);
    if (head == NULL)
    {
        perror("head failed!\n");
        return NULL;
    }
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

void moco_data(GoodsSystem *Goods)
{
    DateTime date = {
        .year = 2026,  // 年
        .month = 2,    // 月
        .day = 10,     // 日
        .hour = 9,     // 时
        .minute = 45}; // 分

    GoodsSystem *g = newGoods("SCP001", "始源", "未知异常", "NULL", "NULL", 30, 1, "Earth", date);
    list_add_tail(&g->goods_head, &(Goods->goods_head->list));
}
