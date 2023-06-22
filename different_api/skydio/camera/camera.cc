//
// Created by jhbai on 23. 05. 09.
//

#include "camera.h"
#include <cstdlib>
#include <algorithm>
#include <time.h>

SkydioCamera::SkydioCamera() {}
SkydioCamera::~SkydioCamera() {}

SkydioCamera::CAMERA_STATUS GetCameraStatus() {
    return SkydioCamera::CAMERA_STATUS(rand() % 3);
}

void SkydioCamera::FillRow(std::vector<int> & row)
{
    std::generate(row.begin(), row.end(), [](){ return rand() % 256; }); 
}

void SkydioCamera::FillMatrix(std::vector<std::vector<int>> & mat)
{
    std::for_each(mat.begin(), mat.end(), FillRow);
}

std::vector<std::vector<int>> SkydioCamera::GetCameraData() {
    // Size of image (pixels)
    int x = 640;
    int y = 480;
  
    std::vector<std::vector<int>> image(x, std::vector<int>(y, 0));
    srand(time(0));
    FillMatrix(image);
    return image;
}