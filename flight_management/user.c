#include "user.h"

// 用户注册
int user_register(User *users, const char *username, const char *password)
{
    printf("用户 %s 注册了!! \n", username);
    return 1;
}

// 用户登录
int user_login(User *users, const char *username, const char *password)
{
    printf("用户 %s 登录了!! \n", username);
    return 1;
}

// 用户注销
int user_logout(User *users, const char *username)
{
    printf("用户 %s 注销了!! \n", username);
    return 1;
}