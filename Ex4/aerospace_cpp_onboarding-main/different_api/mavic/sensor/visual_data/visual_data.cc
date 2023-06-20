//
// Created by jhbai on 23. 05. 08.
//

#include "sensor/visual_data/visual_data.h"
#include <cstdlib>
#include <time.h>

MavicVisualData::MavicVisualData() {}
MavicVisualData::~MavicVisualData() {}

float MavicVisualData::GetVisualDepth() {
    srand(time(0));
    float temp = (float) rand()/RAND_MAX * 12.0f - 5.0f;
    if (temp > 0.0f)
        return temp;
    else 
        return -1;
}

MavicVisualData::Point MavicVisualData::GetDepthPoint() {
    srand(time(0));
    int tempX = (float) rand()/RAND_MAX * 1000.0f - 360.0f;
    int tempY = (float) rand()/RAND_MAX * 652.8f - 172.8f;
    if (tempX > 0.0f)
        return MavicVisualData::Point{tempX, std::abs(tempY)};
    else 
        return MavicVisualData::Point{-1, -1};
}