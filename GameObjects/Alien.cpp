#include "Alien.h"
#include "../GameConstants.h"

SpaceInvaders::GameObjects::Alien::Alien(int x, int y, int row, int type) : GameObject()
{
    this->position[0] = x;
    this->position[1] = y;
    this->dPosition[0] = x;
    this->dPosition[1] = y;
    this->type = type;
    this->row = row;

    this->bounds[2] *= 0.9;
    this->bounds[3] *= 0.9;
}

void SpaceInvaders::GameObjects::Alien::update(double deltaTime)
{
    int y = 0;

    if(this->down)
    {
        this->down = false;
        y = (DEFAULT_SPRITE_SIZE/2);
    }

    this->move(deltaTime * this->moveDirection * ENEMY_SPEED, y);
}

void SpaceInvaders::GameObjects::Alien::loadSprites(SpaceInvaders::Assets::Sprites::SpriteLoader* loader)
{
    this->sprites.push_back(
            loader->loadSprite(R"(Assets\Sprites\Enemies\Enemy)"+ std::to_string(this->type) + ".png"));
}

bool SpaceInvaders::GameObjects::Alien::isDead()
{
    return this->dead;
}

bool SpaceInvaders::GameObjects::Alien::isTouchingWall()
{
    return this->position[0] <= 20 * SCALE_X + this->bounds[2] ||
        this->position[0] >= WINDOW_SIZE_X - this->bounds[2] - 20 * SCALE_X;
}

void SpaceInvaders::GameObjects::Alien::movePosition(int direction, bool down)
{
    this->moveDirection = direction;
    this->down = down;
}