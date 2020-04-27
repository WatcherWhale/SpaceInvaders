#include "Alien.h"
#include "../GameConstants.h"
#include "Bullet.h"

SpaceInvaders::GameObjects::Alien::Alien(int x, int y, int row, int column, int type) : GameObject()
{
    this->tag = GameObjectTag::ENEMY;

    this->position[0] = x;
    this->position[1] = y;
    this->dPosition[0] = x;
    this->dPosition[1] = y;

    this->collider[0] = -0.33;
    this->collider[1] = -0.10;
    this->collider[2] = 0.33;
    this->collider[3] = 0.10;

    this->type = type;
    this->row = row;
    this->column = column;
}

void SpaceInvaders::GameObjects::Alien::update(double deltaTime)
{
    int y = 0;

    if(this->down)
    {
        this->down = false;
        y = (GameConstants::DEFAULT_SPRITE_SIZE/2);
    }

    this->move(deltaTime * this->moveDirection * GameConstants::ENEMY_SPEED * this->speedMult, y);
}

void SpaceInvaders::GameObjects::Alien::loadSprites(SpaceInvaders::Assets::Sprites::SpriteLoader* loader)
{
    this->sprites.push_back(
            loader->loadSprite(R"(Assets\Sprites\Enemies\Enemy)"+ std::to_string(this->type) + ".png", true));
}

bool SpaceInvaders::GameObjects::Alien::isDead()
{
    return this->dead;
}

bool SpaceInvaders::GameObjects::Alien::isTouchingWall()
{
    return this->position[0] <= 20 * GameConstants::SCALE_X + this->bounds[2] ||
        this->position[0] >= GameConstants::WINDOW_SIZE_X - this->bounds[2] - 20 * GameConstants::SCALE_X;
}

void SpaceInvaders::GameObjects::Alien::movePosition(int direction, bool down)
{
    this->moveDirection = direction;
    this->down = down;
}

void SpaceInvaders::GameObjects::Alien::onCollision(SpaceInvaders::GameObjects::GameObject* collided)
{
    if(collided->getTag() == GameObjectTag::BULLET)
    {
        auto* bullet = dynamic_cast<Bullet*>(collided);
        if(bullet->isPlayerBullet() && (bullet->getKilled() == this || bullet->getKilled() == nullptr))
        {
            this->dead = true;
            this->remove = true;
        }
    }
}

void SpaceInvaders::GameObjects::Alien::updateMult(double mult)
{
    this->speedMult = mult;
}

int SpaceInvaders::GameObjects::Alien::getRow()
{
    return this->row;
}

int SpaceInvaders::GameObjects::Alien::getColumn()
{
    return this->column;
}