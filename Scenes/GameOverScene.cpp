#include "GameOverScene.h"
#include "../Controllers/GameController.h"
#include <cmath>

using namespace SpaceInvaders::Controllers;

void SpaceInvaders::Scenes::GameOverScene::load()
{
    auto* fontLoader = GameController::getInstance().getFontLoader();

    // Create game over title
    auto* gameOverTxt = GameController::getInstance().getFactory()->getUiFactory()
            ->createText("Game Over",fontLoader->getFont("bold"), Color(255,255,255), 0, 0);

    gameOverTxt->scale(2);
    gameOverTxt->setPosition(std::lround( (GameConstants::WINDOW_SIZE_X - gameOverTxt->getSize()[0]) / 2.0),
            gameOverTxt->getPosition()[1]);

    // Create points scored text
    std::string pointsStr = "You scored: " + std::to_string(Controllers::GameController::getInstance().getPoints()) + " pts";
    auto* pointsTxt = GameController::getInstance().getFactory()->getUiFactory()
            ->createText(pointsStr, fontLoader->getFont("regular"), Color(255, 255, 255), 0,
                         std::lround(gameOverTxt->getSize()[1]));

    pointsTxt->setPosition(std::lround((GameConstants::WINDOW_SIZE_X - pointsTxt->getSize()[0])/2.0),
                           pointsTxt->getPosition()[1]);

    // Create Restart Button
    auto* restartButton = GameController::getInstance().getFactory()->getUiFactory()
            ->createButton(500, pointsTxt->getPosition()[1] + 20, 270, 70);
    restartButton->setSprite(GameController::getInstance().getSpriteLoader()->loadSprite("Assets/Sprites/Button.png", true));
    restartButton->setPosition(std::lround((GameConstants::WINDOW_SIZE_X - restartButton->getSize()[0]) / 2.0),
            restartButton->getPosition()[1]);

    auto* restartButtonText = GameController::getInstance().getFactory()->getUiFactory()
            ->createText("Restart", GameController::getInstance().getFontLoader()->getFont("regular"), Color(0,0,0),
                         std::lround(restartButton->getPosition()[0] + 20 * GameConstants::SCALE_X),
                         restartButton->getPosition()[1], 160, 70);

    double twTh = restartButtonText->getTextSize()[0] / restartButtonText->getTextSize()[1];
    restartButtonText->setSize(twTh * restartButtonText->getSize()[1], restartButtonText->getSize()[1]);
    double offset = (restartButton->getSize()[0] - twTh * restartButtonText->getSize()[1]) / 2.0;

    restartButtonText->setPosition(std::lround(restartButton->getPosition()[0] + offset), restartButtonText->getPosition()[1]);


    restartButton->setText(restartButtonText);

    restartButton->addClickListener(this, [](void* listener)
    {
        GameController::getInstance().loadScene(SceneEnum::GAME);
    });

    // Create Menu Button
    auto* menuButton = GameController::getInstance().getFactory()->getUiFactory()
            ->createButton(500, restartButton->getPosition()[1] + 20, 270, 70);
    menuButton->setSprite(GameController::getInstance().getSpriteLoader()->loadSprite("Assets/Sprites/Button.png", true));
    menuButton->setPosition(std::lround((GameConstants::WINDOW_SIZE_X - menuButton->getSize()[0]) / 2.0),
            menuButton->getPosition()[1]);

    auto* menuButtonText = GameController::getInstance().getFactory()->getUiFactory()
            ->createText("Menu", GameController::getInstance().getFontLoader()->getFont("regular"), Color(0,0,0),
                         std::lround(menuButton->getPosition()[0] + 20 * GameConstants::SCALE_X),
                         menuButton->getPosition()[1], 160, 70);

    twTh = menuButtonText->getTextSize()[0] / menuButtonText->getTextSize()[1];
    menuButtonText->setSize(twTh * menuButtonText->getSize()[1], menuButtonText->getSize()[1]);
    offset = (menuButton->getSize()[0] - twTh * menuButtonText->getSize()[1]) / 2.0;

    menuButtonText->setPosition(std::lround(menuButton->getPosition()[0] + offset), menuButtonText->getPosition()[1]);

    menuButton->setText(menuButtonText);

    menuButton->addClickListener(this, [](void* listener)
    {
        GameController::getInstance().loadScene(SceneEnum::MENU);
    });


    this->ui.push_back(gameOverTxt);
    this->ui.push_back(pointsTxt);
    this->ui.push_back(restartButton);
    this->ui.push_back(menuButton);

    this->eventListeners.push_back(restartButton);
    this->eventListeners.push_back(menuButton);

    // Clear everything
    GameController::getInstance().clearPoints();
    GameController::getInstance().resetLevel();
}
