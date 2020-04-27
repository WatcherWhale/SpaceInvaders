#include "GameScene.h"
#include "../Controllers/GameController.h"

SpaceInvaders::Scenes::GameScene::GameScene()
{
    this->lvlController = SpaceInvaders::Controllers::LevelController();
}

SpaceInvaders::Scenes::GameScene::~GameScene()
{
    unsigned long shootCallbackId = this->getLvlController()->getEnemyController()->getShootCallbackId();
    unsigned long bonusCallbackId = this->getLvlController()->getEnemyController()->getBonusCallbackId();
    Controllers::GameController::getInstance().getTimer()->stopCallback(shootCallbackId);
    Controllers::GameController::getInstance().getTimer()->stopCallback(bonusCallbackId);
}


void SpaceInvaders::Scenes::GameScene::update(double deltaTime)
{
    // Call default update method
    Scene::update(deltaTime);

    if(this->getLvlController()->getPlayer()->getLives() <= 0)
    {
        Controllers::GameController::getInstance().loadScene(Controllers::SceneEnum::GAMEOVER);
        return;
    }

    // Update Enemy controller
    this->lvlController.getEnemyController()->update(deltaTime);
}

void SpaceInvaders::Scenes::GameScene::load()
{
    auto* loader = Controllers::GameController::getInstance().getSpriteLoader();
    auto* player = Controllers::GameController::getInstance().getFactory()
            ->createPlayer(Controllers::GameController::getInstance().getLives());

    player->loadSprites(loader);
    this->lvlController.setPlayer(player);

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
        else if(go->isRemovable())
        {
            this->gameObjects.erase(this->gameObjects.begin() + i);
        }
        else
        {
            i++;
        }
    }

    if(this->lvlController.getEnemyController()->getEnemies()->empty())
    {
        Controllers::GameController::getInstance().loadScene(Controllers::SceneEnum::GAME);
    }
}