#include <iostream>
#include "Timer.h"

SpaceInvaders::Utils::Timer::Timer()
{
    this->ticks = 0;
}

SpaceInvaders::Utils::Timer::~Timer()
{
    this->callbacks.clear();
}

void SpaceInvaders::Utils::Timer::update()
{
    this->ticks += this->deltaTime;

    // Check all callbacks
    for(int i = 0; i < callbacks.size(); i++)
    {
        auto cb = callbacks.at(i);

        if(cb.tick <= this->ticks)
        {
            cb.func(cb.listener);
            callbacks.erase(callbacks.begin() + i);
        }
        else
        {
            i++;
        }
    }
}

unsigned long SpaceInvaders::Utils::Timer::requestCallback(CallbackFunction func, void* arg, unsigned long duration)
{
    TimerCallbackObject cb;

    cb.func = func;
    cb.tick = duration + this->ticks;
    cb.listener = arg;
    cb.id = this->ticks + this->callbacks.size();

    this->callbacks.push_back(cb);

    std::cout << "Got request for " << duration << "\n" << "There are now " << this->callbacks.size() << " requests";

    return cb.id;
}

double SpaceInvaders::Utils::Timer::getDeltaTime()
{
    return this->deltaTime / 1000.0;
}

unsigned long SpaceInvaders::Utils::Timer::getDeltaTimeAbsolute()
{
    return this->deltaTime;
}

void SpaceInvaders::Utils::Timer::stopCallback(unsigned long id)
{
    int i = 0;
    while(i < callbacks.size())
    {
        auto cb = callbacks.at(i);

        if(cb.id == id)
        {
            callbacks.erase(callbacks.begin() + i);
            break;
        }
        else
        {
            i++;
        }
    }
}
