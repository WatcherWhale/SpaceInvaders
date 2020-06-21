#include <cmath>
#include "Bunker.h"
#include "../GameConstants.h"
#include "Bullet.h"
#include "../Controllers/GameController.h"

using namespace SpaceInvaders::GameObjects;

Bunker::Bunker(int pos) : GameObject()
{
    this->pos = pos;
    this->tag = GameObjectTag::WALL;

    this->dPosition[0] = ((pos + 1) * GameConstants::WALL_SPACING + (pos + 0.5) * GameConstants::DEFAULT_SPRITE_SIZE) * GameConstants::SCALE_X;
    this->dPosition[1] = GameConstants::WINDOW_SIZE_Y - 200 * GameConstants::SCALE_Y;

    this->position[0] = std::lround(this->dPosition[0]);
    this->position[1] = std::lround(this->dPosition[1]);

    collider[0] = -0.5;
    collider[1] = -0.5;
    collider[2] = 0.5;
    collider[3] = 0;
}

Bunker::Bunker(int pos, int health) : Bunker(pos)
{
    this->currentSprite = health;
}

void Bunker::loadSprites(SpaceInvaders::Assets::Sprites::SpriteLoader* loader)
{
    this->sprites.push_back(loader->loadSprite(GameConstants::getAsset("Sprites/Bunkers/Bunker1.png"), true));
    this->sprites.push_back(loader->loadSprite(GameConstants::getAsset("Sprites/Bunkers/Bunker2.png"), true));
    this->sprites.push_back(loader->loadSprite(GameConstants::getAsset("Sprites/Bunkers/Bunker3.png"), true));
    this->sprites.push_back(loader->loadSprite(GameConstants::getAsset("Sprites/Bunkers/Bunker4.png"), true));
    this->sprites.push_back(loader->loadSprite(GameConstants::getAsset("Sprites/Bunkers/Bunker5.png"), true));
}

void Bunker::update(double deltaTime)
{
    GameObject::update(deltaTime);
}

void Bunker::onCollision(GameObject* collided)
{
    if(collided->getTag() == GameObjectTag::BULLET)
    {
        auto* bullet = dynamic_cast<Bullet*>(collided);
        if(this->currentSprite < 4)
        {
            this->currentSprite++;
            bullet->setRemoved();

            Controllers::GameController::getInstance().setBunkerHealth(this->pos, this->currentSprite);
        }
    }
    else if(collided->getTag() == GameObjectTag::ENEMY)
    {
        if(this->currentSprite < 4)
        {
            this->currentSprite++;
            Controllers::GameController::getInstance().setBunkerHealth(this->pos, this->currentSprite);
        }
    }
}
