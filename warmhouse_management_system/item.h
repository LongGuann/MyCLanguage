#ifndef _INC_ITEM
#define _INC_ITEM
#include "common.h"

typedef struct // 入库时间
{
    int year;
    int month;
    int day;
    int hour;
    int minute;
} DateTime;

typedef struct goods //  物品节点
{

    char goods_id[20];       // 物品编号
    char goods_name[20];     // 物品名称
    char goods_category[20]; // 类别
    char goods_location[20]; // 存放位置
    char goods_colour[20];   // 物品颜色
    char goods_texture[20];  // 物品材质
    int goods_quantity;      // 数量
    double goods_weight;     // 物品重量
    DateTime put_time;       // 入库时间
    char out_time[20];       // 出库时间
    struct list_head list;
} Goods;

typedef struct // 物品链表节点
{
    Goods *goods_head;
} GoodsSystem;

Goods *newGoods(char *goods_id,       // 物品编号
                char *goods_name,     // 物品名称
                char *goods_category, // 类别
                char *goods_colour,   // 物品颜色
                char *goods_texture,  // 物品材质
                double goods_weight,  // 物品重量
                int goods_quantity,   // 数量
                char *goods_location, // 存放位置
                DateTime put_time);   // 入库时间

GoodsSystem *initGoods();

void printGoodsInfo(Goods *goods);

void find_Goods_All(GoodsSystem *Goods);
void find_Goods_All_id(GoodsSystem *goods);
void find_Goods_by_id(GoodsSystem *goods, const char *id);             // id查询物品
void find_Goods_by_name(GoodsSystem *goods, const char *name);         // name查询物品
void find_Goods_by_category(GoodsSystem *goods, const char *category); // 类别查询物品
void find_Goods_by_location(GoodsSystem *goods, const char *location); // 存放位置查询物品

void add_Goods(GoodsSystem *goods); // 添加物品

void update_Goods(GoodsSystem *goods, const char *updated_goods); // 更新物品信息

void updata_goods_id(GoodsSystem *goods, char *goods_id, char *new_id);
void updata_goods_name(GoodsSystem *goods, char *goods_name, char *new_name);             // 更新物品名称
void updata_goods_category(GoodsSystem *goods, char *goods_category, char *new_category); // 更新物品类别

void delete_Goods(GoodsSystem *goods, const char *delete_goods_id); // 删除物品

void display_Goods(GoodsSystem goods); // 显示物品信息

void moco_data(GoodsSystem *goods);
#endif
