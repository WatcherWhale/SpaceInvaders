#include "Timer.h"

SpaceInvaders::Utils::Timer::Timer()
{
    this->ticks = 0;
}

SpaceInvaders::Utils::Timer::~Timer()
{
    this->callbacks.clear();
}

void SpaceInvaders::Utils::Timer::update(unsigned long ticks)
{
    this->ticks += ticks;

    auto it = callbacks.begin();
    while(it != callbacks.end())
    {
        if(it->tick <= this->ticks)
        {
            it->func(it->listener);
            callbacks.erase(it);
        }
        else
        {
            it++;
        }
    }
}

void SpaceInvaders::Utils::Timer::requestCallback(CallbackFunction func, void* arg, unsigned long duration)
{
    TimerCallbackObject cb;

    cb.func = func;
    cb.tick = duration + this->ticks;
    cb.listener = arg;

    this->callbacks.push_back(cb);
}
