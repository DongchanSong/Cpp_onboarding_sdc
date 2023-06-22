//
// Created by jhbai on 23. 05. 09.
//

#ifndef LIBSKYDIO_CAMERA_HPP
#define LIBSKYDIO_CAMERA_HPP

#include <vector>

class SkydioCamera {
public: 
    SkydioCamera();
    ~SkydioCamera();
    
    enum class CAMERA_STATUS {
        DEFAULT = 0,
        OPERATIONAL = 1,
        ERROR = 2,
    };

    /**
     * @brief Returns camera status
     * @return Returns CAMERA_STATUS enum
     */
    SkydioCamera::CAMERA_STATUS GetCameraStatus();

    /**
     * @brief Returns image data in 2D vector
     * @return Returns 2D vector
     */
    std::vector<std::vector<int>> GetCameraData();

private:
    static void FillRow(std::vector<int> & row);
    static void FillMatrix(std::vector<std::vector<int>> & mat);
};

#endif  // LIBSKYDIO_CAMERA_HPP