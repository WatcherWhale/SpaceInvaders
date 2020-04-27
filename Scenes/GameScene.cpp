#include "GameScene.h"
#include "../Controllers/GameController.h"
#include <string>

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

    ptsText = Controllers::GameController::getInstance().getFactory()->getUiFactory()
            ->createText("0 pts",
                Controllers::GameController::getInstance().getFontLoader()->getFont("regular"), Color(255, 255, 255),
                0, 0);

    auto* size = ptsText->getTextSize();
    ptsText->setSize(size[0] / 2, size[1] / 2);
    ptsText->setPosition(20, GameConstants::WINDOW_SIZE_Y - 2 * ptsText->getSize()[1] - 20);

    livesText = Controllers::GameController::getInstance().getFactory()->getUiFactory()
            ->createText("3 lives",
                         Controllers::GameController::getInstance().getFontLoader()->getFont("regular"), Color(255, 255, 255),
                         0, 0);

    size = livesText->getTextSize();
    livesText->setSize(size[0] / 2, size[1] / 2);
    livesText->setPosition(20, GameConstants::WINDOW_SIZE_Y - livesText->getSize()[1] - 20);

    levelText = Controllers::GameController::getInstance().getFactory()->getUiFactory()
            ->createText("Level " + std::to_string(Controllers::GameController::getInstance().getLevel() + 1),
                         Controllers::GameController::getInstance().getFontLoader()->getFont("regular"), Color(255, 255, 255),
                         0, 0);

    size = levelText->getTextSize();
    levelText->setSize(size[0] / 2, size[1] / 2);
    levelText->setPosition(20, GameConstants::WINDOW_SIZE_Y - 3 * levelText->getSize()[1] - 20);

    this->ui.push_back(ptsText);
    this->ui.push_back(livesText);
    this->ui.push_back(levelText);
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

    ptsText->setText(std::to_string(Controllers::GameController::getInstance().getPoints()) + " pts");
    livesText->setText(std::to_string(Controllers::GameController::getInstance().getLives()) + " lives");

    auto* size = ptsText->getTextSize();
    ptsText->setSize(size[0] / 2, size[1] / 2);

    size = livesText->getTextSize();
    livesText->setSize(size[0] / 2, size[1] / 2);

    if(this->lvlController.getEnemyController()->getEnemies()->empty())
    {
        Controllers::GameController::getInstance().loadScene(Controllers::SceneEnum::GAME);
    }
}