#include "admin.h"

char AdminName[20] = "admin";
char AdminPassWord[20] = "123456";

// 航班信息录入
int add_filght(FlightSystem *system)
{
    printf("录入成功\n");
    return 1;
}
// 航班信息更新
int update_filght_info(FlightSystem *system, const char *flight_number)
{
    printf("更新成功 \n");
    return 1;
}

// 航班删除
int delete_filght(FlightSystem *system, const char *flight_number)
{
    printf("航班删除成功 \n");
    return 1;
}

// 用户航班预定查询
// // 查看用户所有预订
// void user_show_subscribes(User *user)
// {
//     if (user == NULL)
//     {
//         printf("用户不存在！\n");
//         return;
//     }
//     system("clear");
//     printf("\n=== %s 的航班预订记录 ===\n", user->username);
//     if (list_empty(&user->subscribe_list))
//     {
//         printf("暂无预订记录！\n");
//         return;
//     }
//     int count = 1;
//     UserSubscribe *pos;
//     list_for_each_entry(pos, &user->subscribe_list, list)
//     {
//         printf("\n%d. 航班号: %s\n", count++);
//         printf("   预订时间: %d-%02d-%02d %02d:%02d\n",
//                pos->subscribe_time.year, pos->subscribe_time.month,
//                pos->subscribe_time.day, pos->subscribe_time.hour,
//                pos->subscribe_time.minute);
//         char *status_str;
//         switch (pos->status)
//         {
//         case 0:
//             status_str = "已预订";
//             break;
//         case 1:
//             status_str = "已使用";
//             break;
//         case 2:
//             status_str = "已取消";
//             break;
//         default:
//             status_str = "未知状态";
//         }
//         printf("   状态: %s\n", status_str);
//     }
//     printf("\n按任意键继续...");
//     getchar();
//     getchar();
// }
