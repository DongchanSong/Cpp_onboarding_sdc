//
// Created by jhbai on 23. 05. 09.
//

#include "lidar.h"
#include <cstdlib>
#include <time.h>

SkydioLidar::SkydioLidar() {}
SkydioLidar::~SkydioLidar() {}

SkydioLidar::LIDAR_STATUS GetLidarStatus() {
    return SkydioLidar::LIDAR_STATUS(rand() % 3);
}

float SkydioLidar::GetForwardLidarDistance() {
    srand(time(0));
    float temp = (float) rand()/RAND_MAX * 12.0f - 5.0f;
    if (temp > 0.0f)
        return temp;
    else 
        return -1;
}