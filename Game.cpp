#include "Game.h"
using namespace SpaceInvaders;

Game::Game(GameFactory* factory)
{
	this->factory = factory;
    this->spriteLoader = this->factory->createSpriteLoader();
    this->fontLoader = this->factory->createFontLoader();

	this->eventHandler = EventHandler();
	this->controller = Controllers::LevelController();
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
	    this->createObjects();

        auto icon = this->spriteLoader->loadSprite("Assets/Sprites/Player/Player.png");
        auto backgroundSprite = this->spriteLoader->loadSprite("Assets\\Sprites\\Background.png");

        this->fontLoader->loadFont("regular", "Assets/Fonts/8bitRegular.ttf");
        this->fontLoader->loadFont("bold", "Assets/Fonts/8bitBold.ttf");

        this->window->setBackground(backgroundSprite);
        this->window->setIcon(icon);

        auto* txt = this->factory->createText("Space Invaders By Mathias Maes",
                this->fontLoader->getFont("bold"), Color(255, 255, 255), 10, WINDOW_SIZE_Y - 36);

	    while(isRunning)
        {
            this->window->pollEvents();

            for (auto go : this->gameObjects)
            {
                go->update(this->window->getDeltaTime());
                this->window->queueSprite(go->getSprite(), go->getPosition(), go->getBounds());
            }

            if(!this->controller.isLevelStarted())
            {
                this->controller.startLevel(this->factory, this->spriteLoader);
            }

            auto enemyController = this->controller.getEnemyController();
            enemyController->update(this->window->getDeltaTime());
            for(auto enemy : *enemyController->getEnemies())
            {
                this->window->queueSprite(enemy->getSprite(), enemy->getPosition(), enemy->getBounds());
            }

            this->window->queueText(txt);

            this->window->clear();
            this->window->draw();
        }

        icon->unload();
        backgroundSprite->unload();

	    this->fontLoader->unload();

	    this->window->destroy();
    }
}

void Game::stop()
{
    this->isRunning = false;
}

EventHandler* Game::getEventHandler()
{
    return &this->eventHandler;
}

void Game::createObjects()
{
    // Load Player
    this->controller.setPlayer( this->factory->createPlayer());
    this->controller.getPlayer()->loadSprites(this->spriteLoader);
    this->eventHandler.addListener(this->controller.getPlayer());
    this->gameObjects.push_back(this->controller.getPlayer());
}
