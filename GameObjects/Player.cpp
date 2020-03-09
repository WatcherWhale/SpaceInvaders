#include "Player.h"
#include "../GameConstants.h"
#include <cmath>

using namespace SpaceInvaders::GameObjects;
using namespace SpaceInvaders::Events;

Player::Player() : GameObject()
{
    this->position[0] = WINDOW_SIZE_X / 2;
    this->position[1] = std::lround(WINDOW_SIZE_Y - 50 * SCALE_Y);

    this->dPosition[0] = this->position[0];
    this->dPosition[1] = this->position[1];
}

void Player::update(double deltaTime)
{
    this->move(this->moveDirection * deltaTime * this->speed, 0);
}

void Player::onKeyDown(Key key)
{
    switch (key)
    {
        case Key::SPACE:
            this->shoot();
        break;

        case Key::LEFT:
            this->moveDirection = -1;
        break;

        case Key::RIGHT:
            this->moveDirection = 1;
        break;
    }
}

void Player::onKeyUp(Key key)
{
    switch(key)
    {
        case Key::RIGHT:
            if(this->moveDirection > 0)
                this->moveDirection = 0;
            break;

        case Key::LEFT:
            if(this->moveDirection < 0)
                this->moveDirection = 0;
        break;

        case Key::SPACE:
            this->shooting = false;
        break;

        default:
            break;
    }
}

void Player::shoot()
{
    this->shooting = true;
}

void Player::loadSprites(SpaceInvaders::Assets::Sprites::SpriteLoader* loader)
{
    this->sprites.push_back(loader->loadSprite(R"(Assets\Sprites\Player\Player.png)"));
}