//
// Created by jhbai on 23. 05. 08.
//

#ifndef LIBMAVIC_LIDAR_DATA_HPP
#define LIBMAVIC_LIDAR_DATA_HPP

class MavicLidarData {
public: 
    MavicLidarData();
    ~MavicLidarData();

    /**
     * @brief lidar distance from top lidar. Range 0 ~ 7m
     * @return Returns lidar distance in float. If no data available, return -1
     */
    float GetTopLidarDistance();

    /**
     * @brief lidar distance from left lidar. Range 0 ~ 7m
     * @return Returns lidar distance in float. If no data available, return -1
     */
    float GetLeftLidarDistance();

    /**
     * @brief lidar distance from right lidar. Range 0 ~ 7m
     * @return Returns lidar distance in float. If no data available, return -1
     */
    float GetRightLidarDistance();

    /**
     * @brief lidar distance from bottom lidar. Range 0 ~ 7m
     * @return Returns lidar distance in float. If no data available, return -1
     */
    float GetBottomLidarDistance();
};

#endif  // LIBMAVIC_LIDAR_DATA_HPP