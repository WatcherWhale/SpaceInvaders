#include "LevelController.h"

SpaceInvaders::Controllers::LevelController::LevelController()
{
    this->enemyController = EnemyController();
}

SpaceInvaders::Controllers::EnemyController* SpaceInvaders::Controllers::LevelController::getEnemyController()
{
    return &this->enemyController;
}

void SpaceInvaders::Controllers::LevelController::startLevel(int level, Factories::GameFactory* factory,
                                                             Assets::Sprites::SpriteLoader* loader)
{
    this->currentLevel = level;
    this->enemyController.createEnemies(this->currentLevel, factory);
    this->enemyController.loadSprites(loader);
}

void SpaceInvaders::Controllers::LevelController::setPlayer(SpaceInvaders::GameObjects::Player* player)
{
    this->player = player;
}

SpaceInvaders::GameObjects::Player* SpaceInvaders::Controllers::LevelController::getPlayer()
{
    return this->player;
}