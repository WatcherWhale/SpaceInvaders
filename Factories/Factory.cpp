#include "Factory.h"

SpaceInvaders::GameObjects::Player* SpaceInvaders::Factories::GameFactory::createPlayer()
{
    return new SpaceInvaders::GameObjects::Player();
}

SpaceInvaders::GameObjects::Alien* SpaceInvaders::Factories::GameFactory::createAlien(int x, int y, int row, int type)
{
    return new SpaceInvaders::GameObjects::Alien(x, y, row, type);
}
