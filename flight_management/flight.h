#ifndef _INC_FLIGHT
#define _INC_FLIGHT
#include "common.h"
// enum FLIGHT_STATUS {

// }
typedef struct
{
    int year;
    int month;
    int day;
    int hour;
    int minute;
} DateTime;

typedef struct flight
{
    char flight_number[20];  // 航班号
    char destination[20];    // 目的地
    char departure_city[20]; // 出发地
    float price;             // 票价
    int remaining_seats;     // 剩余座位
    int total_seats;         // 座位总量
    int flight_status;       // 0:正常 1:延误 2:取消
    DateTime departure_time; // 出发时间
    struct list_head list;   // 链表关系指针
} Flight;

// 管理航班的结构体
typedef struct
{
    Flight *flights;  // 大结构体头结点
    int flight_count; // 当日航班数量
} FlightSystem;

Flight *newFilght(char *flight_number,
                  char *destination,
                  char *departure_city,
                  float price,
                  int total_seats,
                  DateTime departure_time);

FlightSystem *initFilghtSystem();

void displayFlightInfo(FlightSystem *s);

void displayFlightInfoNumber(FlightSystem *s, char *flightNumber);

void displayFlightInfoUser(FlightSystem *s);

void moco_data(FlightSystem *s);

#endif