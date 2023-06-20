//
// Created by jhbai on 23. 05. 09.
//

#include "gimbal.h"

SkydioGimbal::SkydioGimbal() {}
SkydioGimbal::~SkydioGimbal() {}

SkydioGimbal::GIMBAL_STATUS GetGimbalStatus() {
    return SkydioGimbal::GIMBAL_STATUS(rand() % 3);
}

nlab::lib::Vector3f SkydioGimbal::GetGimbalData() {
    srand(time(0));
    return nlab::lib::Vector3f((float) rand()/RAND_MAX * 90.0f - 45.0f, (float) rand()/RAND_MAX * 240.0f - 120.0f, 0.0f);
}