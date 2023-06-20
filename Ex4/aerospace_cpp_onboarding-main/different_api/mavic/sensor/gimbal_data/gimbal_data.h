//
// Created by jhbai on 23. 05. 08.
//

#ifndef LIBMAVIC_GIMBAL_DATA_HPP
#define LIBMAVIC_GIMBAL_DATA_HPP

#include <nlab/math.hpp>

class MavicGimbalData {
public: 
    MavicGimbalData();
    ~MavicGimbalData();

    /**
     * @brief Returns gimbal roll, pitch, yaw angles
     * @return Returns Vector3f
     */
    nlab::lib::Vector3f GetGimbalData();
};

#endif  // LIBMAVIC_GIMBAL_DATA_HPP