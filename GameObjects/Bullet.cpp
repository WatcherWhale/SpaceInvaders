
#include "Bullet.h"

SpaceInvaders::GameObjects::Bullet::Bullet(int position[], int type)
{
    this->tag = GameObjectTag::BULLET;

    this->dPosition[0] = position[0];
    this->dPosition[1] = position[1];

    this->type = type;
}

void SpaceInvaders::GameObjects::Bullet::update(double deltaTime)
{
    this->move(0, -1 * deltaTime);
}

void SpaceInvaders::GameObjects::Bullet::loadSprites(SpaceInvaders::Assets::Sprites::SpriteLoader* loader)
{
    this->sprites.push_back(loader->loadSprite("Assets/Sprites/Player/Bullet.png"));
}

bool SpaceInvaders::GameObjects::Bullet::isPlayerBullet()
{
    return this->type == 0;
}
