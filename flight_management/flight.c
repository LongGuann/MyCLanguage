#include "flight.h"

Flight *newFilght(char *flight_number,  // 航班号
                  char *destination,    // 终点站
                  char *departure_city, // 始发站
                  float price,          // 价格
                  int total_seats,      // 座位数
                  DateTime departure_time)
{
    Flight *f = malloc(sizeof(Flight));
    if (f == NULL)
    {
        perror("newFilght failed!\n");
        return NULL;
    }

    strcpy(f->flight_number, flight_number);
    strcpy(f->destination, destination);
    strcpy(f->departure_city, departure_city);
    f->departure_time = departure_time;
    f->price = price;
    f->total_seats = total_seats;
    f->remaining_seats = total_seats;
    f->flight_status = 0;
    return f;
}

// 枚举结构体 用来表示选择航班查询条件
enum FLIGHTINFO
{
    FLIGHT_NUMBER = 1,
    FLIGHT_DEPARTURE,
    FLIGHT_DESTINATION,
    FLIGHT_TIME,
    FLIGHT_PRICE,
    FLIGHT_ALL,
};

FlightSystem *initFilghtSystem()
{
    DateTime time = {};
    Flight *head = newFilght("", "", "", 0, 0, time);
    INIT_LIST_HEAD(&head->list);

    FlightSystem *s = malloc(sizeof(FlightSystem));
    if (s == NULL)
    {
        perror("initFilght failed! \n");
        free(head);
        return NULL;
    }

    s->flights = head;
    s->flight_count = 0;
    return s;
}
// 航班查询
void displayFlightInfo(FlightSystem *s)
{

    system("clear");

    if (s->flight_count == 0)
    {
        printf("今日暂无航班信息!\n");
        sleep(2);
        return;
    }

    struct list_head *head = &(s->flights->list);
    Flight *p;
    list_for_each_entry(p, head, list)
    {
        printf("航班号 %s \n", p->flight_number);
        printf("出发地 %s -> 目的地 %s \n", p->departure_city, p->destination);
        printf("本航班机票价格 %f元\n", p->price);
        printf("本次航班剩余 %d票\n", p->total_seats);
        printf("出发时间 %d年 %d月 %d日 %d时 %d分 \n", p->departure_time.year,
               p->departure_time.month,
               p->departure_time.day,
               p->departure_time.hour,
               p->departure_time.minute);
        printf("-------------------------\n");
    }

    printf("按Q退出查看!\n");
    char ch = 0;
    while (1)
    {
        scanf("%c", &ch);
        if (ch == 'Q' || ch == 'q')
        {
            return;
        }
    }
}

// 航班查询 - 航班号版本
void displayFlightInfoNumber(FlightSystem *s, char *flightNumber)
{
    system("clear");

    if (s->flight_count == 0)
    {
        printf("今日暂无航班信息!\n");
        sleep(2);
        return;
    }

    struct list_head *head = &(s->flights->list);
    Flight *p;
    list_for_each_entry(p, head, list)
    {
        if (strcmp(flightNumber, p->flight_number) == 0)
        {
            printf("航班号 %s \n", p->flight_number);
            printf("出发地 %s -> 目的地 %s \n", p->departure_city, p->destination);
            printf("本航班机票价格 %f元\n", p->price);
            printf("本次航班剩余 %d票\n", p->total_seats);
            printf("出发时间 %d年 %d月 %d日 %d时 %d分 \n", p->departure_time.year,
                   p->departure_time.month,
                   p->departure_time.day,
                   p->departure_time.hour,
                   p->departure_time.minute);
            printf("-------------------------\n");
        }
    }

    printf("按Q退出查看!\n");
    char ch = 0;
    while (1)
    {
        scanf("%c", &ch);
        if (ch == 'Q' || ch == 'q')
        {
            return;
        }
    }
}

// 航班查询 - 始发地版本
void displayFlightInfoDeparture(FlightSystem *s, char *departure)
{
    system("clear");

    if (s->flight_count == 0)
    {
        printf("今日暂无航班信息!\n");
        sleep(2);
        return;
    }

    struct list_head *head = &(s->flights->list);
    Flight *p;
    list_for_each_entry(p, head, list)
    {
        if (strcmp(departure, p->departure_city) == 0)
        {
            printf("航班号 %s \n", p->flight_number);
            printf("出发地 %s -> 目的地 %s \n", p->departure_city, p->destination);
            printf("本航班机票价格 %f元\n", p->price);
            printf("本次航班剩余 %d票\n", p->total_seats);
            printf("出发时间 %d年 %d月 %d日 %d时 %d分 \n", p->departure_time.year,
                   p->departure_time.month,
                   p->departure_time.day,
                   p->departure_time.hour,
                   p->departure_time.minute);
            printf("-------------------------\n");
        }
    }

    printf("按Q退出查看!\n");
    char ch = 0;
    while (1)
    {
        scanf("%c", &ch);
        if (ch == 'Q' || ch == 'q')
        {
            return;
        }
    }
}

