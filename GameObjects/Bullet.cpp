
#include "Bullet.h"
#include "../GameConstants.h"

SpaceInvaders::GameObjects::Bullet::Bullet(int position[], int type)
{
    this->tag = GameObjectTag::BULLET;

    this->dPosition[0] = position[0];
    this->dPosition[1] = position[1];
    this->position[0] = position[0];
    this->position[1] = position[1];

    this->collider[0] = -0.1875;
    this->collider[1] = -0.265625;
    this->collider[2] = 0.1875;
    this->collider[3] = 0.265625;

    this->type = type;
    this->killed = nullptr;
}

void SpaceInvaders::GameObjects::Bullet::update(double deltaTime)
{
    this->move(0, -1 * deltaTime * BULLET_SPEED);
}

void SpaceInvaders::GameObjects::Bullet::loadSprites(SpaceInvaders::Assets::Sprites::SpriteLoader* loader)
{
    if(this->isPlayerBullet())
        this->sprites.push_back(loader->loadSprite("Assets/Sprites/Player/Bullet.png", true));
    else
        this->sprites.push_back(loader->loadSprite("Assets/Sprites/Enemies/Bullet.png", true));
}

bool SpaceInvaders::GameObjects::Bullet::isPlayerBullet()
{
    return this->type == 0;
}

void SpaceInvaders::GameObjects::Bullet::onCollision(SpaceInvaders::GameObjects::GameObject* collided)
{
    if((collided->getTag() == GameObjectTag::PLAYER && !this->isPlayerBullet()) ||
        (collided->getTag() == GameObjectTag::ENEMY && this->isPlayerBullet()))
    {
        this->remove = true;
        this->killed = collided;
    }
}

SpaceInvaders::GameObjects::GameObject* SpaceInvaders::GameObjects::Bullet::getKilled()
{
    return this->killed;
}
