#include "LoadScene.h"
#include "../Controllers/GameController.h"

void SpaceInvaders::Scenes::LoadScene::update(double deltaTime)
{
    if(this->loadThread.wait_for(std::chrono::seconds(0)) == std::future_status::ready)
    {
        Controllers::GameController::getInstance().loadScene(Controllers::SceneEnum::GAME);
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
        window->setBackground(spriteLoader->loadSprite(R"(Assets\Sprites\Background.png)"));
    }
}

void loadAssetsAsync(SpaceInvaders::Scenes::LoadScene* loadScene)
{
    auto* spriteLoader = SpaceInvaders::Controllers::GameController::getInstance().getSpriteLoader();
    auto* fontLoader = SpaceInvaders::Controllers::GameController::getInstance().getFontLoader();

    spriteLoader->loadSprite(R"(Assets\Sprites\Background.png)");
    loadScene->addProgress();

    spriteLoader->loadSprite(R"(Assets\Sprites\Player\Player.png)");
    loadScene->addProgress();

    spriteLoader->loadSprite(R"(Assets\Sprites\Enemies\Enemy1.png)");
    loadScene->addProgress();

    fontLoader->loadFont("regular", "Assets/Fonts/8bitRegular.ttf");
    loadScene->addProgress();
    fontLoader->loadFont("bold", "Assets/Fonts/8bitBold.ttf");
    loadScene->addProgress();

    std::this_thread::sleep_for (std::chrono::seconds(1));
}
