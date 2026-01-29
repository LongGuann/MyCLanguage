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