// 航班查询 - 目的地版本
void displayFlightInfoDestination(FlightSystem *s, char *destination)
{
    system("clear");

    if (s->flight_count == 0)
    {
        printf("今日暂无航班信息!\n");
        sleep(2);
        return;
    }

    struct list_head *head = &(s->flights->list);
    Flight *p;
    list_for_each_entry(p, head, list)
    {
        if (strcmp(destination, p->destination) == 0)
        {
            printf("航班号 %s \n", p->flight_number);
            printf("出发地 %s -> 目的地 %s \n", p->departure_city, p->destination);
            printf("本航班机票价格 %f元\n", p->price);
            printf("本次航班剩余 %d票\n", p->total_seats);
            printf("出发时间 %d年 %d月 %d日 %d时 %d分 \n", p->departure_time.year,
                   p->departure_time.month,
                   p->departure_time.day,
                   p->departure_time.hour,
                   p->departure_time.minute);
            printf("-------------------------\n");
        }
    }

    printf("按Q退出查看!\n");
    char ch = 0;
    while (1)
    {
        scanf("%c", &ch);
        if (ch == 'Q' || ch == 'q')
        {
            return;
        }
    }
}

// 航班查询 - 时间版
void displayFlightInfoTime(FlightSystem *s, DateTime data)
{
    system("clear");

    if (s->flight_count == 0)
    {
        printf("今日暂无航班信息!\n");
        sleep(2);
        return;
    }

    struct list_head *head = &(s->flights->list);
    Flight *p;
    list_for_each_entry(p, head, list)
    {
        if (data.day == p->departure_time.day && data.month == p->departure_time.month && data.year == p->departure_time.year)
        {
            printf("航班号 %s \n", p->flight_number);
            printf("出发地 %s -> 目的地 %s \n", p->departure_city, p->destination);
            printf("本航班机票价格 %f元\n", p->price);
            printf("本次航班剩余 %d票\n", p->total_seats);
            printf("出发时间 %d年 %d月 %d日 %d时 %d分 \n", p->departure_time.year,
                   p->departure_time.month,
                   p->departure_time.day,
                   p->departure_time.hour,
                   p->departure_time.minute);
            printf("-------------------------\n");
        }
    }

    printf("按Q退出查看!\n");
    char ch = 0;
    while (1)
    {
        scanf("%c", &ch);
        if (ch == 'Q' || ch == 'q')
        {
            return;
        }
    }
}

// 航班查询 - 价格版
void displayFlightInfoFrice(FlightSystem *s, float price)
{
    system("clear");

    if (s->flight_count == 0)
    {
        printf("今日暂无航班信息!\n");
        sleep(2);
        return;
    }

    struct list_head *head = &(s->flights->list);
    Flight *p;
    float price_max = price + 200;
    float price_min = price - 200;

    list_for_each_entry(p, head, list)
    {
        if (p->price >= price_min && p->price <= price_max)
        {
            printf("航班号 %s \n", p->flight_number);
            printf("出发地 %s -> 目的地 %s \n", p->departure_city, p->destination);
            printf("本航班机票价格 %f元\n", p->price);
            printf("本次航班剩余 %d票\n", p->total_seats);
            printf("出发时间 %d年 %d月 %d日 %d时 %d分 \n", p->departure_time.year,
                   p->departure_time.month,
                   p->departure_time.day,
                   p->departure_time.hour,
                   p->departure_time.minute);
            printf("-------------------------\n");
        }
    }

    printf("按Q退出查看!\n");
    char ch = 0;
    while (1)
    {
        scanf("%c", &ch);
        if (ch == 'Q' || ch == 'q')
        {
            return;
        }
    }
}

