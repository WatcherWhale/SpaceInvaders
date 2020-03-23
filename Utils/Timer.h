#ifndef SPACEINVADERS_TIMER_H
#define SPACEINVADERS_TIMER_H

#include <vector>
#include "FunctionDefinitions.h"

namespace SpaceInvaders::Utils
{
    class Timer
    {
    private:
        unsigned long ticks;
        std::vector<TimerCallbackObject> callbacks;

    public:
        Timer();
        ~Timer();

        void update(unsigned long ticks);
        void requestCallback(CallbackFunction func, void* arg, unsigned long duration);
    };
}

#endif
