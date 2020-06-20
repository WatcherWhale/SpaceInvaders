#include <cmath>
#include "../GameConstants.h"
#include "EnemyController.h"
#include "GameController.h"
#include "../Utils/Math.h"

void SpaceInvaders::Controllers::EnemyController::createEnemies(int level,
        SpaceInvaders::Factories::GameFactory* factory)
{
    int offsetRow = (level-1) % 11;
    this->currentRow = offsetRow;

    for (int x = 0; x < GameConstants::ENEMIES_X; x++)
    {
        for (int y = 0; y < GameConstants::ENEMIES_Y; y++)
        {
            // Calculate the enemy location
            int realX = std::lround( GameConstants::WINDOW_SIZE_X/2.f +
                    (2-x)/2.f * GameConstants::ENEMY_SPACING_X * GameConstants::SCALE_X +
                    (3-x)/2.f * GameConstants::DEFAULT_SPRITE_SIZE * GameConstants::SCALE_X);
            int realY = std::lround( (y * (GameConstants::DEFAULT_SPRITE_SIZE +
                    GameConstants::ENEMY_SPACING_Y) + GameConstants::ENEMY_OFFSET_Y +
                    offsetRow * (GameConstants::DEFAULT_SPRITE_SIZE + GameConstants::ENEMY_SPACING_Y)/2.f ) * GameConstants::SCALE_Y );

            auto* enemy = factory->createAlien(realX, realY, offsetRow - (5-y), x, 1);
            enemy->movePosition(this->direction, false);
            this->enemies.push_back(enemy);
        }
    }

    this->initiateShoot();
    this->initiateBonus();
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
    }

    if(this->enemies.size() == 1)
        this->enemies.at(0)->updateMult(this->speedMult * 2);
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
            Controllers::GameController::getInstance().addPoints(lround((this->speedMult + 1) *  enemy->getRow()
                * (Controllers::GameController::getInstance().getLevel() + 1) + 100));
            this->enemies.erase(this->enemies.begin() + i);
        }

        i++;
    }
}

void SpaceInvaders::Controllers::EnemyController::initiateShoot()
{
    // Get a random delay
    int delay = Utils::Default_Random.nextInt(GameConstants::ENEMY_DELAY_MIN, GameConstants::ENEMY_DELAY_MAX);

    // Start shoot callback
    this->shootCallbackId = GameController::getInstance().getTimer()->requestCallback([](void* sender){
        auto* ec = reinterpret_cast<EnemyController*>(sender);

        // Get a random column to shoot from
        int column = Utils::Default_Random.nextInt(0, GameConstants::ENEMIES_X);
        int currentColumn = column;

        // Get the lowest enemy to shoot from
        GameObjects::Alien* alien = nullptr;

        int iterations = 0;
        while(alien == nullptr && iterations < GameConstants::ENEMIES_X)
        {
            for (auto* a : *ec->getEnemies())
            {
                if(alien == nullptr && a->getColumn() == currentColumn)
                {
                    alien = a;
                }
                else if(a->getColumn() == currentColumn && a->getRow() > alien->getRow())
                {
                    alien = a;
                }
            }

            iterations++;
            currentColumn = (column + iterations) % GameConstants::ENEMIES_X;
        }

        // No enemies left
        if(alien != nullptr)
        {
            // Instantiate bullet
            auto* bullet = GameController::getInstance().getFactory()->createBullet(alien->getPosition(), 1);
            GameController::getInstance().getCurrentScene()->instantiateGameObject(bullet);
            GameController::getInstance().getAudioLoader()->loadAudioClip("Assets/Audio/SFX/enemyshoot.wav")->play();

            // Start next shot
            ec->initiateShoot();
        }

    }, this, delay);
}

unsigned long SpaceInvaders::Controllers::EnemyController::getShootCallbackId()
{
    return this->shootCallbackId;
}

void SpaceInvaders::Controllers::EnemyController::initiateBonus()
{
    int delay = Utils::Default_Random.nextInt(GameConstants::BONUS_DELAY_MIN, GameConstants::BONUS_DELAY_MAX);
    this->bonusCallbackId = GameController::getInstance().getTimer()->requestCallback([](void* sender) {

        int moveType = Utils::Default_Random.nextInt(0,1);
        GameObjects::Bonus* bonus;

        if(moveType == 0)
        {
            bonus = GameController::getInstance().getFactory()->createBonus(0, 1);
        }
        else
        {
            bonus = GameController::getInstance().getFactory()->createBonus(GameConstants::WINDOW_SIZE_X, -1);
        }

        GameController::getInstance().getCurrentScene()->instantiateGameObject(bonus);
    }, this,delay);

}

unsigned long SpaceInvaders::Controllers::EnemyController::getBonusCallbackId()
{
    return this->bonusCallbackId;
}