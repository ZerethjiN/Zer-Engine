/***********************************************************************
 *
 * Zer-Engine:
 * Copyright (C) 2021 Zerethjin (https://twitch.tv/zerethjin)
 * 
 * A GameObject/Component Engine made by Zerethjin in Stream on:
 * - https://twitch.tv/zerethjin
 * 
 * You can use Zer-Engine in your own project (open-source or proprietary),
 * a credit is appreciated but is not required.
 * 
 **********************************************************************/
#ifdef ZERENGINE_TIME_HPP

#include <ctime>

namespace zre {
    ////////////////////////////////////////////////////////////////////////
    //// Inlining Methods //////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////

    inline void Time::updateTime() {
        timespec time;
        timespec_get(&time, TIME_UTC);
        t1 = (time.tv_sec * 1000000 + time.tv_nsec / 1000) / 1000000;
        deltaTime = t1 - t2;
        t2 = t1;
    }

    ////////////////////////////////////////////////////////////////////////

    inline double Time::getDeltaTime() {
        return deltaTime;
    }

    ////////////////////////////////////////////////////////////////////////

    inline double Time::getElapsedTime() {
        return deltaTime * timeScale;
    }

    ////////////////////////////////////////////////////////////////////////

    inline void Time::setTimeScale(double scale) {
        timeScale = scale;
    }

    ////////////////////////////////////////////////////////////////////////
}

#endif /* ZERENGINE_TIME_HPP */