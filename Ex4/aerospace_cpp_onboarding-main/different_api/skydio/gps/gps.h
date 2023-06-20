//
// Created by jhbai on 23. 05. 09.
//

#ifndef LIBSKYDIO_GPS_HPP
#define LIBSKYDIO_GPS_HPP

class SkydioGps {
public:
    SkydioGps();
    ~SkydioGps();

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
    SkydioGps::GPS_HEALTH GetGpsHealth();
};

#endif  // LIBSKYDIO_GPS_HPP