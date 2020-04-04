#include "LoadScene.h"
#include "../Controllers/GameController.h"

void SpaceInvaders::Scenes::LoadScene::update(double deltaTime)
{
    if(this->loadThread.wait_for(std::chrono::seconds(0)) == std::future_status::ready)
    {
        Controllers::GameController::getInstance().loadScene(Controllers::SceneEnum::GAMEOVER);
    }
}

void SpaceInvaders::Scenes::LoadScene::load()
{
    this->loadThread = std::async(loadAssetsAsync, this);
}

void SpaceInvaders::Scenes::LoadScene::addProgress()
{
    this->progress++;
}

void SpaceInvaders::Scenes::LoadScene::draw(SpaceInvaders::Windows::Window* window)
{
    if(this->progress >= 1)
    {
        auto* spriteLoader = SpaceInvaders::Controllers::GameController::getInstance().getSpriteLoader();
        window->setBackground(spriteLoader->loadSprite("Assets/Sprites/Background.png", true));
    }
}

void loadAssetsAsync(SpaceInvaders::Scenes::LoadScene* loadScene)
{
    auto* spriteLoader = SpaceInvaders::Controllers::GameController::getInstance().getSpriteLoader();
    auto* fontLoader = SpaceInvaders::Controllers::GameController::getInstance().getFontLoader();

    // Pre load sprites
    spriteLoader->loadSprite("Assets/Sprites/Background.png", true);
    loadScene->addProgress();

    spriteLoader->loadSprite("Assets/Sprites/Player/Player.png", true);
    loadScene->addProgress();

    spriteLoader->loadSprite("Assets/Sprites/Enemies/Enemy1.png", true);
    loadScene->addProgress();

    spriteLoader->loadSprite("Assets/Sprites/Player/Bullet.png", true);
    loadScene->addProgress();

    spriteLoader->loadSprite("Assets/Sprites/Enemies/Bullet.png", true);
    loadScene->addProgress();

    spriteLoader->loadSprite("Assets/Sprites/Button.png", true);
    loadScene->addProgress();

    // Pre load fonts
    fontLoader->loadFont("regular", "Assets/Fonts/8bitRegular.ttf");
    loadScene->addProgress();
    fontLoader->loadFont("bold", "Assets/Fonts/8bitBold.ttf");
    loadScene->addProgress();

    // Pre load audio
    // TODO

    // Wait for a second for aesthetics
    std::this_thread::sleep_for (std::chrono::seconds(1));
}
