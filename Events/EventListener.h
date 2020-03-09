#ifndef GAME_EVENTLISTENER_H
#define GAME_EVENTLISTENER_H

namespace SpaceInvaders::Events
{
    enum Key {SPACE, LEFT, RIGHT, UP, DOWN, NONE};

    class EventListener
    {
    public:
        virtual void onKeyDown(Key key) = 0;
        virtual void onKeyUp(Key key) = 0;
    };
}


#endif //GAME_EVENTLISTENER_H
