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
#ifndef ZERENGINE_COMP_HPP
#define ZERENGINE_COMP_HPP

/**
 * Co-dependency.
 */
class GameObj;

namespace zre {
    /**
     * Base class for all components.
     */
    class Comp {
    public:
        /** Destructor. */
        virtual ~Comp() { }

        /** Starting all members of this component. */
        virtual void start() { }
        /** Methods of this component called every frame. */
        virtual void update() { }
        virtual void renderClear() { }
        virtual void renderBackground() { }
        virtual void renderForeground() { }
        virtual void renderHUD() { }
        virtual void renderDisplay() { }

        GameObj* gameObj; //<== GameObject parent of this component.
    };
}

#endif /* ZERENGINE_COMP_HPP */