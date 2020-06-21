#include "SFMLTimer.h"

void SFML::Utils::SFMLTimer::start()
{
    this->clock.restart();
}

unsigned long SFML::Utils::SFMLTimer::interval()
{
    return this->clock.getElapsedTime().asMilliseconds();
}

void SFML::Utils::SFMLTimer::stop()
{
    this->deltaTime = this->clock.getElapsedTime().asMilliseconds();
    this->update();
}
