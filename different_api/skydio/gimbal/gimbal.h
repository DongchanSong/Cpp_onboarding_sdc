//
// Created by jhbai on 23. 05. 09.
//

#ifndef LIBSKYDIO_GIMBAL_HPP
#define LIBSKYDIO_GIMBAL_HPP

#include <nlab/math.hpp>

class SkydioGimbal {
public: 
    SkydioGimbal();
    ~SkydioGimbal();

    enum class GIMBAL_STATUS {
        DEFAULT = 0,
        OPERATIONAL = 1,
        ERROR = 2,
    };

    /**
     * @brief Returns gimbal status
     * @return Returns GIMBAL_STATUS enum
     */
    SkydioGimbal::GIMBAL_STATUS GetGimbalStatus();

    /**
     * @brief Returns gimbal roll, pitch, yaw angles
     * @return Returns Vector3f
     */
    nlab::lib::Vector3f GetGimbalData();
};

#endif  // LIBSKYDIO_GIMBAL_HPP