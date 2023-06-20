//
// Created by jhbai on 23. 05. 08.
//

#include "sensor/gimbal_data/gimbal_data.h"

MavicGimbalData::MavicGimbalData() {}
MavicGimbalData::~MavicGimbalData() {}

nlab::lib::Vector3f MavicGimbalData::GetGimbalData() {
    srand(time(0));
    return nlab::lib::Vector3f((float) rand()/RAND_MAX * 90.0f - 45.0f, (float) rand()/RAND_MAX * 240.0f - 120.0f, 0.0f);
}