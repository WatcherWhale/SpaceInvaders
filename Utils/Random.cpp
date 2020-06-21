#include "Random.h"

SpaceInvaders::Utils::Random::Random()
{
    std::random_device rd;
    this->seed = rd();
    this->rand = std::mt19937_64(this->seed);
}

SpaceInvaders::Utils::Random::Random(long seed)
{
    this->seed = seed;
    this->rand = std::mt19937_64(seed);
}

double SpaceInvaders::Utils::Random::next()
{
    return this->rand() / static_cast<double>(std::mt19937_64::max());
}

double SpaceInvaders::Utils::Random::next(double min, double max)
{
    return (max - min) * this->next() + min;
}

double SpaceInvaders::Utils::Random::next(double max)
{
    return this->next(0, max);
}

unsigned int SpaceInvaders::Utils::Random::nextInt()
{
    return this->rand();
}

int SpaceInvaders::Utils::Random::nextInt(int min, int max)
{
    return static_cast<uint16_t>(this->nextInt()) % (max - min + 1) + min;
}

int SpaceInvaders::Utils::Random::nextInt(int max)
{
    return this->nextInt(0, max);
}