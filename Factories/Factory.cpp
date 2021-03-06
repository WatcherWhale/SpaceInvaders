#include "Factory.h"

SpaceInvaders::Factories::UIFactory* SpaceInvaders::Factories::GameFactory::getUiFactory()
{
    return this->uiFactory;
}

SpaceInvaders::GameObjects::Player* SpaceInvaders::Factories::GameFactory::createPlayer(int lives)
{
    return new SpaceInvaders::GameObjects::Player(lives);
}

SpaceInvaders::GameObjects::Alien* SpaceInvaders::Factories::GameFactory::createAlien(int x, int y, int row, int column, int type)
{
    return new SpaceInvaders::GameObjects::Alien(x, y, row, column, type);
}

SpaceInvaders::GameObjects::Bullet* SpaceInvaders::Factories::GameFactory::createBullet(int position[], int type)
{
    return new GameObjects::Bullet(position, type);
}

SpaceInvaders::GameObjects::Bonus* SpaceInvaders::Factories::GameFactory::createBonus(double xPos, double direction)
{
    return new GameObjects::Bonus(xPos, direction);
}

SpaceInvaders::GameObjects::Bunker* SpaceInvaders::Factories::GameFactory::createBunker(int pos)
{
    return new SpaceInvaders::GameObjects::Bunker(pos);
}

SpaceInvaders::GameObjects::Bunker* SpaceInvaders::Factories::GameFactory::createBunker(int pos, int health)
{
    return new SpaceInvaders::GameObjects::Bunker(pos, health);
}
