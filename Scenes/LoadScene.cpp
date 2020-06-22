#include "LoadScene.h"
#include "../Controllers/GameController.h"

using namespace SpaceInvaders;

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
        window->setBackground(spriteLoader->loadSprite(GameConstants::getAsset("Sprites/Background.png"), true));
    }
}

void loadAssetsAsync(SpaceInvaders::Scenes::LoadScene* loadScene)
{
    auto* spriteLoader = SpaceInvaders::Controllers::GameController::getInstance().getSpriteLoader();
    auto* fontLoader = SpaceInvaders::Controllers::GameController::getInstance().getFontLoader();
    auto* audioLoader = SpaceInvaders::Controllers::GameController::getInstance().getAudioLoader();

    // Pre load sprites
    auto* icon = spriteLoader->loadSprite(GameConstants::getAsset("Sprites/Icon.png"), false);
    SpaceInvaders::Controllers::GameController::getInstance().getWindow()->setIcon(icon);
    loadScene->addProgress();

    spriteLoader->loadSprite(GameConstants::getAsset("Sprites/Background.png"), true);
    loadScene->addProgress();
    spriteLoader->loadSprite(GameConstants::getAsset("Sprites/Player/Player.png"), true);
    spriteLoader->loadSprite(GameConstants::getAsset("Sprites/Enemies/Enemy1.png"), true);
    spriteLoader->loadSprite(GameConstants::getAsset("Sprites/Player/Bullet.png"), true);
    spriteLoader->loadSprite(GameConstants::getAsset("Sprites/Enemies/Bullet.png"), true);
    spriteLoader->loadSprite(GameConstants::getAsset("Sprites/Button.png"), true);

    spriteLoader->loadSprite(GameConstants::getAsset("Sprites/Bunkers/Bunker1.png"), true);
    spriteLoader->loadSprite(GameConstants::getAsset("Sprites/Bunkers/Bunker2.png"), true);
    spriteLoader->loadSprite(GameConstants::getAsset("Sprites/Bunkers/Bunker3.png"), true);
    spriteLoader->loadSprite(GameConstants::getAsset("Sprites/Bunkers/Bunker4.png"), true);

    // Pre load fonts
    fontLoader->loadFont("regular", GameConstants::getAsset("Fonts/8bitRegular.ttf"));
    fontLoader->loadFont("bold", GameConstants::getAsset("Fonts/8bitBold.ttf"));

    // Pre load audio
    auto mus = audioLoader->loadMusic(GameConstants::getAsset("Audio/Music/we_are_number_one_8_bit.wav"));
    mus->play(true);

    audioLoader->loadAudioClip(GameConstants::getAsset("Audio/SFX/button.wav"));
    audioLoader->loadAudioClip(GameConstants::getAsset("Audio/SFX/death.wav"));
    audioLoader->loadAudioClip(GameConstants::getAsset("Audio/SFX/shoot.wav"));
    audioLoader->loadAudioClip(GameConstants::getAsset("Audio/SFX/gameover.wav"));
    audioLoader->loadAudioClip(GameConstants::getAsset("Audio/SFX/enemyshoot.wav"));
}
