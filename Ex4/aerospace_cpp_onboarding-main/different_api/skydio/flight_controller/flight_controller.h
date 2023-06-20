//
// Created by jhbai on 23. 05. 09.
//

#ifndef LIBSKYDIO_FLIGHT_CONTROLLER_HPP
#define LIBSKYDIO_FLIGHT_CONTROLLER_HPP

#include <nlab/math.hpp>

class SkydioFlightController {
public:
    SkydioFlightController();
    ~SkydioFlightController();

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
    SkydioFlightController::FLIGHT_STATUS GetFlightStatus();

    /**
     * @brief Returns current 3D position(yd, yd, yd), in NED frame
     * @return Returns Vector3f
     */
    nlab::lib::Vector3f GetPosNed();

    /**
     * @brief Returns current 3D position(deg, deg, yd), in LLH frame
     * @return Returns Vector3f
     */
    nlab::lib::Vector3 GetPosLlh();

    /**
     * @brief Returns current velocity(yd/s, yd/s, yd/s), in heading frame
     * @return Returns Vector3f
     */
    nlab::lib::Vector3f GetVelHdg();

    /**
     * @brief Returns current quaternion where q = w + xi + yj + zk
     * @return Returns quaternion (w, x, y, z)
     */
    nlab::lib::Quaternionf GetQuaternion();
};

#endif  // LIBSKYDIO_FLIGHT_CONTROLLER_HPP