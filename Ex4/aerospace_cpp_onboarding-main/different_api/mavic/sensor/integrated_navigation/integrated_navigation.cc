//
// Created by jhbai on 23. 05. 08.
//

#include "sensor/integrated_navigation/integrated_navigation.h"

MavicIntegratedNavigation::MavicIntegratedNavigation() {}
MavicIntegratedNavigation::~MavicIntegratedNavigation() {}

nlab::lib::Vector3f MavicIntegratedNavigation::GetPosNed() {
    srand(time(0));
    return nlab::lib::Vector3f(rand()%100-50, rand()%100-50, rand()%100+1);
}

nlab::lib::Vector3 MavicIntegratedNavigation::GetPosLlh() {
    srand(time(0));
    return nlab::lib::Vector3(((double) rand() / (RAND_MAX)) + 37.0, ((double) rand() / (RAND_MAX)) + 126.0, rand() % 100 + 1.0);
}

nlab::lib::Vector3f MavicIntegratedNavigation::GetVelHdg() {
    srand(time(0));
    return nlab::lib::Vector3f((float) rand()/RAND_MAX*6.0f - 3.0f, (float) rand()/RAND_MAX*6.0f - 3.0f, (float) rand()/RAND_MAX*6.0f - 3.0f);
}

nlab::lib::Vector3f MavicIntegratedNavigation::GetEuler() {
    srand(time(0));
    return nlab::lib::Vector3f((float) rand()/RAND_MAX*60.0f - 30.0f, (float) rand()/RAND_MAX*60.0f - 30.0f, (float) rand()/RAND_MAX*360.0f - 180.0f);
}