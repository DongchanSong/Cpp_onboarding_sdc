//
// Created by jhbai on 23. 05. 08.
//

#ifndef LIBMAVIC_INTEGRATED_NAVIGATION_HPP
#define LIBMAVIC_INTEGRATED_NAVIGATION_HPP

#include <nlab/math.hpp>

class MavicIntegratedNavigation {
public:
    MavicIntegratedNavigation();
    ~MavicIntegratedNavigation();

    /**
     * @brief Returns current 3D position(m, m, m), in NED frame
     * @return Returns Vector3f
     */
    nlab::lib::Vector3f GetPosNed();

    /**
     * @brief Returns current 3D position(deg, deg, m), in LLH frame
     * @return Returns Vector3f
     */
    nlab::lib::Vector3 GetPosLlh();

    /**
     * @brief Returns current velocity(m/s, m/s, m/s), in heading frame
     * @return Returns Vector3f
     */
    nlab::lib::Vector3f GetVelHdg();

    /**
     * @brief Returns current Euler angles(deg, deg, deg) in Roll, Pitch, Yaw order
     * @return Returns Vector3f
     */
    nlab::lib::Vector3f GetEuler();
};

#endif  // LIBMAVIC_INTEGRATED_NAVIGATION_HPP