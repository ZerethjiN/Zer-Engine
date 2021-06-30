/***********************************************************************
 *
 * Zer-Engine:
 * Copyright (C) 2021 Zerethjin (https://twitch.tv/zerethjin).
 * 
 * A GameObject/Component Engine made by Zerethjin in Stream on:
 * - https://twitch.tv/zerethjin
 * 
 * You can use Zer-Engine in your own project (open-source or proprietary),
 * a credit is appreciated but is not required.
 * 
 **********************************************************************/
#ifndef ZERENGINE_GAME_OBJ_HPP
#define ZERENGINE_GAME_OBJ_HPP

/**
 * Headers.
 */
#include <vector>
#include "Comp.hpp"

namespace zre {
    /**
     * Automated component grouping.
     */
    class GameObj {
    public:
        ////////////////////////////////////////////////////////////////////////
        //// Constructor/Destructor ////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////

        /** Constructor. */
        inline GameObj();
        /** Destructor. */
        inline ~GameObj();

        ////////////////////////////////////////////////////////////////////////
        //// Getters/Setters ///////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////

        /** Attaches a new Component to this GameObject. */
        inline GameObj* addComp(Comp* comp);
        /** Delete a component from this GameObject. */
        inline void delComp(Comp* comp);
        /** Get a component of this GameObject by its type name. */
        template <typename T>
        T* getComp() const;
        /** Get the Id of this GameObject. */
        inline unsigned int getId() const;

        ////////////////////////////////////////////////////////////////////////
        //// Methods ///////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////

        inline void startComps() const;
        inline void updateComps() const;
        inline void renderClearComps() const;
        inline void renderBackgroundComps() const;
        inline void renderForegroundComps() const;
        inline void renderHUDComps() const;
        inline void renderDisplayComps() const;

    private:
        ////////////////////////////////////////////////////////////////////////
        //// Membres/Attributes ////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////

        const unsigned int id; //<== Id of this GameObject.
        std::vector<Comp*> comps; //<== Components of this GameObject.

        static unsigned int NB_GAMEOBJ; //<== Total GameObjects generates during the lifetime of the program.
    };
}

#include "GameObj.tcc"

#endif /** ZERENGINE_GAME_OBJ_HPP */