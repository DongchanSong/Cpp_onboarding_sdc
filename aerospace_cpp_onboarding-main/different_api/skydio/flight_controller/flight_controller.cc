//
// Created by jhbai on 23. 05. 09.
//

#include "flight_controller.h"

SkydioFlightController::SkydioFlightController() {}
SkydioFlightController::~SkydioFlightController() {}

SkydioFlightController::FLIGHT_STATUS SkydioFlightController::GetFlightStatus() {
    srand(time(0));
    return FLIGHT_STATUS(rand() % 4 + 1);
}

nlab::lib::Vector3f SkydioFlightController::GetPosNed() {
    srand(time(0));
    return nlab::lib::Vector3f(rand()%100-50, rand()%100-50, rand()%100+1);
}

nlab::lib::Vector3 SkydioFlightController::GetPosLlh() {
    srand(time(0));
    return nlab::lib::Vector3(((double) rand() / (RAND_MAX)) + 37.0, ((double) rand() / (RAND_MAX)) + 126.0, rand() % 100 + 1.0);
}

nlab::lib::Vector3f SkydioFlightController::GetVelHdg() {
    srand(time(0));
    return nlab::lib::Vector3f((float) rand()/RAND_MAX*6.0f - 3.0f, (float) rand()/RAND_MAX*6.0f - 3.0f, (float) rand()/RAND_MAX*6.0f - 3.0f);
}

nlab::lib::Quaternionf SkydioFlightController::GetQuaternion() {
    srand(time(0));
    float w = (float) rand()/RAND_MAX;
    float x = (float) rand()/RAND_MAX;
    float y = (float) rand()/RAND_MAX;
    float z = (float) rand()/RAND_MAX;

    if (std::abs(w*w + x*x + y*y + z*z -1) > FLT_EPSILON) {
        float mag = w*w + x*x + y*y + z*z;
        w /= mag;
        x /= x;
        y /= y;
        z /= z;
    }
    return nlab::lib::Quaternionf(w, x, y, z);
}