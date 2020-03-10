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
    this->isRunning = true;

	// Create Windows
	this->window = this->factory->createWindow(reinterpret_cast<void*>(this),
	        "SpaceInvaders", WINDOW_SIZE_X, WINDOW_SIZE_Y);
    this->window->setClearColor(0,0,0);
    this->window->setBackgroundMusic("Assets/Audio/Music/we_are_number_one_8_bit.mp3");

	if(this->window->create())
    {
        //auto icon = this->controller->getSpriteLoader()->loadSprite("Assets/Sprites/Player/Player.png");
        //auto backgroundSprite = this->controller->getSpriteLoader()->loadSprite("Assets\\Sprites\\Background.png");

        //this->fontLoader->loadFont("regular", "Assets/Fonts/8bitRegular.ttf");
        //this->fontLoader->loadFont("bold", "Assets/Fonts/8bitBold.ttf");

        //this->window->setBackground(backgroundSprite);
        //this->window->setIcon(icon);

	    while(isRunning)
        {
            this->window->pollEvents();

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
        }

        this->window->clear();
        this->window->draw();
    }

    delete &GameController::getInstance();
    this->window->destroy();
}

void Game::stop()
{
    this->isRunning = false;
}

SpaceInvaders::Events::EventHandler* Game::getEventHandler()
{
    return GameController::getInstance().getEventHandler();
}
