//
// Created by jhbai on 23. 4. 25.
//

#include "status.h"
#include <cstdlib>
#include <time.h>
#include <stdexcept>

M300Status::M300Status() {}
M300Status::~M300Status() {}

M300Status::FLIGHT_STATUS M300Status::GetFlightStatus() {
    srand(time(0));
    return FLIGHT_STATUS(rand() % 4 + 1);
}

M300Status::PAYLOAD_STATUS M300Status::GetPayloadStatus(M300Status::PAYLOAD_TYPE payload_type) {
    switch (payload_type) {
        case M300Status::PAYLOAD_TYPE::CAMERA:
            srand(time(0));
            return M300Status::PAYLOAD_STATUS(rand() % 3);
        case M300Status::PAYLOAD_TYPE::GIMBAL:
            srand(time(0));
            return M300Status::PAYLOAD_STATUS(rand() % 3);
        case M300Status::PAYLOAD_TYPE::SONAR:
            srand(time(0));
            return M300Status::PAYLOAD_STATUS(rand() % 3);
        default:
            std::string errorMessage = "Wrong payload type, or payload type not specified";
            throw std::runtime_error(errorMessage);
            break;
    }    
}