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
#include "Time.hpp"
namespace zre {
    ////////////////////////////////////////////////////////////////////////
    //// Attributs /////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////

    double Time::timeScale = 1;
    double Time::deltaTime = 0;
    double Time::t1 = 0;
    double Time::t2 = 0;

    ////////////////////////////////////////////////////////////////////////
}