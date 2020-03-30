#include "Math.h"

SpaceInvaders::Utils::Random SpaceInvaders::Utils::Math::getRandom()
{
    return SpaceInvaders::Utils::Random();
}

SpaceInvaders::Utils::Random SpaceInvaders::Utils::Math::getRandom(long seed)
{
    return SpaceInvaders::Utils::Random(seed);
}
