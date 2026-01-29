#include "user.h"

// 创建新的用户节点
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

    INIT_LIST_HEAD(&u->list);
    return u;
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
