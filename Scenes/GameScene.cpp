#include "GameScene.h"
#include "../Controllers/GameController.h"
#include "../GameObjects/Bullet.h"

SpaceInvaders::Scenes::GameScene::GameScene()
{
    this->lvlController = SpaceInvaders::Controllers::LevelController();
}


void SpaceInvaders::Scenes::GameScene::update(double deltaTime)
{
    // Call default update method
    Scene::update(deltaTime);

    // Update Enemy controller
    this->lvlController.getEnemyController()->update(deltaTime);
}

void SpaceInvaders::Scenes::GameScene::load()
{
    auto* loader = Controllers::GameController::getInstance().getSpriteLoader();
    auto* player = new GameObjects::Player();
    player->loadSprites(loader);

    this->gameObjects.push_back(player);
    this->eventListeners.push_back(player);
}

SpaceInvaders::Controllers::LevelController* SpaceInvaders::Scenes::GameScene::getLvlController()
{
    return &this->lvlController;
}

void SpaceInvaders::Scenes::GameScene::startLevel(int level, Factories::GameFactory* factory,
                                                  Assets::Sprites::SpriteLoader* spriteLoader)
{
    this->getLvlController()->startLevel(level, factory, spriteLoader);
    for(auto* enemy : *this->lvlController.getEnemyController()->getEnemies())
    {
        this->gameObjects.push_back(enemy);
    }
}

void SpaceInvaders::Scenes::GameScene::lateUpdate()
{
    this->lvlController.getEnemyController()->lateUpdate();

    int i = 0;
    while(i < this->gameObjects.size())
    {
        auto* go = this->gameObjects.at(i);
        if(go->getTag() == GameObjects::GameObjectTag::BULLET && (go->isOutOfScreenY() || go->isRemovable()) )
        {
            this->gameObjects.erase(this->gameObjects.begin() + i);
        }
        else if(go->getTag() == GameObjects::GameObjectTag::ENEMY && go->isRemovable())
        {
            this->gameObjects.erase(this->gameObjects.begin() + i);
        }
        else
        {
            i++;
        }
    }
}
