#ifndef _INC_ADMIN
#define _INC_ADMIN
#include "common.h"
#include "flight.h"

extern char AdminName[20];
extern char AdminPassWord[20];

// 航班信息录入
void add_filght(FlightSystem *s);
// 航班信息更新
void update_filght_info(FlightSystem *s, const char *flight_number);
void updata_flight_info_number(FlightSystem *s, char *flight_number, char *new_number);
void updata_flight_info_departurecity(FlightSystem *s, char *departure_city, char *new_city);
void updata_flight_info_destination(FlightSystem *s, char *destination, char *new_destination);
void updata_flight_info_pirce(FlightSystem *s, float flight_price, float new_price);
void updata_flight_info_time(FlightSystem *s, DateTime flight_time, DateTime new_time);
void updata_flight_info_total(FlightSystem *s, int flight_total, int new_total);
// 航班删除
int delete_filght(FlightSystem *s, const char *flight_number);

#endif