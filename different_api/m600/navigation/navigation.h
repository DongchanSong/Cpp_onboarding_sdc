//
// Created by jhbai on 23. 05. 08.
//

#ifndef LIBM600_NAVIGATION_HPP
#define LIBM600_NAVIGATION_HPP

#include <nlab/math.hpp>

class M600Navigation {
public:
    M600Navigation();
    ~M600Navigation();

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
    nlab::lib::Vector3f GetVelBody();

    /**
     * @brief Returns current Euler angles(deg, deg, deg) in Roll, Pitch, Yaw order
     * @return Returns Vector3f
     */
    nlab::lib::Vector3f GetEuler();
};

#endif  // LIBM600_NAVIGATION_HPP