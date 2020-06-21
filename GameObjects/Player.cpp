#include "Player.h"
#include "../GameConstants.h"
#include <cmath>
#include <iostream>
#include "../Controllers/GameController.h"

using namespace SpaceInvaders::GameObjects;
using namespace SpaceInvaders::Events;
using namespace SpaceInvaders::Controllers;

Player::Player(int lives) : GameObject()
{
    // Init player with the current lives
    this->lives = lives;

    // Set the correct tag
    this->tag = GameObjectTag::PLAYER;

    // Set the player in the correct position
    this->position[0] = GameConstants::WINDOW_SIZE_X / 2;
    this->position[1] = std::lround(GameConstants::WINDOW_SIZE_Y - 50 * GameConstants::SCALE_Y);

    this->dPosition[0] = this->position[0];
    this->dPosition[1] = this->position[1];
}

void Player::update(double deltaTime)
{
    // move the player in the right direction
    this->move(this->moveDirection * deltaTime * this->speed, 0);

    // Keep the player inside the window
    double minX = 20 * GameConstants::SCALE_X + this->bounds[2];
    double maxX = GameConstants::WINDOW_SIZE_X - this->bounds[2] - 20 * GameConstants::SCALE_X;

    // Constrain position of the spaceship
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
    }
}

void Player::shoot()
{
    // Check if the player is already shooting
    if(this->shooting || this->spaceDown) return;

    // Disable shooting
    this->shooting = true;
    this->spaceDown = true;

    // Create a bullet and add it to the current scene
    auto* bullet = GameController::getInstance().getFactory()->createBullet(this->position, 0);
    GameController::getInstance().getCurrentScene()->instantiateGameObject(bullet);

    // Create callback
    GameController::getInstance().getTimer()->requestCallback([](void* arg)
    {
        reinterpret_cast<Player*>(arg)->endShoot();
    }, this, GameConstants::PLAYER_TIMEOUT);

    GameController::getInstance().getAudioLoader()->loadAudioClip(GameConstants::getAsset("Audio/SFX/shoot.wav"))->play();
}

void Player::endShoot()
{
    this->shooting = false;
    std::cout << "Shoot end\n";
}


void Player::loadSprites(SpaceInvaders::Assets::Sprites::SpriteLoader* loader)
{
    this->sprites.push_back(loader->loadSprite(GameConstants::getAsset("Sprites/Player/Player.png"), true));
}

void Player::onCollision(GameObject* collided)
{
    // Check if the player collided with an enemy bullet
    if(collided->getTag() == GameObjectTag::BULLET)
    {
        auto* bullet = dynamic_cast<Bullet*>(collided);
        if(!bullet->isPlayerBullet())
        {
            this->lives--;
            GameController::getInstance().getAudioLoader()->loadAudioClip(GameConstants::getAsset("Audio/SFX/death.wav"))->play();
            Controllers::GameController::getInstance().setLives(this->lives);
        }
    }
}

int Player::getLives()
{
    return this->lives;
}

void Player::setLives(int lives)
{
    this->lives = lives;
}
