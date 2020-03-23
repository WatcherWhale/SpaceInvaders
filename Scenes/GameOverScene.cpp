#include "GameOverScene.h"
#include "../Controllers/GameController.h"
#include <cmath>

using namespace SpaceInvaders::Controllers;

void SpaceInvaders::Scenes::GameOverScene::load()
{
    auto* fontLoader = GameController::getInstance().getFontLoader();

    auto* gameOverTxt = GameController::getInstance().getFactory()
            ->createText("Game Over",fontLoader->getFont("bold"), Color(255,255,255), 0, 0);

    //TODO: WHAT DO THE NUMBERS MEAN

    gameOverTxt->setPosition(std::lround( (WINDOW_SIZE_X - gameOverTxt->getSize()[0]) / 2.0),
            gameOverTxt->getPosition()[1]);

    auto* pointsTxt = GameController::getInstance().getFactory()
            ->createText("You scored: 0 pts",fontLoader->getFont("regular"), Color(255,255,255), 0,
                    std::lround(gameOverTxt->getSize()[1] + 30 * SCALE_Y));

    pointsTxt->setPosition(std::lround((WINDOW_SIZE_X - pointsTxt->getSize()[0])/2.0),
                           pointsTxt->getPosition()[1]);

    this->ui.push_back(gameOverTxt);
    this->ui.push_back(pointsTxt);
}
