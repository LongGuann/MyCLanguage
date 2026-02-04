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
        scanf("%f", &new_flight->price);
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
void update_filght_info(FlightSystem *s, const char *flight_number)
{
    if (s == NULL || s->flights == NULL)
    {
        printf("航班未初始化!,请管理员初始化航班\n");
        sleep(1);
        return;
    }
    system("clear");

    // 先查找航班是否存在
    struct list_head *head = &(s->flights->list);
    Flight *flight = NULL;
    Flight *p;

    list_for_each_entry(p, head, list)
    {
        if (strcmp(p->flight_number, flight_number) == 0)
        {
            flight = p;
            break;
        }
    }

    if (flight == NULL)
    {
        printf("未找到航班号为 %s 的航班\n", flight_number);
        return;
    }
    system("clear");
    printf("当前航班信息：\n");
    printf("航班号: %s\n", flight->flight_number);
    printf("出发地: %s\n", flight->departure_city);
    printf("目的地: %s\n", flight->destination);
    printf("价格: %f\n", flight->price);
    printf("总座位数: %d\n", flight->total_seats);
    printf("剩余座位: %d\n", flight->remaining_seats);
    printf("出发时间: %d-%d-%d %d:%d\n",
           flight->departure_time.year,
           flight->departure_time.month,
           flight->departure_time.day,
           flight->departure_time.hour,
           flight->departure_time.minute);

    printf("-----请选择需要更新的航班信息！-----\n");
    printf("1. 航班号更新 : \n");
    printf("2. 航班出发地更新 : \n");
    printf("3. 航班目的地更新 : \n");
    printf("4. 航班价格更新 : \n");
    printf("5. 航班出发时间更新 : \n");
    printf("6. 航班可售座位数更新 : \n");
    printf("7. 退出航班更新信息系统\n");

    int selected;
    scanf("%d", &selected);
    switch (selected)
    {
    case 1: //  航班号修改
    {
        char new_number[20];
        printf("请输入需要更新成为的航班号！\n");
        scanf("%s", new_number);
        clear_input_buffer();
        updata_flight_info_number(s, flight->flight_number, new_number);
        break;
    }

    case 2: // 出发地修改
    {
        char new_departurecity[20];
        printf("请输入新的出发地\n");
        scanf("%s", new_departurecity);
        clear_input_buffer();
        updata_flight_info_departurecity(s, flight->departure_city, new_departurecity);
        break;
    }

    case 3: // 目的地修改
    {
        char new_destination[20];
        printf("请输入新的目的地\n");
        scanf("%s", new_destination);
        clear_input_buffer();
        updata_flight_info_departurecity(s, flight->destination, new_destination);
        break;
    }

    case 4: // 价格修改
    {
        float new_price;
        printf("请输入新的票价\n");
        scanf("%f", &new_price);
        clear_input_buffer();
        updata_flight_info_pirce(s, flight->price, new_price);
        break;
    }

    case 5: // 出发时间修改
    {
        DateTime new_time;
        printf("请输入新的出发时间（年 月 日 时 分）: ");
        scanf("%d %d %d %d %d",
              &new_time.year, &new_time.month, &new_time.day,
              &new_time.hour, &new_time.minute);
        clear_input_buffer();

        flight->departure_time = new_time;
        printf("出发时间已更新\n");
        break;
    }

    case 6: // 可售票数更改
    {
        int new_total;
        printf("请输入新的总座位数: ");
        scanf("%d", &new_total);
        clear_input_buffer();
        int seat_difference = new_total - flight->total_seats;
        flight->total_seats = new_total;
        flight->remaining_seats += seat_difference;

        if (flight->remaining_seats < 0)
        {
            flight->remaining_seats = 0;
        }

        printf("总座位数已更新为: %d\n", new_total);
        break;
    }
    case 7:
        /* code */
        return;

    default:
        break;
    }

    printf("更新成功 \n");
    printf("航班更新已完成!\n");
    printf("本次更新的航班信息为\n");
    printf("------------------------");
    printf("航班号 %s \n", flight->flight_number);
    printf("当前航班信息：\n");
    printf("航班号: %s\n", flight->flight_number);
    printf("出发地: %s\n", flight->departure_city);
    printf("目的地: %s\n", flight->destination);
    printf("价格: %f\n", flight->price);
    printf("总座位数: %d\n", flight->total_seats);
    printf("剩余座位: %d\n", flight->remaining_seats);
    printf("出发时间: %d-%d-%d %d:%d\n",
           flight->departure_time.year,
           flight->departure_time.month,
           flight->departure_time.day,
           flight->departure_time.hour,
           flight->departure_time.minute);
    printf("-------------------------\n");
    printf("\n按任意键返回菜单...");
    getchar();
    return;
}

