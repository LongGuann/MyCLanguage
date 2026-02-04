#include "user.h"
// #include "flight.h"
//  创建新的用户节点
User *create_user(const char *username, const char *password)
{
    User *u = malloc(sizeof(User));
    if (u == NULL)
    {
        perror("create_node failed!\n");
        return NULL;
    }
    // 指针初始化只需要直接调用内核提供的宏
    strncpy(u->username, username, sizeof(u->username) - 1);
    strncpy(u->password, password, sizeof(u->password) - 1);

    INIT_LIST_HEAD(&u->subscribe_list);
    INIT_LIST_HEAD(&u->list);
    return u;
}

// 创建预订记录
UserSubscribe *create_subscribe(const char *flight_number)
{
    UserSubscribe *us = malloc(sizeof(UserSubscribe));
    if (us == NULL)
    {
        perror("create_subscribe failed!\n");
        return NULL;
    }

    strncpy(us->flight_number, flight_number, sizeof(us->flight_number) - 1);

    us->status = 0; // 0:已预订

    INIT_LIST_HEAD(&us->list);
    return us;
}

// 用户注册
int user_register(User *users, const char *username, const char *password)
{

    printf("用户 %s 注册了!! \n", username);
    return 1;
}

// 用户登录
int user_login(User *users, const char *username, const char *password)
{
    // User *pos;
    // list_for_each_entry(pos, &uhead->list, list)
    // {
    //     if ((strcmp(->username, username) == 0) && strcmp(user->password, password) == 0)
    //     {
    //         printf("用户 %s 登录了!! \n", username);
    //         return 1;
    //     }
    // }
    printf("\n");
    return 0;
}

// 用户注销
int user_logout(User *users, const char *username)
{
    struct list_head *head = &(users->list);
    User *pos, *n;
    User *use = NULL;
    list_for_each_entry_safe(pos, n, head, list)
    {
        printf("%s 注销中", pos->username);
        if (strcmp(pos->username, username) == 0)
        {
            list_del(&pos->list);
            use = pos;
            free(pos);
            return 1;
        }
    }
    if (use == NULL)
    {
        printf("未找到用户 %s \n", username);
        sleep(1);
        return -1;
    }
}

// 用户航班预定
int user_subscribe(User *users, const char *flight_number)
{
    if (users == NULL || flight_number == NULL)
    {
        return 0;
    }

    UserSubscribe *pos;
    list_for_each_entry(pos, &users->subscribe_list, list)
    {
        if (strcmp(pos->flight_number, flight_number) == 0 && pos->status == 0)
        {
            printf("您已经预订过该航班！\n");
            return 0;
        }
    }

    UserSubscribe *us = create_subscribe(flight_number);
    if (us == NULL)
    {
        return 0;
    }

    list_add_tail(&us->list, &users->subscribe_list);
    printf("恭喜%s,，您已成功预订航班 %s\n", users->username, flight_number);

    return 1;
}

// 用户航班取消预定
int user_del_subscribe(User *users, const char *flight_number)
{
    if (users == NULL || flight_number == NULL)
    {
        return 0;
    }

    UserSubscribe *pos, *n;
    int found = 0;
    list_for_each_entry_safe(pos, n, &users->subscribe_list, list)
    {
        if (strcmp(pos->flight_number, flight_number) == 0)
        {
            if (pos->status == 0)
            {                    // 只有已预订状态可以取消
                pos->status = 2; // 取消预定
                list_del(&pos->list);

                free(pos);
                printf("已成功取消航班 %s 的预订\n", flight_number);
                return 1;
            }
            else
            {
                printf("该航班预订状态异常（%s),无法取消！\n",
                       pos->status == 1 ? "已使用" : "已取消");
                return 0;
            }
            found = 1;
        }
    }
    if (!found)
    {
        printf("未找到航班号 %s 的有效预订记录！\n", flight_number);
        return 0;
    }
    return 0;
}

// 用户航班查询
int user_look_flight(User *users)
{
    system("clear");
    printf("\n========== %s 的航班预订记录 ==========\n", users->username);
    printf(" %s | %s\n", "序号", "航班号");
    printf("-----|------------\n");

    if (list_empty(&users->subscribe_list))
    {
        printf("暂无任何预订记录！\n");
        printf("\n按任意键返回...");
        getchar();
        getchar();
        return 0;
    }

    int count = 1;
    UserSubscribe *pos;
    int flag_flight_look = 0;

    list_for_each_entry(pos, &users->subscribe_list, list)
    {
        flag_flight_look = 1;

        printf(" %d | %s\n", count++, pos->flight_number);
    }

    if (!flag_flight_look)
    {
        printf("暂无有效预订记录！\n");
    }

    printf("=========================================\n");
    printf("按任意键返回...");
    getchar();
    getchar();
    return 1;
}

// 查找用户
// User *find_user_by_name(const char *username)
// {
//     if (uhead == NULL || username == NULL)
//     {
//         return NULL;
//     }
//     User *pos;
//     list_for_each_entry(pos, &uhead->list, list)
//     {
//         if (strcmp(pos->username, username) == 0)
//         {
//             return pos;
//         }
//     }
//     return NULL;
// }
