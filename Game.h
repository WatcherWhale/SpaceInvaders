#ifndef GAME_H
#define GAME_H

#include "Windows/Window.h"
#include "Factories/Factory.h"
#include "Events/EventHandler.h"
#include "GameObjects/GameObject.h"
#include "Controllers/LevelController.h"

#include <vector>

using namespace SpaceInvaders::Factories;
using namespace SpaceInvaders::Events;

namespace SpaceInvaders
{
	class Game
	{
	public:
		Game(GameFactory* factory);
        void run();
        void stop();

        EventHandler* getEventHandler();

	private:
		void createObjects();

		GameFactory* factory;
		Windows::Window* window;
		EventHandler eventHandler;
		Controllers::LevelController controller;
		Assets::Sprites::SpriteLoader* spriteLoader;
		Assets::FontLoader* fontLoader;

		bool isRunning = false;
		std::vector<GameObjects::GameObject*> gameObjects;
	};
}

#endif // !GAME_H
