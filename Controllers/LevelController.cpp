#include "LevelController.h"

SpaceInvaders::Controllers::LevelController::LevelController()
{
    this->enemyController = EnemyController();
}

SpaceInvaders::Controllers::EnemyController* SpaceInvaders::Controllers::LevelController::getEnemyController()
{
    return &this->enemyController;
}

void SpaceInvaders::Controllers::LevelController::startLevel(Factories::GameFactory* factory,
                                                             Assets::Sprites::SpriteLoader* loader)
{
    if(this->levelStarted) return;

    this->currentLevel++;
    this->enemyController.createEnemies(this->currentLevel, factory);
    this->enemyController.loadSprites(loader);
    this->levelStarted = true;
}

bool SpaceInvaders::Controllers::LevelController::isLevelStarted()
{
    return this->levelStarted;
}

void SpaceInvaders::Controllers::LevelController::setPlayer(SpaceInvaders::GameObjects::Player* player)
{
    this->player = player;
}

SpaceInvaders::GameObjects::Player* SpaceInvaders::Controllers::LevelController::getPlayer()
{
    return this->player;
}