// 航班查询用户多样版本
void displayFlightInfoUser(FlightSystem *s)
{
    while (1)
    {
        enum FLIGHTINFO selected;
        // 每次打印内清下屏幕
        system("clear");

        printf("\n=== 航班信息查询系统======\n");
        printf("1. 航班号查询 \n");
        printf("2. 航班始发站查询 \n");
        printf("3. 航班目的地查询 \n");
        printf("4. 航班出发时间查询 \n");
        printf("5. 航班价格查询 \n");
        printf("6. 所有航班\n");
        printf("7. 退出查询 \n");

        printf("请选择: ");
        scanf("%d", (int *)&selected);

        switch (selected)
        {
        case FLIGHT_NUMBER: // 航班号查询
            system("clear");
            printf("请输入航班号 \n");
            char ch_num[20];
            scanf("%s", ch_num);

            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            displayFlightInfoNumber(s, ch_num);
            break;
        case FLIGHT_DEPARTURE: // 航班始发站查询
            system("clear");
            printf("请输入始发站 \n");
            char ch_departure[20];
            scanf("%s", ch_departure);

            while ((c = getchar()) != '\n' && c != EOF)
                ;
            displayFlightInfoDeparture(s, ch_departure);
            break;
        case FLIGHT_DESTINATION: // 航班目的地查询
            system("clear");
            printf("请输入目的地 \n");
            char ch_destination[20];
            scanf("%s", ch_destination);

            while ((c = getchar()) != '\n' && c != EOF)
                ;
            displayFlightInfoDestination(s, ch_destination);

            break;
        case FLIGHT_TIME: // 航班出发时间查询
            system("clear");
            DateTime ch_time;
            printf("请输入出发时间 \n");

            scanf("%d %d %d", &ch_time.year, &ch_time.month, &ch_time.day);

            while ((c = getchar()) != '\n' && c != EOF)
                ;
            displayFlightInfoTime(s, ch_time);

            break;
        case FLIGHT_PRICE: // 航班价格查询
            system("clear");
            float ch_frice;
            printf("请输入机票价格 \n");

            scanf("%f", &ch_frice);

            while ((c = getchar()) != '\n' && c != EOF)
                ;
            displayFlightInfoFrice(s, ch_frice);

            break;
        case FLIGHT_ALL:
            system("clear");
            displayFlightInfo(s);
            break;
        default:
            return;
            break;
        }
    }
}

// 航班预定 - 用户
int user_filght_subscribe(FlightSystem *s)
{
    system("clear");
    while (1)
    {

        char flightNUmber[20];
        printf("请输入要预定的航班号: ");
        scanf("%s", flightNUmber);
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;
        struct list_head *head = &(s->flights->list);
        Flight *p;

        list_for_each_entry(p, head, list)
        {
            if (strcmp(flightNUmber, p->flight_number) == 0)
            {
                if (p->remaining_seats > 0)
                {

                    p->remaining_seats--;
                    p->total_seats--;
                    printf("成功预定了航班号为%s的航班 \n", flightNUmber);
                    return 1;
                }
                else if (p->remaining_seats == 0)
                {
                    printf("航班预定失败,该航班已经满座");
                    return 0;
                }
            }
        }
    }
}

// 航班取消预定 - 用户
int user_filght_del_subscribe(FlightSystem *s)
{
    system("clear");
    while (1)
    {

        char flightNUmber[20];
        printf("请输入要取消的航班号: ");
        scanf("%s", flightNUmber);
        int c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;
        struct list_head *head = &(s->flights->list);
        Flight *p;

        list_for_each_entry(p, head, list)
        {
            if (strcmp(flightNUmber, p->flight_number) == 0)
            {

                p->remaining_seats++;
                p->total_seats++;
                printf("成功取消了航班号为%s的航班 \n", flightNUmber);
                return 1;
            }
        }
        printf("未查询到该趟航班的预定信息,请重新输入");
        return 0;
    }
}

// 航班预定查询 - 用户
void user_filght_look(FlightSystem *s)
{
}

// 航班数据
void moco_data(FlightSystem *s)
{
    DateTime date = {
        .year = 2026,  // 年
        .month = 2,    // 月
        .day = 10,     // 日
        .hour = 9,     // 时
        .minute = 45}; // 分

    Flight *f = newFilght("NH3601", "北京", "广州", 900, 0, date);
    f->remaining_seats = f->total_seats;
    f->remaining_seats = 0;
    list_add_tail(&f->list, &(s->flights->list));

    s->flight_count++;

    date.hour = 10;

    f = newFilght("NH3602", "上海", "广州", 400, 400, date);
    f->remaining_seats = f->total_seats;
    list_add_tail(&f->list, &(s->flights->list));
    s->flight_count++;

    date.hour = 11;

    f = newFilght("NH3603", "呼和浩特", "广州", 300, 300, date);
    f->remaining_seats = f->total_seats;
    list_add_tail(&f->list, &(s->flights->list));

    s->flight_count++;

    date.hour = 12;

    f = newFilght("NH3607", "乌鲁木齐", "广州", 200, 200, date);
    f->remaining_seats = f->total_seats;
    list_add_tail(&f->list, &(s->flights->list));
    s->flight_count++;
}
