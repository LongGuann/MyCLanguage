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
    printf("用户 %s 注销了!! \n", username);
    return 1;
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
    printf("恭喜%s\n", users->username);

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
    list_for_each_entry_safe(pos, n, &users->subscribe_list, list)
    {
        if (strcmp(pos->flight_number, flight_number) == 0)
        {
            if (pos->status == 0)
            {                    // 只有已预订状态可以取消
                pos->status = 2; // 取消预定
                list_del(&pos->list);
                free(pos);
                return 1;
            }
        }
    }
    printf("未找到该航班的预订记录或已使用/已取消！\n");
    return 0;
}

// 用户航班查询
int user_look_flight(User *users)
{
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
