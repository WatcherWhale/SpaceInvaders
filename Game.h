#ifndef GAME_H
#define GAME_H

#include "Windows/Window.h"
#include "Factories/Factory.h"
#include "Events/EventHandler.h"
#include "GameObjects/GameObject.h"
#include "Controllers/LevelController.h"
#include "Controllers/GameController.h"

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

        Events::EventHandler* getEventHandler();

    private:

		GameFactory* factory;
		Windows::Window* window;
		bool isRunning = false;
    };
}

#endif // !GAME_H
