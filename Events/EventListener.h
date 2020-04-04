#ifndef GAME_EVENTLISTENER_H
#define GAME_EVENTLISTENER_H

namespace SpaceInvaders::Events
{
    enum Key {SPACE, LEFT, RIGHT, UP, DOWN, NONE};

    class EventListener
    {
    public:
        virtual void onKeyDown(Key key) {};
        virtual void onKeyUp(Key key) {};

        virtual void mouseMove(int x, int y) {};
        virtual void mouseDown(int x, int y) {};
        virtual void mouseUp(int x, int y) {};
    };
}


#endif //GAME_EVENTLISTENER_H
