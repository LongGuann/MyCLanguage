#include "menu.h"

// 定义全局变量
User *uhead = NULL;
User *user = NULL;
char Username[20];
char PassWord[20];
char PassWordEctype[20];
char flight_number[20];

enum MAINMENU
{
    MAIN_USER_LOGIN = 1,
    MAIN_USER_REGISTER,
    MAIN_ADMIN_LOGIN,
    MAIN_SYSTEM_EXIT,
    // MAIN_USER_FIND,
};
// 主页菜单
void main_menu(FlightSystem *s)
{
    // 初始化全局链表头）
    if (uhead == NULL)
    {
        uhead = create_user("HEAD", ""); // 创建头节点
    }
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
        printf("5. 用户查询 \n");

        printf("请选择: ");
        scanf("%d", (int *)&selected);

        switch (selected)
        {
        case MAIN_USER_LOGIN:
            system("clear");
            printf("欢迎进入用户登陆！ \n");
            user_login_menu(s);
            break;
        case MAIN_USER_REGISTER:
            // TODO: 用户注册
            system("clear");
            printf("欢迎进入用户注册！\n");
            sleep(1);
            user_register_menu(s);
            break;
        case MAIN_ADMIN_LOGIN:
            // TODO: 管理员登录
            system("clear");
            printf("欢迎进入管理员登陆！\n");
            admin_login_menu(s);
            break;
        case MAIN_SYSTEM_EXIT:
            return;
            break;
        default:
            break;
        }
    }
}

// 用户注册页面
void user_register_menu(FlightSystem *s)
{
    while (1)
    {
        system("clear");
        printf("\n-------用户注册菜单----------\n");
        printf("1. 已有账户, 返回登陆页面\n");
        printf("2. 没有账户, 进行用户注册\n");

        int selected = 0;
        scanf("%d", &selected);

        switch (selected)
        {
        case 1:
            printf("退出成功!\n");
            return;
            break;
        case 2:
        {
            printf("即将进入用户注册页面,请稍后!\n");
            sleep(1);

            while (1)
            {
                // 输入用户名
                printf("请输入用户名: ");
                scanf("%s", Username);

                // 输入密码
                printf("请输入用户密码: ");
                scanf("%s", PassWord);

                // 确认密码
                printf("请再次输入用户密码: ");
                scanf("%s", PassWordEctype);

                // 清空输入缓冲区
                int ch;
                while ((ch = getchar()) != '\n' && ch != EOF)
                    ;

                // 检查用户名是否为空
                if (strlen(Username) == 0)
                {
                    printf("用户名不能为空！\n");
                    sleep(1);
                    continue;
                }

                // 比较两次输入的密码
                if (strcmp(PassWord, PassWordEctype) == 0)
                {

                    // 创建用户
                    user = create_user(Username, PassWord);
                    if (user != NULL)
                    {
                        // 创建用户链表头节点
                        // User *uhead = create_user("", "");
                        // 这里需要把用户添加到全局链表中
                        list_add(&user->list, &uhead->list);
                        printf("用户 %s 注册成功！\n", Username);
                        sleep(1);
                        return;
                    }
                    else
                    {
                        printf("用户创建失败！\n");
                        sleep(1);
                        continue;
                    }
                }
                else
                {
                    printf("两次密码不一致，请重新输入！\n");
                    sleep(1);
                    continue;
                }
            }
            break;
        }
        default:
            break;
        }
    }
}

// 用户登陆界面
void user_login_menu(FlightSystem *s)
{
    char userLoginName[20];
    char userLoginPasd[20];

    while (1)
    {
        printf("请输入用户账号:\n");
        scanf("%s", userLoginName);
        printf("请输入用户密码:\n");
        scanf("%s", userLoginPasd);
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF)
            ;
        User *pos;
        list_for_each_entry(pos, &uhead->list, list)
        {
            if ((strcmp(pos->username, userLoginName) == 0) && strcmp(pos->password, userLoginPasd) == 0)
            {
                printf("用户 %s 登录了!! \n", userLoginName);
                sleep(1);
                user_menu(s);
                return;
            }
        }
        sleep(1);
        printf("用户名或密码错误,请重新登陆或注册用户!\n");
        return;
    }

    printf("\n");
}

// 用户菜单变量
enum USERMENU
{
    USER_FLIGHT_INFO = 1,
    USER_FLIGHT_SUBSCRUBE,
    USER_DEL_SUBSCRUBE,
    USER_LOOK_SUBSCRUBE,
    USER_LOG_OUT_DEL,
};

