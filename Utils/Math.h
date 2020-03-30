#ifndef SPACEINVADERS_MATH_H
#define SPACEINVADERS_MATH_H

#include "Random.h"

namespace SpaceInvaders::Utils
{
    class Math
    {
    public:
        static Random getRandom();
        static Random getRandom(long seed);
    private:

    };
}
#endif
