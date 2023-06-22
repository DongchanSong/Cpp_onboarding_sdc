//
// Created by jhbai on 23. 05. 08.
//

#include "gps.h"
#include <cstdlib>
#include <time.h>

MavicGps::MavicGps() {}
MavicGps::~MavicGps() {}

float MavicGps::GetGpsNum() {
    srand(time(0));
    return rand() % 20 + 1;
}

MavicGps::GPS_HEALTH MavicGps::GetGpsHealth() {
    srand(time(0));
    return MavicGps::GPS_HEALTH(rand() % 2 + 1);
}