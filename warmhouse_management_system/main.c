#include "common.h"
#include "item.h"

int main(int argc, char const *argv[])
{
    GoodsSystem *goods = initGoods();
    if (goods == NULL)
    {
        perror("goods failed !\n");
        return NULL;
    }

    moco_data(goods);

    main_menu(goods);

    return 0;
}
