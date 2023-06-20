//
// Created by jhbai on 23. 4. 25.
//

#ifndef LIBM300_SENSOR_DATA_HPP
#define LIBM300_SENSOR_DATA_HPP

#include <nlab/math.hpp>

class M300SensorData {
public: 
    M300SensorData();
    ~M300SensorData();
    
    /**
     * @brief Returns image data in 2D vector
     * @return Returns 2D vector
     */
    std::vector<std::vector<int>> GetCameraData();

    /**
     * @brief Returns gimbal roll, pitch, yaw angles
     * @return Returns Vector3f
     */
    nlab::lib::Vector3f GetGimbalData();

    /**
     * @brief Returns sonar forward distance data
     * @return Returns float
     */
    float GetSonarData();

private:
    static void FillRow(std::vector<int> & row);
    static void FillMatrix(std::vector<std::vector<int>> & mat);
};

#endif  // LIBM300_SENSOR_DATA_HPP