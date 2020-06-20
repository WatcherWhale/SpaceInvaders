#include <SDL2/SDL_timer.h>
#include "SDLTimer.h"

void SDL::Utils::SDLTimer::start()
{
    this->startTime = SDL_GetTicks();
}

unsigned long SDL::Utils::SDLTimer::interval()
{
    return SDL_GetTicks() - this->startTime;
}

void SDL::Utils::SDLTimer::stop()
{
    this->deltaTime = SDL_GetTicks() - this->startTime;
    this->update();
}
