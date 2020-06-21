#ifndef SPACEINVADERS_SFMLTIMER_H
#define SPACEINVADERS_SFMLTIMER_H


#include <SFML/System/Clock.hpp>
#include "../../Utils/Timer.h"

using namespace SpaceInvaders::Utils;

namespace SFML::Utils
{
    class SFMLTimer : public Timer
    {
    public:
        void start() override;
        unsigned long interval() override;
        void stop();
    private:
        sf::Clock clock;
    };
}

#endif
