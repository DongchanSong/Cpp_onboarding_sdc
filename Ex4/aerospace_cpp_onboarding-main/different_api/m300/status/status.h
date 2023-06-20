//
// Created by jhbai on 23. 4. 25.
//

#ifndef LIBM300_STATUS_HPP
#define LIBM300_STATUS_HPP

class M300Status {
public:
    M300Status();
    ~M300Status();
    enum FLIGHT_STATUS {
        DEFAULT = 0,
        ON_GROUND = 1,
        ARMED = 2,
        IN_FLIGHT = 3,
        ERROR = 4
    };

    /**
     * @brief Returns flight status
     * @return Returns FLIGHT_STATUS enum
     */
    M300Status::FLIGHT_STATUS GetFlightStatus();

    enum class PAYLOAD_STATUS {
        DEFAULT = 0,
        OPERATIONAL = 1,
        ERROR = 2,
    };

    enum class PAYLOAD_TYPE {
        CAMERA = 0,
        GIMBAL = 1,
        SONAR = 2,
    };

    /**
     * @brief Returns payload status when given a payload type
     * @return Returns PAYLOAD_STATUS enum
     */
    M300Status::PAYLOAD_STATUS GetPayloadStatus(M300Status::PAYLOAD_TYPE payload_type);
};

#endif  // LIBM300_STATUS_HPP