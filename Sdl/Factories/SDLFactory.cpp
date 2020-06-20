#include "SDLFactory.h"
#include "SDLUIFactory.h"
#include "../Utils/SDLTimer.h"
#include "../AssetLoaders/Audio/SDLAudioLoader.h"

using namespace SDL::Windows;
using namespace SDL::Factories;

Window* SDLFactory::createWindow(void* game, std::string title, int width, int height, bool isMaximized)
{
    return new SDLWindow(game, title, width, height, isMaximized);
}

SpaceInvaders::Assets::Sprites::SpriteLoader* SDLFactory::createSpriteLoader()
{
    return new SDL::Assets::Sprites::SDLSpriteLoader();
}

SpaceInvaders::Assets::FontLoader* SDLFactory::createFontLoader()
{
    return new SDL::Assets::SDLFontLoader();
}

SDLFactory::SDLFactory()
{
    this->uiFactory = new SDLUIFactory();
}

SpaceInvaders::Utils::Timer* SDLFactory::createTimer()
{
    return new SDL::Utils::SDLTimer();
}

SpaceInvaders::Assets::Audio::AudioLoader* SDLFactory::createAudioLoader()
{
    return new SDL::Assets::Audio::SDLAudioLoader();
}
