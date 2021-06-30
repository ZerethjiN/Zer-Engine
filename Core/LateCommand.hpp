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
#ifndef ZERENGINE_LATE_COMMAND_HPP
#define ZERENGINE_LATE_COMMAND_HPP

/**
 * Headers.
 */
#include "Comp.hpp"
#include "GameObj.hpp"

namespace zre {
    /**
     * Enumeration of different types of late commandes.
     */
    enum LateCmdType {
        AddObj,
        DelObj,
        AddComp,
        DelComp,
        Purge,
        CloseProg
    };

    /**
     * Message from the World for these different post-frame actions. 
     */
    struct LateCmd {
        LateCmdType type;
        unsigned int id;
        Comp* comp;
        GameObj* obj;
    };
}

#endif /* ZERENGINE_LATE_COMMAND_HPP */