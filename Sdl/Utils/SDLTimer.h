#ifndef SPACEINVADERS_SDLTIMER_H
#define SPACEINVADERS_SDLTIMER_H

#include "../../Utils/Timer.h"

using namespace SpaceInvaders::Utils;

namespace SDL::Utils
{
    class SDLTimer : public Timer
    {
    public:
        void start() override;
        unsigned long interval() override;
        void stop();
    private:
        unsigned long startTime;
    };
}
#endif
