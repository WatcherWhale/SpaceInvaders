#include "GameScene.h"
#include "../Controllers/GameController.h"
#include "../GameObjects/Bullet.h"

SpaceInvaders::Scenes::GameScene::GameScene()
{
    this->lvlController = new SpaceInvaders::Controllers::LevelController();
}

SpaceInvaders::Scenes::GameScene::~GameScene()
{
    delete this->lvlController;
}


void SpaceInvaders::Scenes::GameScene::update(double deltaTime)
{
    // Call default update method
    Scene::update(deltaTime);

    int i = 0;
    while(i < this->gameObjects.size())
    {
        auto* go = this->gameObjects.at(i);
        if(go->getTag() == GameObjects::GameObjectTag::BULLET && go->isOutOfScreenY())
        {
            this->gameObjects.erase(this->gameObjects.begin() + i);
        }
        else
        {
            i++;
        }
    }

    // Update Enemy controller
    this->lvlController->getEnemyController()->update(deltaTime);
}

void SpaceInvaders::Scenes::GameScene::load()
{
    auto* loader = Controllers::GameController::getInstance().getSpriteLoader();
    auto* player = new GameObjects::Player();
    player->loadSprites(loader);

    this->gameObjects.push_back(player);
    this->eventListeners.push_back(player);
}

void SpaceInvaders::Scenes::GameScene::draw(Windows::Window* window)
{
    Scene::draw(window);

    for(auto* enemy : *this->lvlController->getEnemyController()->getEnemies())
    {
        window->queueSprite(enemy->getSprite(), enemy->getPosition(), enemy->getBounds());
    }
}

SpaceInvaders::Controllers::LevelController* SpaceInvaders::Scenes::GameScene::getLvlController()
{
    return this->lvlController;
}
