#include "SDLFactory.h"
#include "SDLUIFactory.h"
#include "../Utils/SDLTimer.h"

using namespace SpaceInvaders::Windows;

Window* SDLFactory::createWindow(void* game, std::string title, int width, int height)
{
    return new SDLWindow(game, title, width, height);
}

SpaceInvaders::Assets::Sprites::SpriteLoader* SDLFactory::createSpriteLoader()
{
    return new Assets::Sprites::SDLSpriteLoader();
}

SpaceInvaders::Assets::FontLoader* SDLFactory::createFontLoader()
{
    return new Assets::SDLFontLoader();
}


SDLFactory::SDLFactory()
{
    this->uiFactory = new SDLUIFactory();
}

SpaceInvaders::Utils::Timer* SDLFactory::createTimer()
{
    return new Utils::SDLTimer();
}
