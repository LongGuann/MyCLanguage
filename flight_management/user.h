#ifndef _INC_USER
#define _INC_USER
#include "common.h"

typedef struct
{
    char username[20];
    char password[20];
    struct list_head *list;
} User;

// 用户注册
int user_register(User *users, const char *username, const char *password);

// 登录注册
int user_login(User *users, const char *username, const char *password);

// 用户注销
int user_logout(User *users, const char *username);

#endif