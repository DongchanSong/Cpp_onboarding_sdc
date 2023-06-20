//
// Created by jhbai on 23. 05. 08.
//

#ifndef LIBMAVIC_CAMERA_DATA_HPP
#define LIBMAVIC_CAMERA_DATA_HPP

#include <vector>

class MavicCameraData {
public: 
    MavicCameraData();
    ~MavicCameraData();
    
    /**
     * @brief Returns image data in 2D vector
     * @return Returns 2D vector
     */
    std::vector<std::vector<int>> GetCameraData();

private:
    static void FillRow(std::vector<int> & row);
    static void FillMatrix(std::vector<std::vector<int>> & mat);
};

#endif  // LIBMAVIC_CAMERA_DATA_HPP