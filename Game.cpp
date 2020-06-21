#include "Game.h"
#include "Utils/JsonFile.h"

using namespace SpaceInvaders;
using namespace SpaceInvaders::Controllers;

Game::Game(GameFactory* factory)
{
    // Load the settings from the settings file
    this->loadSettings();

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

void Game::loadSettings()
{
    Utils::JsonFile settings = Utils::JsonFile::load("settings.json");

    // Load Video
    GameConstants::WINDOW_SIZE_X = settings.getObject("video")->at("width");
    GameConstants::WINDOW_SIZE_Y = settings.getObject("video")->at("height");

    GameConstants::WINDOW_FULLSCREEN = settings.getObject("video")->at("fullscreen");

    int fps = settings.getObject("video")->at("fps");
    GameConstants::FPS_TIME = 1000 / fps;

    GameConstants::recalculate();

    // Load volume
    GameConstants::MUSIC_VOLUME = settings.getObject("volume")->at("music");
    GameConstants::CLIP_VOLUME = settings.getObject("volume")->at("sfx");

    GameConstants::TEXTURE_PACK = settings.getString("texturepack");
}
