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

        virtual void start() = 0;
        virtual unsigned long interval() = 0;
        virtual void stop() = 0;

        double getDeltaTime();
        unsigned long getDeltaTimeAbsolute();

        unsigned long requestCallback(CallbackFunction func, void* arg, unsigned long duration);
        void stopCallback(unsigned long id);

    protected:
        unsigned long deltaTime = 0;
        void update();
    };
}

#endif
