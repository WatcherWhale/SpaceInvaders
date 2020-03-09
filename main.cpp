#include <iostream>

#include "Game.h"
#include "Sdl/Factories/SDLFactory.h"

using namespace SpaceInvaders;
using namespace SpaceInvaders::Factories;

int main(int argc, char* argv[])
{
    GameFactory* fact = new SDLFactory();
    Game game = Game(fact);
    game.run();
    
    return 0;
}
