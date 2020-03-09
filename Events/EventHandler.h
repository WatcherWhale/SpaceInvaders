#ifndef GAME_EVENTHANDLER_H
#define GAME_EVENTHANDLER_H

#include <vector>
#include "EventListener.h"

using namespace std;

namespace SpaceInvaders::Events
{
    class EventHandler
    {
    public:

        ~EventHandler();
        void addListener(EventListener* listener);

        void onKeyDown(Key key);
        void onKeyUp(Key key);

    private:
        vector<EventListener*> listeners;
    };

}
#endif //GAME_EVENTHANDLER_H