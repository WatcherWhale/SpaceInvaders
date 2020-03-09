#include "GameController.h"
#include "../Scenes/GameScene.h"

SpaceInvaders::Controllers::GameController::GameController(SpaceInvaders::Factories::GameFactory* factory)
{
    this->factory = factory;
    this->spriteLoader = factory->createSpriteLoader();
    this->eventHandler = new Events::EventHandler();
}

SpaceInvaders::Controllers::GameController::~GameController()
{
    delete this->eventHandler;
}

void SpaceInvaders::Controllers::GameController::loadScene(SpaceInvaders::Controllers::SceneEnum scene)
{
    if(this->currentScene != nullptr)
    {
        delete this->currentScene;
    }

    if(scene == SceneEnum::GAME)
    {
        this->currentScene = new Scenes::GameScene();
    }
}

SpaceInvaders::Events::EventHandler* SpaceInvaders::Controllers::GameController::getEventHandler()
{
    return this->eventHandler;
}
