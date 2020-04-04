#ifndef SPACEINVADERS_MATH_H
#define SPACEINVADERS_MATH_H

#include "Random.h"

namespace SpaceInvaders::Utils
{
    static Random Default_Random = Random();

    class Math
    {
    public:
        static Random getRandom();
        static Random getRandom(long seed);
    };
}
#endif
