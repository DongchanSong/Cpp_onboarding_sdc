//
// Created by jhbai on 23. 4. 25.
//

#include "sensor_data.h"

M300SensorData::M300SensorData() {}
M300SensorData::~M300SensorData() {}

void M300SensorData::FillRow(std::vector<int> & row)
{
    std::generate(row.begin(), row.end(), [](){ return rand() % 256; }); 
}

void M300SensorData::FillMatrix(std::vector<std::vector<int>> & mat)
{
    std::for_each(mat.begin(), mat.end(), FillRow);
}

std::vector<std::vector<int>> M300SensorData::GetCameraData() {
    // Size of image (pixels)
    int x = 640;
    int y = 480;
  
    std::vector<std::vector<int>> image(x, std::vector<int>(y, 0));
    srand(time(0));
    FillMatrix(image);
    return image;
}

nlab::lib::Vector3f M300SensorData::GetGimbalData() {
    srand(time(0));
    return nlab::lib::Vector3f((float) rand()/RAND_MAX * 90.0f - 45.0f, (float) rand()/RAND_MAX * 240.0f - 120.0f, 0.0f);
}

float M300SensorData::GetSonarData() {
    srand(time(0));
    return (float) rand()/RAND_MAX * 10.0f;
}