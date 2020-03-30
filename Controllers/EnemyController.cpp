#include <cmath>
#include "EnemyController.h"
#include "GameController.h"
#include "../Utils/Math.h";

void SpaceInvaders::Controllers::EnemyController::createEnemies(int level,
        SpaceInvaders::Factories::GameFactory* factory)
{
    int offsetRow = (level-1) % 11;
    this->currentRow = offsetRow;

    for (int x = 0; x < 6; x++)
    {
        for (int y = 0; y < 6; y++)
        {
            int realX = std::lround( WINDOW_SIZE_X/2.f +
                    (2-x)/2.f * ENEMY_SPACING_X * SCALE_X + (3-x)/2.f * DEFAULT_SPRITE_SIZE * SCALE_X);
            int realY = std::lround( (y * (DEFAULT_SPRITE_SIZE + ENEMY_SPACING_Y) + ENEMY_OFFSET_Y
                    + offsetRow * (DEFAULT_SPRITE_SIZE + ENEMY_SPACING_Y)/2.f ) * SCALE_Y );

            auto* enemy = factory->createAlien(realX, realY, offsetRow - (5-y) , 1);
            enemy->movePosition(this->direction, false);
            this->enemies.push_back(enemy);
        }
    }
}

void SpaceInvaders::Controllers::EnemyController::update(double deltaTime)
{
    bool updateMovement = false;

    for(auto* enemy : this->enemies)
    {
        updateMovement = updateMovement || enemy->isTouchingWall();
    }

    if(updateMovement && !this->handledMovementUpdate)
    {
        this->direction *= -1;
        this->speedMult += 0.2;

        for (auto* enemy : this->enemies)
        {
            enemy->movePosition(this->direction, true);
            enemy->updateMult(this->speedMult);
        }

        this->currentRow++;
        this->handledMovementUpdate = true;

        if(currentRow == 11)
        {
            // Game Over
            GameController::getInstance().loadScene(SceneEnum::GAMEOVER);
        }
    }
    else if(!updateMovement && this->handledMovementUpdate)
    {
        this->handledMovementUpdate = false;
        GameController::getInstance().getTimer()->requestCallback([](void* alien)
        {

        }, nullptr, Utils::Math::getRandom().nextInt());
    }
}

std::vector<SpaceInvaders::GameObjects::Alien*>* SpaceInvaders::Controllers::EnemyController::getEnemies()
{
    return &this->enemies;
}

void SpaceInvaders::Controllers::EnemyController::loadSprites(SpaceInvaders::Assets::Sprites::SpriteLoader* loader)
{
    for(auto enemy : this->enemies)
    {
        enemy->loadSprites(loader);
    }
}

int SpaceInvaders::Controllers::EnemyController::getCurrentRow()
{
    return this->currentRow;
}

void SpaceInvaders::Controllers::EnemyController::lateUpdate()
{
    int i = 0;
    while(i < this->enemies.size())
    {
        auto* enemy = this->enemies.at(i);
        if(enemy->isDead())
        {
            this->enemies.erase(this->enemies.begin() + i);
        }

        i++;
    }
}
