#include "Game.h"
#include "Settings.h"

using namespace SpaceInvaders;
using namespace SpaceInvaders::Controllers;

Game::Game(GameFactory* factory)
{
    // Load the settings from the settings file
    Settings::load("settings.conf");

    // Set the factory
	this->factory = factory;
	GameController::getInstance().setFactory(this->factory);
}

void Game::run()
{
	// Create Window
	this->window = this->factory->createWindow(reinterpret_cast<void*>(this),
	        "SpaceInvaders", GameConstants::WINDOW_SIZE_X, GameConstants::WINDOW_SIZE_Y, GameConstants::WINDOW_FULLSCREEN);
    this->window->setClearColor(0, 0, 0);

	if(this->window->create())
    {
        GameController::getInstance().setWindow(this->window);

        // Start game loop
	    while(GameController::getInstance().isRunning())
        {
	        // Start the timer
            GameController::getInstance().getTimer()->start();

            // Clear the window
            this->window->clear();

            if(GameController::getInstance().getCurrentScene() != nullptr)
            {
                // Update & Draw the current scene
                GameController::getInstance().getCurrentScene()
                    ->update(GameController::getInstance().getTimer()->getDeltaTime());

                GameController::getInstance().getCurrentScene()->draw(this->window);
            }
            else
            {
                // If there is no scene loaded, load the load scene
                GameController::getInstance().loadScene(SpaceInvaders::Controllers::SceneEnum::LOAD);
            }

            // Draw everything on the window
            this->window->draw();

            // Poll the events
            this->window->pollEvents();

            // Perform late update on the current scene
            if(GameController::getInstance().getCurrentScene() != nullptr)
                GameController::getInstance().getCurrentScene()->lateUpdate();

            // Stop the timer & calculate frame time
            GameController::getInstance().getTimer()->stop();
        }
    }

	// Unload the game controller
	GameController::getInstance().unload();
	// Destroy the window
    this->window->destroy();
}