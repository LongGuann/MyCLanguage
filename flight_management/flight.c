#include "flight.h"

Flight *newFilght(char *flight_number,
                  char *destination,
                  char *departure_city,
                  float price,
                  int total_seats,
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

void moco_data(FlightSystem *s)
{
    DateTime date = {
        .year = 2026,
        .month = 2,
        .day = 10,
        .hour = 9,
        .minute = 45};

    Flight *f = newFilght("NH3601", "北京", "广州", 450, 300, date);

    list_add_tail(&f->list, &(s->flights->list));

    s->flight_count++;

    date.hour = 10;

    f = newFilght("NH3602", "上海", "广州", 450, 300, date);

    list_add_tail(&f->list, &(s->flights->list));
    s->flight_count++;

    date.hour = 11;

    f = newFilght("NH3603", "呼和浩特", "广州", 450, 300, date);

    list_add_tail(&f->list, &(s->flights->list));

    s->flight_count++;

    date.hour = 12;

    f = newFilght("NH3607", "乌鲁木齐", "广州", 450, 300, date);

    list_add_tail(&f->list, &(s->flights->list));
    s->flight_count++;
}