#ifndef _INC_USER
#define _INC_USER
#include "common.h"

// // 声明全局变量
// extern User *uhead = NULL;
// extern User *user = NULL;
// extern char Username[20];
// extern char PassWord[20];
// extern char PassWordEctype[20];
typedef struct user
{
    char username[20];
    char password[20];
    struct list_head list;
} User;

User *create_user(const char *username, const char *password);

// 用户注册
int user_register(User *users, const char *username, const char *password);

// 登录注册
int user_login(User *users, const char *username, const char *password);

// 用户注销
int user_logout(User *users, const char *username);

#endif