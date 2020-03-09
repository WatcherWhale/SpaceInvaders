#include "GameScene.h"

SpaceInvaders::Scenes::GameScene::GameScene()
{
    this->lvlController = new SpaceInvaders::Controllers::LevelController();
}

SpaceInvaders::Scenes::GameScene::~GameScene()
{
    // Unload enemy controller
    delete this->lvlController;
}


void SpaceInvaders::Scenes::GameScene::update(double deltaTime)
{
    // Call default update method
    Scene::update(deltaTime);

    // Update Enemy controller
    this->lvlController->getEnemyController()->update(deltaTime);
}

void SpaceInvaders::Scenes::GameScene::load(Factories::GameFactory* factory, Assets::Sprites::SpriteLoader* loader)
{
    this->lvlController->startLevel(factory, loader);
    auto* player = new GameObjects::Player();
    player->loadSprites(loader);

    this->gameObjects.push_back(player);
    this->eventListeners.push_back(player);

    this->lvlController->startLevel(factory, loader);
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
