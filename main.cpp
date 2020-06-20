#include <iostream>

#include "Game.h"
#include "Sdl/Factories/SDLFactory.h"

using namespace SpaceInvaders;
using namespace SpaceInvaders::Factories;
using namespace SDL::Factories;

int main(int argc, char* argv[])
{
    // Create SDl Factory
    GameFactory* fact = new SDLFactory();
    Game game = Game(fact);
    // Start the game
    game.run();
    
    return 0;
}
