#include "menu.h"

enum MAINMENU
{
    MAIN_USER_LOGIN = 1,
    MAIN_USER_REGISTER,
    MAIN_ADMIN_LOGIN,
    MAIN_SYSTEM_EXIT
};

void main_menu(FlightSystem *s)
{
    while (1)
    {
        enum MAINMENU selected;
        // 每次打印内清下屏幕
        system("clear");

        printf("\n=== 航班管理系统======\n");
        printf("1. 用户登录 \n");
        printf("2. 用户注册 \n");
        printf("3. 管理员登录 \n");
        printf("4. 退出系统 \n");

        printf("请选择: ");
        scanf("%d", (int *)&selected);

        switch (selected)
        {
        case MAIN_USER_LOGIN:
            system("clear");
            printf("登陆成功! \n");
            sleep(1);
            user_menu(s);
            break;
        case MAIN_USER_REGISTER:
            // TODO: 用户注册
            break;
        case MAIN_ADMIN_LOGIN:
            // TODO: 管理员登录
            system("clear");
            printf("管理员登陆成功! \n");
            sleep(1);
            admin_menu(s);
            break;
        case MAIN_SYSTEM_EXIT:
            return;
            break;
        default:
            break;
        }
    }
}

void user_menu(FlightSystem *s)
{

    while (1)
    {
        system("clear");
        printf("\n=== 用户功能菜单 ======\n");
        printf("1. 航班查询\n");
        printf("2. 预定航班\n");
        printf("3. 取消预定\n");
        printf("4. 查看我的预定\n");
        printf("5. 退出登录\n");
        printf("请选择: ");
        int selected = 0;

        scanf("%d", &selected);

        switch (selected)
        {
        case 1:
            displayFlightInfo(s);
            break;
        case 5:
            printf("退出成功!\n");
            return;
            break;
        default:
            break;
        }
    }
}

void admin_menu(FlightSystem *s)
{
    while (1)
    {
        system("clear");
        printf("\n=== 管理员功能菜单 ======\n");
        printf("1. 录入航班信息\n");
        printf("2. 更新航班信息\n");
        printf("3. 删除航班\n");
        printf("4. 航班查询\n");
        printf("5. 退出登录\n");
        printf("请选择: ");
        int selected = 0;

        scanf("%d", &selected);

        switch (selected)
        {
        case 4:
            displayFlightInfo(s);
            break;
        case 5:
            return;
        default:
            break;
        }
    }
}