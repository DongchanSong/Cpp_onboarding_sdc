//
// Created by jhbai on 23. 05. 08.
//

#include "sensor_data.h"

M600SensorData::M600SensorData() {}
M600SensorData::~M600SensorData() {}

void M600SensorData::FillRow(std::vector<int> & row)
{
    std::generate(row.begin(), row.end(), [](){ return rand() % 256; }); 
}

void M600SensorData::FillMatrix(std::vector<std::vector<int>> & mat)
{
    std::for_each(mat.begin(), mat.end(), FillRow);
}

std::vector<std::vector<int>> M600SensorData::GetCameraData() {
    // Size of image (pixels)
    int x = 640;
    int y = 480;
  
    std::vector<std::vector<int>> image(x, std::vector<int>(y, 0));
    srand(time(0));
    FillMatrix(image);
    return image;
}

nlab::lib::Vector3f M600SensorData::GetGimbalData() {
    srand(time(0));
    return nlab::lib::Vector3f((float) rand()/RAND_MAX * 90.0f - 45.0f, (float) rand()/RAND_MAX * 240.0f - 120.0f, 0.0f);
}