//
// Created by jhbai on 23. 05. 08.
//

#include "status.h"
#include <cstdlib>
#include <time.h>
#include <stdexcept>

M600Status::M600Status() {}
M600Status::~M600Status() {}

M600Status::FLIGHT_STATUS M600Status::GetFlightStatus() {
    srand(time(0));
    return FLIGHT_STATUS(rand() % 4 + 1);
}

M600Status::PAYLOAD_STATUS M600Status::GetPayloadStatus(M600Status::PAYLOAD_TYPE payload_type) {
    switch (payload_type) {
        case M600Status::PAYLOAD_TYPE::CAMERA:
            srand(time(0));
            return M600Status::PAYLOAD_STATUS(rand() % 3);
        case M600Status::PAYLOAD_TYPE::GIMBAL:
            srand(time(0));
            return M600Status::PAYLOAD_STATUS(rand() % 3);
        default:
            std::string errorMessage = "Wrong payload type, or payload type not specified";
            throw std::runtime_error(errorMessage);
            break;
    }    
}