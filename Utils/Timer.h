#ifndef SPACEINVADERS_TIMER_H
#define SPACEINVADERS_TIMER_H

#include <vector>

namespace SpaceInvaders::Utils
{
    typedef void (*Function) (void*);
    typedef struct{
        Function func;
        unsigned long tick;
        void* arg;
    } CallbackObject;

    class Timer
    {
    private:
        unsigned long ticks;
        std::vector<CallbackObject> callbacks;

    public:
        Timer();
        ~Timer();

        void update(unsigned long ticks);
        void requestCallback(Function func, void* arg, unsigned long duration);
    };
}

#endif
