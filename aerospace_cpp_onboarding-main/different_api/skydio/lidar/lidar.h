//
// Created by jhbai on 23. 05. 09.
//

#ifndef LIBSKYDIO_LIDAR_HPP
#define LIBSKYDIO_LIDAR_HPP

class SkydioLidar {
public: 
    SkydioLidar();
    ~SkydioLidar();

    enum class LIDAR_STATUS {
        DEFAULT = 0,
        OPERATIONAL = 1,
        ERROR = 2,
    };

    /**
     * @brief Returns lidar status
     * @return Returns LIDAR_STATUS enum
     */
    SkydioLidar::LIDAR_STATUS GetLidarStatus();
    /**
     * @brief lidar distance from forward lidar. Range 0 ~ 7m
     * @return Returns lidar distance in float. If no data available, return -1
     */
    float GetForwardLidarDistance();
};

#endif  // LIBSKYDIO_LIDAR_HPP