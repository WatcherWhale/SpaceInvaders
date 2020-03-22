#include "GameOverScene.h"
#include "../Controllers/GameController.h"

using namespace SpaceInvaders::Controllers;

void SpaceInvaders::Scenes::GameOverScene::load()
{
    auto* fontLoader = GameController::getInstance().getFontLoader();
    auto* txt = GameController::getInstance().getFactory()->createText("Game Over",
            fontLoader->getFont("regular"), Color(255,255,255),
            100, 100);

    this->ui.push_back(txt);
}
