//
// Created by jhbai on 23. 05. 08.
//

#ifndef LIBMAVIC_STATUS_HPP
#define LIBMAVIC_STATUS_HPP

class MavicStatus {
public:
    MavicStatus();
    ~MavicStatus();

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
    MavicStatus::FLIGHT_STATUS GetFlightStatus();

    enum class PAYLOAD_STATUS {
        DEFAULT = 0,
        OPERATIONAL = 1,
        ERROR = 2,
    };

    enum class PAYLOAD_TYPE {
        VISUAL = 0,
        LIDAR = 1,
        CAMERA = 2,
        GIMBAL = 3
    };

    /**
     * @brief Returns payload status when given a payload type
     * @return Returns PAYLOAD_STATUS enum
     */
    MavicStatus::PAYLOAD_STATUS GetPayloadStatus(MavicStatus::PAYLOAD_TYPE payload_type);
};

#endif  // LIBMAVIC_STATUS_HPP