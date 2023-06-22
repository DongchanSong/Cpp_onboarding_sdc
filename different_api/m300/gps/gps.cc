//
// Created by jhbai on 23. 4. 25.
//

#include "gps.h"
#include <cstdlib>
#include <time.h>

M300Gps::M300Gps() {}
M300Gps::~M300Gps() {}

float M300Gps::GetGpsNum() {
    srand(time(0));
    return rand() % 20 + 1;
}

M300Gps::GPS_HEALTH M300Gps::GetGpsHealth() {
    srand(time(0));
    return M300Gps::GPS_HEALTH(rand() % 2 + 1);
}

M300Gps::RTK_CONNECTION M300Gps::GetRtkConnection() {
    srand(time(0));
    return M300Gps::RTK_CONNECTION(rand() % 1 + 1);
}