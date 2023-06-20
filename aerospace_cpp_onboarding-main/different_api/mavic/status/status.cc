//
// Created by jhbai on 23. 05. 08.
//

#include "status.h"
#include <cstdlib>
#include <time.h>
#include <stdexcept>

MavicStatus::MavicStatus() {}
MavicStatus::~MavicStatus() {}

MavicStatus::FLIGHT_STATUS MavicStatus::GetFlightStatus() {
    srand(time(0));
    return FLIGHT_STATUS(rand() % 4 + 1);
}

MavicStatus::PAYLOAD_STATUS MavicStatus::GetPayloadStatus(MavicStatus::PAYLOAD_TYPE payload_type) {
    switch (payload_type) {
        case MavicStatus::PAYLOAD_TYPE::VISUAL:
            srand(time(0));
            return MavicStatus::PAYLOAD_STATUS(rand() % 3);
        case MavicStatus::PAYLOAD_TYPE::LIDAR:
            srand(time(0));
            return MavicStatus::PAYLOAD_STATUS(rand() % 3);
        case MavicStatus::PAYLOAD_TYPE::CAMERA:
            srand(time(0));
            return MavicStatus::PAYLOAD_STATUS(rand() % 3);
        case MavicStatus::PAYLOAD_TYPE::GIMBAL:
            srand(time(0));
            return MavicStatus::PAYLOAD_STATUS(rand() % 3);
        default:
            std::string errorMessage = "Wrong payload type, or payload type not specified";
            throw std::runtime_error(errorMessage);
            break;
    }    
}