// 用户菜单
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
        printf("5. 注销用户\n");
        printf("6. 退出登录\n");
        printf("请选择: ");
        int selected = 0;

        scanf("%d", &selected);

        switch (selected)
        {
        case USER_FLIGHT_INFO:
            displayFlightInfoUser(s);
            break;
        case USER_FLIGHT_SUBSCRUBE:
        {
            int subFlag;
            subFlag = user_filght_subscribe(s);
            if (subFlag == 1 && user != NULL)
            {
                // user_filght_subscribe(s);
                user_subscribe(user, flight_number);
                sleep(1);
            }
            break;
        }

        case USER_DEL_SUBSCRUBE:
        {
            if (user_filght_del_subscribe(s) == 1)
            { // 成功修改航班系统
                // 再安全删除用户端的预订记录
                if (user_del_subscribe(user, flight_number) == 0)
                {
                    printf("警告：用户预订记录删除失败，但航班座位已释放！\n");
                }
            }
            sleep(1);
            break;
        }

        case USER_LOOK_SUBSCRUBE:
            user_look_flight(user);
            break;

        case USER_LOG_OUT_DEL:
        {
            char user_scan_name[20];
            printf("请输入待注销的用户!\n");
            scanf("%s", user_scan_name);
            int c1;
            while ((c1 = getchar()) != '\n' && c1 != EOF)
                ;
            if (user_logout(user, user_scan_name))
            {
                printf("注销成功!");
            }
            main_menu(s);
        }

        default:
            printf("退出成功!\n");
            return;
            break;
        }
    }
}
// 管理员登陆页面
void admin_login_menu(FlightSystem *s)
{
    char adminLoginName[20];
    char amdinLoginPasd[20];
    while (1)
    {
        printf("请输入管理员账号:\n");
        scanf("%s", adminLoginName);
        printf("请输入管理员密码:\n");
        scanf("%s", amdinLoginPasd);
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF)
            ;
        if ((strcmp(AdminName, adminLoginName) == 0) && strcmp(AdminPassWord, amdinLoginPasd) == 0)
        {
            printf("管理员 %s 登录了!! \n", adminLoginName);
            sleep(1);
            admin_menu(s);
            return;
        }
        sleep(1);
        printf("用户名或密码错误,请重新登陆或注册用户!\n");
        return;
    }
    printf("\n");
}

// 管理员菜单变量
enum ADMINMENU
{
    ADMIN_WRITE_ADD = 1,
    ADMIN_UPDATA,
    ADMIN_DEL,
    ADMIN_FLIGHT_FIND,
    ADMIN_USER_FIND,
    ADMIN_LOG_OUT,
};

// 管理员菜单
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
        printf("5. 用户查询 \n");
        printf("6. 退出登录\n");
        printf("请选择: ");
        int selected = 0;

        scanf("%d", &selected);

        switch (selected)
        {
        case ADMIN_WRITE_ADD:
            add_filght(s);
            break;
        case ADMIN_UPDATA:
            printf("请输入需要更新的航班号： \n");
            char flight_number_updata[20];
            scanf("%s", flight_number_updata);
            update_filght_info(s, flight_number_updata);
            break;
        case ADMIN_DEL: // 删除航班
            printf("请输入需要删除的航班号： \n");
            char flight_number_del[20];
            scanf("%s", flight_number_del);
            delete_filght(s, flight_number_del);
            printf("航班删除成功 \n");
            sleep(1);
            break;

        case ADMIN_FLIGHT_FIND:
            displayFlightInfo(s);
            break;
        case ADMIN_USER_FIND:
        {
            // 查询已经注册的用户   -----------------------------后续需要放进管理员用户权限中;
            system("clear");
            // 检查链表头是否已初始化
            if (uhead == NULL)
            {
                printf("用户链表未初始化，没有用户数据！\n");
            }
            else if (list_empty(&uhead->list))
            {
                printf("当前没有注册用户！\n");
            }
            else
            {
                printf("已注册用户列表：\n");
                struct list_head *pos;
                int count = 1;
                list_for_each(pos, &uhead->list)
                {
                    User *user = list_entry(pos, User, list);
                    printf("%d. 用户名：%s\n", count++, user->username);
                }
            }
            printf("按任意键继续...");
            getchar();
            getchar();
            break;
        }
        case ADMIN_LOG_OUT:
            return;
        default:
            break;
        }
    }
}