// 航班信息更新  -- 航班号
void updata_flight_info_number(FlightSystem *s, char *flight_number, char *new_number)
{
    if (s == NULL || flight_number == NULL)
    {
        printf("错误，请初始化航班！\n");
        return;
    }
    struct list_head *head = &(s->flights->list);
    Flight *p;

    list_for_each_entry(p, head, list)
    {
        if (strcmp(p->flight_number, flight_number) == 0)
        {
            // 更新节点数据  // 航班号
            strncpy(p->flight_number, new_number, sizeof(p->flight_number) - 1);
            printf("已更新航班号%s  ---->  %s", flight_number, new_number);
            return;
        }
    }
}

// 航班信息修改  -- 出发地
void updata_flight_info_departurecity(FlightSystem *s, char *departure_city, char *new_city)
{
    if (s == NULL || departure_city == NULL)
    {
        printf("错误，请初始化航班！\n");
        return;
    }
    struct list_head *head = &(s->flights->list);
    Flight *p;

    list_for_each_entry(p, head, list)
    {
        if (strcmp(p->departure_city, new_city) == 0)
        {
            // 更新节点数据  // 航班号
            strncpy(p->departure_city, new_city, sizeof(p->departure_city) - 1);
            printf("已更新出发地%s  ---->  %s", departure_city, new_city);
            return;
        }
    }
}

// 航班信息更新  -- 目的地
void updata_flight_info_destination(FlightSystem *s, char *destination, char *new_destination)
{
    if (s == NULL || destination == NULL)
    {
        printf("错误，请初始化航班！\n");
        return;
    }
    struct list_head *head = &(s->flights->list);
    Flight *p;

    list_for_each_entry(p, head, list)
    {
        if (strcmp(p->destination, new_destination) == 0)
        {
            // 更新节点数据  // 航班号
            strncpy(p->destination, new_destination, sizeof(p->destination) - 1);
            printf("已更新目的地%s  ---->  %s", destination, new_destination);
            return;
        }
    }
}
// 航班信息更新  -- 价格
void updata_flight_info_pirce(FlightSystem *s, float flight_price, float new_price)
{
    if (s == NULL)
    {
        printf("错误，请初始化航班！\n");
        return;
    }
    struct list_head *head = &(s->flights->list);
    Flight *p;

    list_for_each_entry(p, head, list)
    {
        if (flight_price != new_price)
        {
            // 更新节点数据  // 航班号
            p->price = new_price;
            printf("已更新 价格%lf  ---->  %lf", flight_price, new_price);
            return;
        }
    }
}
// 航班信息更新  -- 出发时间
void updata_flight_info_time(FlightSystem *s, DateTime flight_time, DateTime new_time)
{
}
// 航班信息更新  -- 可售票数
void updata_flight_info_total(FlightSystem *s, int flight_total, int new_total)
{
}

// 航班删除
int delete_filght(FlightSystem *s, const char *flight_number)
{
    system("clear");
    if (s == NULL || s->flights == NULL)
    {
        printf("航班未初始化!,请管理员初始化航班\n");
        sleep(1);
        return -1;
    }

    // 先查找航班是否存在
    struct list_head *head = &(s->flights->list);
    Flight *flight = NULL;
    Flight *p;
    Flight *n;

    list_for_each_entry_safe(p, n, head, list)
    {
        printf("%s ", p->flight_number);
        if (strcmp(p->flight_number, flight_number) == 0)
        {
            list_del(&p->list);
            flight = p;
            free(p);
            return 1;
        }
    }
    printf("\n");
    if (flight == NULL)
    {
        printf("未找到航班号为 %s 的航班\n", flight_number);
        sleep(1);
        return -1;
    }
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
