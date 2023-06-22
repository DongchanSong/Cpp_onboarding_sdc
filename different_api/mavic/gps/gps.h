//
// Created by jhbai on 23. 05. 08.
//

#ifndef LIBMAVIC_GPS_HPP
#define LIBMAVIC_GPS_HPP

class MavicGps {
public:
    MavicGps();
    ~MavicGps();

    /**
     * @brief Returns current GPS number
     * @return Returns float in between 1~20
     */
    float GetGpsNum();

    enum class GPS_HEALTH {
        NONE = 0,
        OPERATIONAL = 1,
        OPTIMAL = 2
    };

    /**
     * @brief Returns current GPS health
     * @return GPS_HEALTH enum
     */
    MavicGps::GPS_HEALTH GetGpsHealth();
};

#endif  // LIBMAVIC_GPS_HPP