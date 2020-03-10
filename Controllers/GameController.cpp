#include "GameController.h"
#include "../Scenes/GameScene.h"
#include "../Scenes/LoadScene.h"

SpaceInvaders::Controllers::GameController::GameController()
{
    this->eventHandler = new Events::EventHandler();
}

void SpaceInvaders::Controllers::GameController::setFactory(Factories::GameFactory* factory)
{
    this->factory = factory;

    // Create asset loaders
    this->spriteLoader = factory->createSpriteLoader();
    this->fontLoader = factory->createFontLoader();
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
        auto* scene = new Scenes::GameScene();
        scene->load();

        for(auto* listener : *scene->getListeners())
        {
            this->eventHandler->addListener(listener);
        }

        scene->getLvlController()->startLevel(this->currentLevel, this->factory, this->spriteLoader);
        this->currentScene = scene;
    }
    else if(scene == SceneEnum::LOAD)
    {
        this->currentScene = new Scenes::LoadScene();
        this->currentScene->load();
    }
}

SpaceInvaders::Events::EventHandler* SpaceInvaders::Controllers::GameController::getEventHandler()
{
    return this->eventHandler;
}

SpaceInvaders::Scenes::Scene* SpaceInvaders::Controllers::GameController::getCurrentScene()
{
    return this->currentScene;
}

SpaceInvaders::Factories::GameFactory* SpaceInvaders::Controllers::GameController::getFactory()
{
    return this->factory;
}

SpaceInvaders::Assets::Sprites::SpriteLoader* SpaceInvaders::Controllers::GameController::getSpriteLoader()
{
    return this->spriteLoader;
}

SpaceInvaders::Assets::FontLoader* SpaceInvaders::Controllers::GameController::getFontLoader()
{
    return this->fontLoader;
}
