//
// Created by jhbai on 23. 05. 08.
//

#include "sensor/lidar_data/lidar_data.h"
#include <cstdlib>
#include <time.h>

MavicLidarData::MavicLidarData() {}
MavicLidarData::~MavicLidarData() {}

float MavicLidarData::GetTopLidarDistance() {
    srand(time(0));
    float temp = (float) rand()/RAND_MAX * 12.0f - 5.0f;
    if (temp > 0.0f)
        return temp;
    else 
        return -1;
}

float MavicLidarData::GetLeftLidarDistance() {
    srand(time(0));
    float temp = (float) rand()/RAND_MAX * 12.0f - 5.0f;
    if (temp > 0.0f)
        return temp;
    else 
        return -1;
}

float MavicLidarData::GetRightLidarDistance() {
    srand(time(0));
    float temp = (float) rand()/RAND_MAX * 12.0f - 5.0f;
    if (temp > 0.0f)
        return temp;
    else 
        return -1;
}

float MavicLidarData::GetBottomLidarDistance() {
    srand(time(0));
    float temp = (float) rand()/RAND_MAX * 12.0f - 5.0f;
    if (temp > 0.0f)
        return temp;
    else 
        return -1;
}