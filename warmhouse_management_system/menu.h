#ifndef _INC_MENU
#define _INC_NENU

#include "common.h"
#include "item.h"

// 系统菜单
void main_menu(GoodsSystem *Goods);
// 物品查询菜单
void find_goods_menu(GoodsSystem *Goods);
// 物品更新菜单
void updata_goods_menu(GoodsSystem *goods, Goods *updata_goods);
#endif
