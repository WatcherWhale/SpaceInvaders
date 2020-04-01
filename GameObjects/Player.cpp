#include "Player.h"
#include "../GameConstants.h"
#include <cmath>
#include "../Controllers/GameController.h"
#include "Bullet.h"

using namespace SpaceInvaders::GameObjects;
using namespace SpaceInvaders::Events;
using namespace SpaceInvaders::Controllers;


Player::Player() : GameObject()
{
    this->tag = GameObjectTag::PLAYER;

    this->position[0] = WINDOW_SIZE_X / 2;
    this->position[1] = std::lround(WINDOW_SIZE_Y - 50 * SCALE_Y);

    this->dPosition[0] = this->position[0];
    this->dPosition[1] = this->position[1];
}

void Player::update(double deltaTime)
{
    this->move(this->moveDirection * deltaTime * this->speed, 0);

    double minX = 20 * SCALE_X + this->bounds[2];
    double maxX = WINDOW_SIZE_X - this->bounds[2] - 20 * SCALE_X;

    if(this->dPosition[0] < minX)
    {
        this->dPosition[0] = minX;
        this->position[0] = std::lround(minX);
    }

    if(this->dPosition[0] > maxX)
    {
        this->dPosition[0] = maxX;
        this->position[0] = std::lround(maxX);
    }
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
            this->spaceDown = false;
            break;

        default:
            break;
    }
}

void Player::shoot()
{
    if(this->shooting || this->spaceDown) return;
    this->shooting = true;
    this->spaceDown = true;

    auto* bullet = GameController::getInstance().getFactory()->createBullet(this->position, 0);
    GameController::getInstance().getCurrentScene()->instantiateGameObject(bullet);

    // Create callback
    GameController::getInstance().getTimer()->requestCallback([](void* arg) {
        reinterpret_cast<Player*>(arg)->endShoot();
    }, this, PLAYER_TIMEOUT);
}

void Player::endShoot()
{
    this->shooting = false;
}


void Player::loadSprites(SpaceInvaders::Assets::Sprites::SpriteLoader* loader)
{
    this->sprites.push_back(loader->loadSprite(R"(Assets\Sprites\Player\Player.png)", true));
}

void Player::onCollision(GameObject* collided)
{
    if(collided->getTag() == GameObjectTag::BULLET)
    {
        auto* bullet = dynamic_cast<Bullet*>(collided);
        if(!bullet->isPlayerBullet())
        {
            
        }
    }
}