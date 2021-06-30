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
#ifndef ZERENGINE_TIME_HPP
#define ZERENGINE_TIME_HPP

namespace zre {
    class Time {
    public:
        static inline void updateTime();

        static inline double getDeltaTime();
        static inline double getElapsedTime();

        static inline void setTimeScale(double scale);

    private:
        static double timeScale;
        static double deltaTime;
        static double t1;
        static double t2;
    };
}

#include "Time.tcc"

#endif /* ZERENGINE_TIME_HPP */