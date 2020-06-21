#include <iostream>

#include "Game.h"
//#include "Sdl/Factories/SDLFactory.h"
#include "SFML/Factories/SFMLFactory.h"

using namespace SpaceInvaders;
using namespace SpaceInvaders::Factories;
using namespace SFML::Factories;

int main(int argc, char* argv[])
{
    // Create SDl Factory
    GameFactory* fact = new SFMLFactory();
    Game game = Game(fact);
    // Start the game
    game.run();
    
    return 0;
}
