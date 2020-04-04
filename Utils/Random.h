#ifndef SPACEINVADERS_RANDOM_H
#define SPACEINVADERS_RANDOM_H

#include <random>

namespace SpaceInvaders::Utils
{
    class Random
    {
    public:
        Random();
        Random(long seed);

        double next();
        double next(double max);
        double next(double min, double max);

        unsigned int nextInt();
        int nextInt(int max);
        int nextInt(int min, int max);

    private:
        long seed;
        std::mt19937_64 rand;
    };
}

#endif
