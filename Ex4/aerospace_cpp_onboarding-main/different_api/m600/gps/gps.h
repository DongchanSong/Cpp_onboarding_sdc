//
// Created by jhbai on 23. 05. 08.
//

#ifndef LIBM600_GPS_HPP
#define LIBM600_GPS_HPP

class M600Gps {
public:
    M600Gps();
    ~M600Gps();

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
    M600Gps::GPS_HEALTH GetGpsHealth();

    enum class RTK_CONNECTION {
        DISCONNECTED = 0,
        CONNECTED = 1
    };

    /**
     * @brief Returns current RTK connetion status
     * @return Returns RTK_CONNECTION
     */
    M600Gps::RTK_CONNECTION GetRtkConnection();
};

#endif  // LIBM600_GPS_HPP