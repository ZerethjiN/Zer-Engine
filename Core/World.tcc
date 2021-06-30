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
#ifdef ZERENGINE_WORLD_HPP

namespace zre {
    ////////////////////////////////////////////////////////////////////////
    //// Public Inlining Methods ///////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////

    inline const std::vector<GameObj*>& World::getGameObjs() {
        return gameObjs;
    }

    ////////////////////////////////////////////////////////////////////////
    //// Private Inlining Methods //////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////

    inline void World::updateObjs() {
        for (GameObj* obj : gameObjs) {
            obj->updateComps();
        }
    }

    ////////////////////////////////////////////////////////////////////////

    inline void World::renderClearObjs() {
        for (GameObj* obj : gameObjs) {
            obj->renderClearComps();
        }
    }

    ////////////////////////////////////////////////////////////////////////

    inline void World::renderBackgroundObjs() {
        for (GameObj* obj : gameObjs) {
            obj->renderBackgroundComps();
        }
    }

    ////////////////////////////////////////////////////////////////////////

    inline void World::renderForegroundObjs() {
        for (GameObj* obj : gameObjs) {
            obj->renderForegroundComps();
        }
    }

    ////////////////////////////////////////////////////////////////////////

    inline void World::renderHUDObjs() {
        for (GameObj* obj : gameObjs) {
            obj->renderHUDComps();
        }
    }

    ////////////////////////////////////////////////////////////////////////

    inline void World::renderDisplayObjs() {
        for (GameObj* obj : gameObjs) {
            obj->renderDisplayComps();
        }
    }

    ////////////////////////////////////////////////////////////////////////
}

#endif /* ZERENGINE_WORLD_HPP */