#include <cmath>
#include "MenuScene.h"
#include "../Controllers/GameController.h"

using namespace SpaceInvaders::Scenes;
using namespace SpaceInvaders::Controllers;

void MenuScene::load()
{
    auto* fontLoader = GameController::getInstance().getFontLoader();

    auto* gameTitle = GameController::getInstance().getFactory()->getUiFactory()
            ->createText("SpaceInvaders",fontLoader->getFont("bold"), Color(255,255,255), 0, 0);

    gameTitle->scale(2);
    gameTitle->setPosition(std::lround((GameConstants::WINDOW_SIZE_X - gameTitle->getSize()[0]) / 2.0),
                           gameTitle->getPosition()[1]);

    auto* copyrightTitle = GameController::getInstance().getFactory()->getUiFactory()
            ->createText("By Mathias Maes ©2020", fontLoader->getFont("regular"), Color(255, 255, 255), 0,
                         std::lround(gameTitle->getSize()[1]));

    copyrightTitle->setPosition(std::lround((GameConstants::WINDOW_SIZE_X - copyrightTitle->getSize()[0])/2.0),
                                copyrightTitle->getPosition()[1]);


    auto* startButton = GameController::getInstance().getFactory()->getUiFactory()
            ->createButton(500, copyrightTitle->getPosition()[1] + 100, 270, 70);
    startButton->setSprite(GameController::getInstance().getSpriteLoader()->loadSprite("Assets/Sprites/Button.png", true));
    startButton->setPosition(std::lround((GameConstants::WINDOW_SIZE_X - startButton->getSize()[0]) / 2.0),
                             startButton->getPosition()[1]);

    auto* startButtonText = GameController::getInstance().getFactory()->getUiFactory()
            ->createText("Start", GameController::getInstance().getFontLoader()->getFont("regular"), Color(0,0,0),
                         std::lround(startButton->getPosition()[0] + 20 * GameConstants::SCALE_X),
                         startButton->getPosition()[1], 160, 70);

    double twTh = startButtonText->getTextSize()[0] / startButtonText->getTextSize()[1];
    startButtonText->setSize(twTh * startButtonText->getSize()[1], startButtonText->getSize()[1]);
    double offset = (startButton->getSize()[0] - twTh * startButtonText->getSize()[1]) / 2.0;

    startButtonText->setPosition(std::lround(startButton->getPosition()[0] + offset), startButtonText->getPosition()[1]);


    startButton->setText(startButtonText);

    startButton->addClickListener(this, [](void* listener)
    {
        GameController::getInstance().loadScene(SceneEnum::GAME);
    });


    auto* exitButton = GameController::getInstance().getFactory()->getUiFactory()
            ->createButton(500, startButton->getPosition()[1] + 20, 270, 70);
    exitButton->setSprite(GameController::getInstance().getSpriteLoader()->loadSprite("Assets/Sprites/Button.png", true));
    exitButton->setPosition(std::lround((GameConstants::WINDOW_SIZE_X - exitButton->getSize()[0]) / 2.0),
                            exitButton->getPosition()[1]);

    auto* exitButtonText = GameController::getInstance().getFactory()->getUiFactory()
            ->createText("Exit", GameController::getInstance().getFontLoader()->getFont("regular"), Color(0,0,0),
                         std::lround(exitButton->getPosition()[0] + 20 * GameConstants::SCALE_X),
                         exitButton->getPosition()[1], 160, 70);

    twTh = exitButtonText->getTextSize()[0] / exitButtonText->getTextSize()[1];
    exitButtonText->setSize(twTh * exitButtonText->getSize()[1], exitButtonText->getSize()[1]);
    offset = (exitButton->getSize()[0] - twTh * exitButtonText->getSize()[1]) / 2.0;

    exitButtonText->setPosition(std::lround(exitButton->getPosition()[0] + offset), exitButtonText->getPosition()[1]);

    exitButton->setText(exitButtonText);

    exitButton->addClickListener(this, [](void* listener)
    {
        GameController::getInstance().stopGame();
    });

    this->ui.push_back(gameTitle);
    this->ui.push_back(copyrightTitle);
    this->ui.push_back(startButton);
    this->ui.push_back(exitButton);

    this->eventListeners.push_back(startButton);
    this->eventListeners.push_back(exitButton);
}
