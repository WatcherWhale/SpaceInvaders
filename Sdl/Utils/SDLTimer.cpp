#include <SDL2/SDL_timer.h>
#include "SDLTimer.h"

void SpaceInvaders::Utils::SDLTimer::start()
{
    this->startTime = SDL_GetTicks();
}

unsigned long SpaceInvaders::Utils::SDLTimer::interval()
{
    return SDL_GetTicks() - this->startTime;
}

void SpaceInvaders::Utils::SDLTimer::stop()
{
    this->deltaTime = SDL_GetTicks() - this->startTime;
    this->update();
}
