//
// Created by jhbai on 23. 4. 25.
//

#ifndef LIBM300_GPS_HPP
#define LIBM300_GPS_HPP

class M300Gps {
public:
    M300Gps();
    ~M300Gps();

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
    M300Gps::GPS_HEALTH GetGpsHealth();

    enum class RTK_CONNECTION {
        DISCONNECTED = 0,
        CONNECTED = 1
    };

    /**
     * @brief Returns current RTK connetion status
     * @return Returns RTK_CONNECTION
     */
    M300Gps::RTK_CONNECTION GetRtkConnection();
};

#endif  // LIBM300_GPS_HPP