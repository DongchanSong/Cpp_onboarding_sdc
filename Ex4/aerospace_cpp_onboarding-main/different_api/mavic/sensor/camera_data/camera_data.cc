//
// Created by jhbai on 23. 05. 08.
//

#include "sensor/camera_data/camera_data.h"
#include <cstdlib>
#include <algorithm>
#include <time.h>

MavicCameraData::MavicCameraData() {}
MavicCameraData::~MavicCameraData() {}

void MavicCameraData::FillRow(std::vector<int> & row)
{
    std::generate(row.begin(), row.end(), [](){ return rand() % 256; }); 
}

void MavicCameraData::FillMatrix(std::vector<std::vector<int>> & mat)
{
    std::for_each(mat.begin(), mat.end(), FillRow);
}

std::vector<std::vector<int>> MavicCameraData::GetCameraData() {
    // Size of image (pixels)
    int x = 640;
    int y = 480;
  
    std::vector<std::vector<int>> image(x, std::vector<int>(y, 0));
    srand(time(0));
    FillMatrix(image);
    return image;
}