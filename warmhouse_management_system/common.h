#ifndef _INC_COMMON
#define _INC_COMMON

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "kernel_list.h"
#include <time.h>

void menuout();
void clear_input_buffer();
int is_datetime(int year, int month, int day, int hour, int minute);

#endif
