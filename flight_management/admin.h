#ifndef _INC_ADMIN
#define _INC_ADMIN
#include "common.h"
#include "flight.h"

// 航班信息录入
int add_filght(FlightSystem * system);
// 航班信息更新
int update_filght_info(FlightSystem * system, const char * flight_number);

// 航班删除
int delete_filght(FlightSystem * system, const char * flight_number);
#endif