#include "GameController.h"
#include "../Scenes/GameScene.h"
#include "../Scenes/LoadScene.h"
#include "../Scenes/GameOverScene.h"
#include "../Scenes/MenuScene.h"

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
    this->audioLoader = factory->createAudioLoader();

    this->timer = factory->createTimer();
}

void SpaceInvaders::Controllers::GameController::loadScene(SpaceInvaders::Controllers::SceneEnum scene)
{
    if(!this->running) return;

    if(this->currentScene != nullptr)
    {
        delete this->currentScene;
    }

    this->eventHandler->clearListeners();

    if(scene == SceneEnum::GAME)
    {
        auto* scene = new Scenes::GameScene();
        scene->load();

        this->currentLevel++;
        scene->startLevel(this->currentLevel, this->factory, this->spriteLoader);
        this->currentScene = scene;
    }
    else if(scene == SceneEnum::LOAD)
    {
        this->currentScene = new Scenes::LoadScene();
        this->currentScene->load();
    }
    else if(scene == SceneEnum::GAMEOVER)
    {
        this->currentScene = new Scenes::GameOverScene();
        this->currentScene->load();
    }
    else if(scene == SceneEnum::MENU)
    {
        this->currentScene = new Scenes::MenuScene();
        this->currentScene->load();
    }

    for(auto* listener : *this->currentScene->getListeners())
    {
        this->eventHandler->addListener(listener);
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

void SpaceInvaders::Controllers::GameController::unload()
{
    delete this->currentScene;
    delete this->eventHandler;
    delete this->fontLoader;
    delete this->spriteLoader;
}

void SpaceInvaders::Controllers::GameController::stopGame()
{
    this->running = false;
}

bool SpaceInvaders::Controllers::GameController::isRunning()
{
    return this->running;
}

SpaceInvaders::Utils::Timer* SpaceInvaders::Controllers::GameController::getTimer()
{
    return this->timer;
}

void SpaceInvaders::Controllers::GameController::setWindow(Windows::Window* window)
{
    this->window = window;
}

SpaceInvaders::Windows::Window* SpaceInvaders::Controllers::GameController::getWindow()
{
    return this->window;
}

void SpaceInvaders::Controllers::GameController::addPoints(int points)
{
    this->points += points;
}

int SpaceInvaders::Controllers::GameController::getPoints()
{
    return this->points;
}

void SpaceInvaders::Controllers::GameController::clearPoints()
{
    this->points = 0;
}

void SpaceInvaders::Controllers::GameController::resetLevel()
{
    this->currentLevel = 0;
    this->lives = 3;
    for(int i = 0; i < 4; i++) this->bunkerHealth[i] = 0;
}

int SpaceInvaders::Controllers::GameController::getLevel()
{
    return this->currentLevel;
}

int SpaceInvaders::Controllers::GameController::getLives()
{
    return this->lives;
}

void SpaceInvaders::Controllers::GameController::setLives(int lives)
{
    this->lives = lives;
}

SpaceInvaders::Assets::Audio::AudioLoader* SpaceInvaders::Controllers::GameController::getAudioLoader()
{
    return this->audioLoader;
}

int SpaceInvaders::Controllers::GameController::getBunkerHealth(int i)
{
    return this->bunkerHealth[i];
}

void SpaceInvaders::Controllers::GameController::setBunkerHealth(int i, int health)
{
    this->bunkerHealth[i] = health;
}

