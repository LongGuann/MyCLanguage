#ifndef _INC_USER
#define _INC_USER
#include "common.h"

// 用户信息记录
typedef struct user
{
    char username[20];
    char password[20];

    struct list_head subscribe_list;
    struct list_head list;
} User;

// 用户航班号信息
typedef struct user_subscribe
{
    char flight_number[20]; // 预订的航班号
    int status;             // 0:已预订 1:已使用 2:已取消
    struct list_head list;  // 链表关系指针
} UserSubscribe;

User *create_user(const char *username, const char *password);

// 用户注册
int user_register(User *users, const char *username, const char *password);

// 登录注册
int user_login(User *users, const char *username, const char *password);

// 用户注销
int user_logout(User *users, const char *username);

// 用户航班预定
int user_subscribe(User *users, const char *flight_number);

// 用户航班取消预定
int user_del_subscribe(User *users, const char *flight_number);

// 用户航班查询
int user_look_flight(User *users);

#endif