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
#ifdef ZERENGINE_GAME_OBJ_HPP

namespace zre {
    ////////////////////////////////////////////////////////////////////////
    //// Inlining Constructor/Destructor ///////////////////////////////////
    ////////////////////////////////////////////////////////////////////////

    /**
     * Constructor.
    */
    inline GameObj::GameObj():
        id(NB_GAMEOBJ) {
        NB_GAMEOBJ++;
    }

    ////////////////////////////////////////////////////////////////////////

    /**
     * Destructor.
    */
    inline GameObj::~GameObj() {
        for (Comp* comp : comps) {
            delete(comp);
        }
    }

    ////////////////////////////////////////////////////////////////////////
    //// Inlining Getters/Setters //////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////

    /**
     * Attaches a new Component to this GameObject.
     */
    inline GameObj* GameObj::addComp(Comp* comp) {
        comp->gameObj = this;
        comps.push_back(comp);
        return this;
    }

    ////////////////////////////////////////////////////////////////////////

    /**
     * Delete a component from this GameObject.
     */
    inline void GameObj::delComp(Comp* comp) {
        for (int i = 0; i < comps.size(); i++) {
            if (comps[i] == comp) {
                delete(comp);
                comps.erase(comps.begin() + i);
                break;
            }
        }
    }

    ////////////////////////////////////////////////////////////////////////

    /**
     * Get a component of this GameObject by its type name.
     */
    template <typename T>
    T* GameObj::getComp() const {
        for (Comp* comp : comps) {
            if (typeid(T).name() == typeid(*component).name()) {
                return static_cast<T*>(component);
            }
        }
        return nullptr;
    }

    ////////////////////////////////////////////////////////////////////////

    /**
     * Get the Id of this GameObject.
     */
    inline unsigned int GameObj::getId() const {
        return id;
    }

    ////////////////////////////////////////////////////////////////////////
    //// Inlining Methods //////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////

    inline void GameObj::startComps() const {
        for (Comp* comp : comps) {
            comp->start();
        }
    }

    ////////////////////////////////////////////////////////////////////////

    inline void GameObj::updateComps() const {
        for (Comp* comp : comps) {
            comp->update();
        }
    }

    ////////////////////////////////////////////////////////////////////////

    inline void GameObj::renderClearComps() const {
        for (Comp* comp : comps) {
            comp->renderClear();
        }
    }

    ////////////////////////////////////////////////////////////////////////

    inline void GameObj::renderBackgroundComps() const {
        for (Comp* comp : comps) {
            comp->renderBackground();
        }
    }

    ////////////////////////////////////////////////////////////////////////

    inline void GameObj::renderForegroundComps() const {
        for (Comp* comp : comps) {
            comp->renderForeground();
        }
    }

    ////////////////////////////////////////////////////////////////////////

    inline void GameObj::renderHUDComps() const {
        for (Comp* comp : comps) {
            comp->renderHUD();
        }
    }

    ////////////////////////////////////////////////////////////////////////

    inline void GameObj::renderDisplayComps() const {
        for (Comp* comp : comps) {
            comp->renderDisplay();
        }
    }

    ////////////////////////////////////////////////////////////////////////
    //// Class Attributes //////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////

    unsigned int GameObj::NB_GAMEOBJ = 0;

    ////////////////////////////////////////////////////////////////////////
}

#endif /* ZERENGINE_GAME_OBJ_HPP */