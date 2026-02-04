#include "common.h"
#include "item.h"
#include "menu.h"

int main(int argc, char const *argv[])
{
    GoodsSystem *goods = initGoods();
    if (goods == NULL)
    {
        perror("goods failed !\n");
        return -1;
    }

    moco_data(goods);

    main_menu(goods);

    return 0;
}
