#include "GameScene.h"
#include "../Controllers/GameController.h"

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

    this->background = loader->loadSprite("Assets\\Sprites\\Background.png");
}

void SpaceInvaders::Scenes::GameScene::draw(Windows::Window* window)
{
    window->setBackground(this->background);
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
