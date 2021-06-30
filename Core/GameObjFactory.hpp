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
#ifndef ZERENGINE_GAME_OBJ_FACTORY_HPP
#define ZERENGINE_GAME_OBJ_FACTORY_HPP

/**
 * Headers.
 */
#include "World.hpp"
#include "Comp.hpp"

namespace zre {
    /**
     * Creation of a new GameObj with its Components directly attached to the world.
     */
    class GameObjFactory {
    public:
        ////////////////////////////////////////////////////////////////////////
        //// Methods ///////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////

        /** Creation of a new GameObject in the world. */
        inline GameObjFactory& createGameObj();
        /** Attaches a new component to the last GameObject created by this factory. */
        inline GameObjFactory& addComponent(Comp* comp);

    private:
        ////////////////////////////////////////////////////////////////////////
        //// Membres ///////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////

        unsigned int id; //<== Id of the last GameObject created.
    };
}

#include "GameObjFactory.tcc"

#endif /** ZERENGINE_GAME_OBJ_FACTORY_HPP */