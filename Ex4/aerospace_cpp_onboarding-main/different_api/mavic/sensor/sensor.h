//
// Created by jhbai on 23. 05. 08.
//

#ifndef LIBMAVIC_SENSOR_HPP
#define LIBMAVIC_SENSOR_HPP

#include <integrated_navigation.h>
#include <visual_data.h>
#include <lidar_data.h>
#include <camera_data.h>
#include <gimbal_data.h>

class MavicSensor {
public:
    MavicSensor() {};
    ~MavicSensor() {};

    /**
     * @brief Returns integrated navigation class composed in sensor class
     * @return Returns integrated navigation class composed in sensor class
     */
    MavicIntegratedNavigation GetIntegratedNavigation() { return integratedNavigation_; };

    /**
     * @brief Returns visual data class composed in sensor class
     * @return Returns visual data class composed in sensor class
     */
    MavicVisualData GetVisualData()  { return visualData_; };

    /**
     * @brief Returns lidar data class composed in sensor class
     * @return Returns lidar data class composed in sensor class
     */
    MavicLidarData GetLidarData() { return lidarData_; };

    /**
     * @brief Returns camera data class composed in sensor class
     * @return Returns camera data class composed in sensor class
     */
    MavicCameraData GetCameraData() { return cameraData_; };

    /**
     * @brief Returns gimbal data class composed in sensor class
     * @return Returns gimbal data class composed in sensor class
     */
    MavicGimbalData GetGimbalData() { return gimbalData_; };

protected:
    MavicIntegratedNavigation integratedNavigation_;
    MavicVisualData visualData_;
    MavicLidarData lidarData_;
    MavicCameraData cameraData_;
    MavicGimbalData gimbalData_;
};

#endif  // LIBMAVIC_SENSOR_HPP