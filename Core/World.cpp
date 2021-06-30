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
#include "World.hpp"
#include "Time.hpp"

using namespace std;

namespace zre {
    ////////////////////////////////////////////////////////////////////////
    //// Methods ///////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////

    void World::gameLoop() {
        isRunning = true;
        while (isRunning) {
            Time::updateTime();
            updateObjs();
            renderClearObjs();
            renderBackgroundObjs();
            renderForegroundObjs();
            renderHUDObjs();
            renderDisplayObjs();

            if (!lateBuffer.empty()) {
                worldUpgrade();
            }
        }
    }

    ////////////////////////////////////////////////////////////////////////

    void World::worldUpgrade() {
        vector<GameObj*> startingObjs;

        for (LateCmd cmd : lateBuffer) {
            switch(cmd.type) {
                case AddObj:
                    gameObjs.push_back(cmd.obj);
                    startingObjs.push_back(cmd.obj);
                    break;

                case DelObj:
                    for (int i = 0; i < gameObjs.size(); i++) {
                        if (gameObjs[i]->getId() == cmd.id) {
                            delete(gameObjs[i]);
                            gameObjs.erase(gameObjs.begin() + i);
                            break;
                        }
                    }
                    break;

                case AddComp:
                    for (GameObj* obj : gameObjs) {
                        if (obj->getId() == cmd.id) {
                            obj->addComp(cmd.comp);
                            break;
                        }
                    }
                    break;

                case DelComp:
                    for (GameObj* obj : gameObjs) {
                        if (obj->getId() == cmd.id) {
                            obj->delComp(cmd.comp);
                            break;
                        }
                    }
                    break;

                case Purge:
                    for (GameObj* obj : gameObjs) {
                        delete(obj);
                    }
                    gameObjs.clear();
                    break;

                case CloseProg:
                    isRunning = false;
                    for (GameObj* obj : gameObjs) {
                        delete(obj);
                    }
                    gameObjs.clear();
                    break;
            }
        }

        for (GameObj* obj : startingObjs) {
            obj->startComps();
        }

        startingObjs.clear();
        lateBuffer.clear();
    }

    ////////////////////////////////////////////////////////////////////////
    //// Commands //////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////

    void World::delObj(unsigned int id) {
        lateBuffer.push_back({ DelObj, id, nullptr, nullptr });
    }

    ////////////////////////////////////////////////////////////////////////

    unsigned int World::addObj() {
        auto* obj = new GameObj();
        lateBuffer.push_back({ AddObj, obj->getId(), nullptr, obj });
        return obj->getId();
    }

    ////////////////////////////////////////////////////////////////////////

    void World::addComp(Comp* comp, unsigned int id) {
        lateBuffer.push_back({ AddComp, id, comp, nullptr });
    }

    ////////////////////////////////////////////////////////////////////////

    void World::delComp(Comp* comp, unsigned int id) {
        lateBuffer.push_back({ DelComp, id, comp, nullptr });
    }

    ////////////////////////////////////////////////////////////////////////

    void World::purge() {
        lateBuffer.push_back({ Purge, 0, nullptr, nullptr });
    }

    ////////////////////////////////////////////////////////////////////////

    void World::closeProg() {
        lateBuffer.push_back({ CloseProg, 0, nullptr, nullptr });
    }

    ////////////////////////////////////////////////////////////////////////
    //// Attributs /////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////

    bool World::isRunning;

    ////////////////////////////////////////////////////////////////////////

    vector<GameObj*> World::gameObjs;

    ////////////////////////////////////////////////////////////////////////

    vector<LateCmd> World::lateBuffer;

    ////////////////////////////////////////////////////////////////////////
}