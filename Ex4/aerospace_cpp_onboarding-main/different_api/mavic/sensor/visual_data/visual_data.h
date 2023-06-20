//
// Created by jhbai on 23. 05. 08.
//

#ifndef LIBMAVIC_VISUAL_DATA_HPP
#define LIBMAVIC_VISUAL_DATA_HPP

class MavicVisualData {
public: 
    MavicVisualData();
    ~MavicVisualData();

    typedef struct {
        int x;
        int y;
    } Point;

    /**
     * @brief Returns depth distance by visual data. Range: 0 ~ 7m
     * @return Returns float. If no data available, return -1
     */
    float GetVisualDepth();

    /**
     * @brief Returns point in the camera frame for current visual depth data. RangeX: 640, RangeY:480
     * @return Returns Point x, y. If no data available, return -1, -1
     */
    MavicVisualData::Point GetDepthPoint();
};

#endif  // LIBMAVIC_VISUAL_DATA_HPP