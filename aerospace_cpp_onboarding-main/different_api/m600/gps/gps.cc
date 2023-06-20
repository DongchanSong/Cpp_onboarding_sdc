//
// Created by jhbai on 23. 05. 08.
//

#include "gps.h"
#include <cstdlib>
#include <time.h>

M600Gps::M600Gps() {}
M600Gps::~M600Gps() {}

float M600Gps::GetGpsNum() {
    srand(time(0));
    return rand() % 20 + 1;
}

M600Gps::GPS_HEALTH M600Gps::GetGpsHealth() {
    srand(time(0));
    return M600Gps::GPS_HEALTH(rand() % 2 + 1);
}

M600Gps::RTK_CONNECTION M600Gps::GetRtkConnection() {
    srand(time(0));
    return M600Gps::RTK_CONNECTION(rand() % 1 + 1);
}