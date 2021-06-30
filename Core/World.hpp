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
#ifndef ZERENGINE_WORLD_HPP
#define ZERENGINE_WORLD_HPP

/**
 * Headers.
 */
#include <vector>
#include "Comp.hpp"
#include "GameObj.hpp"
#include "LateCommand.hpp"

namespace zre {
    class World {
    public:
        static void gameLoop();

        static void delObj(unsigned int id);
        static unsigned int addObj();
        static void addComp(Comp* comp, unsigned int id);
        static void delComp(Comp* comp, unsigned int id);
        static void purge();
        static void closeProg();

        static inline const std::vector<GameObj*>& getGameObjs();

    private:
        static void worldUpgrade();

        static inline void updateObjs();
        static inline void renderClearObjs();
        static inline void renderBackgroundObjs();
        static inline void renderForegroundObjs();
        static inline void renderHUDObjs();
        static inline void renderDisplayObjs();

        static bool isRunning;
        static std::vector<GameObj*> gameObjs;
        static std::vector<LateCmd> lateBuffer;
    };
}

#include "World.tcc"

#endif /* ZERENGINE_WORLD_HPP */