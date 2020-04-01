#include "Game.h"
using namespace SpaceInvaders;
using namespace SpaceInvaders::Controllers;

Game::Game(GameFactory* factory)
{
	this->factory = factory;
	GameController::getInstance().setFactory(this->factory);
}

void Game::run()
{
	// Create Windows
	this->window = this->factory->createWindow(reinterpret_cast<void*>(this),
	        "SpaceInvaders", WINDOW_SIZE_X, WINDOW_SIZE_Y);
    this->window->setClearColor(0, 0, 0);

	if(this->window->create())
    {
        GameController::getInstance().setWindow(this->window);

	    while(GameController::getInstance().isRunning())
        {
            GameController::getInstance().getTimer()->start();
            this->window->clear();

            if(GameController::getInstance().getCurrentScene() != nullptr)
            {
                GameController::getInstance().getCurrentScene()
                    ->update(GameController::getInstance().getTimer()->getDeltaTime());

                GameController::getInstance().getCurrentScene()->draw(this->window);
            }
            else
            {
                GameController::getInstance().loadScene(SpaceInvaders::Controllers::SceneEnum::LOAD);
            }

            this->window->draw();
            this->window->pollEvents();

            if(GameController::getInstance().getCurrentScene() != nullptr)
                GameController::getInstance().getCurrentScene()->lateUpdate();

            GameController::getInstance().getTimer()->stop();
        }
    }

	GameController::getInstance().unload();
    this->window->destroy();
}