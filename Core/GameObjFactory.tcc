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
#ifdef ZERENGINE_GAME_OBJ_FACTORY_HPP

namespace zre {
    ////////////////////////////////////////////////////////////////////////
    //// Inlining Methods //////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////

    /**
     * Creation of a new GameObject in the world.
     */
    inline GameObjFactory& GameObjFactory::createGameObj() {
        id = World::addObj();
        return *this;
    }

    ////////////////////////////////////////////////////////////////////////

    /**
     * Attaches a new component to the last GameObject created by this factory.
     */
    inline GameObjFactory& GameObjFactory::addComponent(Comp* comp) {
        World::addComp(comp, id);
        return *this;
    }

    ////////////////////////////////////////////////////////////////////////
}

#endif /* ZERENGINE_GAME_OBJ_FACTORY_HPP */