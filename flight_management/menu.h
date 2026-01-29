#ifndef _INC_MENU
#define _INC_MENU
#include "common.h"
#include "user.h"
#include "flight.h"
#include "admin.h"

void main_menu(FlightSystem *s);

void user_login_menu(FlightSystem *s);

void user_register_menu(FlightSystem *s);

void user_menu(FlightSystem *s);

void admin_login_menu(FlightSystem *s);

void admin_menu(FlightSystem *s);

#endif