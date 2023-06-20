//
// Created by jhbai on 23. 05. 09.
//

#include "gps.h"
#include <cstdlib>
#include <time.h>

SkydioGps::SkydioGps() {}
SkydioGps::~SkydioGps() {}

float SkydioGps::GetGpsNum() {
    srand(time(0));
    return rand() % 20 + 1;
}

SkydioGps::GPS_HEALTH SkydioGps::GetGpsHealth() {
    srand(time(0));
    return SkydioGps::GPS_HEALTH(rand() % 2 + 1);
}