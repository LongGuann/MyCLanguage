#include "admin.h"

char AdminName[20] = "admin";
char AdminPassWord[20] = "123456";

// 更新输入缓冲区
static void clear_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

// 验证时间有效性
static int is_datetime(int year, int month, int day, int hour, int minute)
{
    if (month < 1 || month > 12)
        return 0;
    if (day < 1 || day > 31)
        return 0; // 简化验证
    if (hour < 0 || hour > 23)
        return 0;
    if (minute < 0 || minute > 59)
        return 0;
    return 1;
}

// 检查航班号是否已存在
static int flight_number_exists(FlightSystem *s, const char *flight_num)
{
    if (s == NULL || s->flights == NULL || flight_num == NULL)
        return 0;

    Flight *p;
    list_for_each_entry(p, &s->flights->list, list)
    {
        if (strcmp(p->flight_number, flight_num) == 0)
        {
            return 1;
        }
    }
    return 0;
}

// 航班信息录入
void add_filght(FlightSystem *s)
{
    if (s == NULL || s->flights == NULL)
    {
        printf("航班未初始化!,请管理员初始化航班\n");
        sleep(1);
        return;
    }
    system("clear");

    printf("--------------------\n");
    printf("请输入航班的录入信息\n");
    printf("--------------------\n");

    Flight *new_flight = malloc(sizeof(Flight));
    if (new_flight == NULL)
    {
        perror("nwe flight is failed!\n");
        return;
    }

    while (1) // 航班号录入
    {
        printf("请输入需要录入的航班号!\n");
        scanf("%s", new_flight->flight_number);
        clear_input_buffer();

        if (flight_number_exists(s, new_flight->flight_number))
        {
            printf("航班号 %s 已经存在,请重新录入! \n", new_flight->flight_number);
            continue;
        }
        break;
    }

    while (1) // 出发地录入
    {
        printf("请输入需要录入的航班出发地!\n");
        scanf("%s", new_flight->departure_city);
        clear_input_buffer();
        if (strlen(new_flight->departure_city) > 0)
        {
            break;
        }
        printf("出发地不能为空!\n");
    }

    while (1) // 目的地录入
    {
        printf("请输入需要录入的航班目的地!\n");
        scanf("%s", new_flight->destination);
        clear_input_buffer();
        if (strlen(new_flight->destination) > 0)
        {
            break;
        }
        printf("目的地不能为空!\n");
    }

    while (1) // 航班价格录入
    {
        printf("请输入本次航班的售卖票价!\n");
        scanf("%f", new_flight->price);
        clear_input_buffer();
        if (new_flight->price > 0)
        {
            break;
        }
        printf("票价不能小于零!\n");
    }

    while (1) // 出发时间录入
    {
        int year, month, day, hour, minute;

        printf("请输入航班的出发时间!\n");
        printf("月份\n");
        scanf("%d", &month);
        clear_input_buffer();
        printf("日期\n");
        scanf("%d", &day);
        clear_input_buffer();
        printf("小时\n");
        scanf("%d", &hour);
        clear_input_buffer();
        printf("分钟\n");
        scanf("%d", &minute);
        clear_input_buffer();

        if (is_datetime(year, month, day, hour, minute))
        {
            new_flight->departure_time.year = year;
            new_flight->departure_time.month = month;
            new_flight->departure_time.day = day;
            new_flight->departure_time.hour = hour;
            new_flight->departure_time.minute = minute;
            break;
        }
        else
        {
            printf(" 无效的日期时间！请重新输入\n\n");
        }
    }

    while (1) // 可用座位数录入
    {
        printf("请录入本次航班的可用座位数:\n");
        scanf("%d", &new_flight->total_seats);
        clear_input_buffer();

        if (new_flight->total_seats > 0)
        {
            new_flight->remaining_seats = new_flight->total_seats;
            break;
        }
        else
        {
            printf("输入的座位数不可用,请重新输入!\n\n");
        }

        INIT_LIST_HEAD(&new_flight->list);

        list_add_tail(&new_flight->list, &s->flights->list);

        s->flight_count++;
    }

    printf("航班录入已完成!\n");
    printf("本次录入的航班信息为\n");
    printf("------------------------");
    printf("航班号 %s \n", new_flight->flight_number);
    printf("出发地 %s -> 目的地 %s \n", new_flight->departure_city, new_flight->destination);
    printf("本航班机票价格 %f元\n", new_flight->price);
    printf("本次航班剩余 %d票\n", new_flight->total_seats);
    printf("出发时间 %d年 %d月 %d日 %d时 %d分 \n", new_flight->departure_time.year,
           new_flight->departure_time.month,
           new_flight->departure_time.day,
           new_flight->departure_time.hour,
           new_flight->departure_time.minute);
    printf("-------------------------\n");
    printf("\n按任意键返回菜单...");
    getchar();
}
// 航班信息更新
int update_filght_info(FlightSystem *s, const char *flight_number)
{
    if (s == NULL || s->flights == NULL)
    {
        printf("航班未初始化!,请管理员初始化航班\n");
        sleep(1);
        return;
    }
    system("clear");

    printf("--------------------\n");
    printf("请输入航班的录入信息\n");
    printf("--------------------\n");

    struct list_head *head = &(s->flights->list);
    Flight *p;

    list_for_each_entry(p, head, list)
    {
    }
    printf("更新成功 \n");
    return 1;
}

// 航班删除
int delete_filght(FlightSystem *s, const char *flight_number)
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
