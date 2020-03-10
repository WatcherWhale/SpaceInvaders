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
    this->window->setClearColor(0,0,0);

	if(this->window->create())
    {
	    while(GameController::getInstance().isRunning())
        {
            this->window->clear();

            if(GameController::getInstance().getCurrentScene() != nullptr)
            {
                GameController::getInstance().getCurrentScene()->update(this->window->getDeltaTime());
                GameController::getInstance().getCurrentScene()->draw(this->window);
            }
            else
            {
                GameController::getInstance().loadScene(SpaceInvaders::Controllers::SceneEnum::LOAD);
            }

            this->window->draw();
            this->window->pollEvents();
        }
    }

	GameController::getInstance().unload();
    this->window->destroy();
}