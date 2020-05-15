#include "Bonus.h"
#include "../Controllers/GameController.h"
#include "../Scenes/GameScene.h"

using namespace SpaceInvaders::Controllers;

SpaceInvaders::GameObjects::Bonus::Bonus(double xPos, double direction)
{
    this->dPosition[0] = xPos;
    this->dPosition[1] = GameConstants::DEFAULT_SPRITE_SIZE + 5 * GameConstants::SCALE_Y;
    this->direction = direction;
}

void SpaceInvaders::GameObjects::Bonus::loadSprites(SpaceInvaders::Assets::Sprites::SpriteLoader* loader)
{
    auto* sprite = GameController::getInstance().getSpriteLoader()->loadSprite("Assets/Sprites/Enemies/Bonus.png", true);
    this->sprites.push_back(sprite);
}

void SpaceInvaders::GameObjects::Bonus::update(double deltaTime)
{
    GameObject::update(deltaTime);
    move(this->direction * GameConstants::ENEMY_SPEED * deltaTime, 0);

    if(this->dPosition[0] <= 0 - 2 * GameConstants::DEFAULT_SPRITE_SIZE ||
        this->dPosition[0] >= GameConstants::WINDOW_SIZE_X + GameConstants::DEFAULT_SPRITE_SIZE)
    {
        this->remove = true;
    }
}

void SpaceInvaders::GameObjects::Bonus::onCollision(SpaceInvaders::GameObjects::GameObject* collided)
{
    GameObject::onCollision(collided);

    if(collided->getTag() == GameObjectTag::BULLET)
    {
        auto* bullet = dynamic_cast<Bullet*>(collided);
        if(bullet->isPlayerBullet())
        {
            this->remove = true;

            GameController::getInstance().setLives(GameController::getInstance().getLives() + 1);
            auto* scene = dynamic_cast<Scenes::GameScene*>(GameController::getInstance().getCurrentScene());
            scene->getLvlController()->getPlayer()->setLives(GameController::getInstance().getLives());
        }
    }
}