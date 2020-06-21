#include "SFMLFactory.h"
#include "SFMLUIFactory.h"
#include "../Utils/SFMLTimer.h"
#include "../AssetLoaders/Audio/SFMLAudioLoader.h"

using namespace SFML::Windows;
using namespace SFML::Factories;

Window* SFMLFactory::createWindow(void* game, std::string title, int width, int height, bool isMaximized)
{
    return new SFMLWindow(game, title, width, height, isMaximized);
}

SpaceInvaders::Assets::Sprites::SpriteLoader* SFMLFactory::createSpriteLoader()
{
    return new SFML::Assets::Sprites::SFMLSpriteLoader();
}

SpaceInvaders::Assets::FontLoader* SFMLFactory::createFontLoader()
{
    return new SFML::Assets::SFMLFontLoader();
}

SFMLFactory::SFMLFactory()
{
    this->uiFactory = new SFMLUIFactory();
}

SpaceInvaders::Utils::Timer* SFMLFactory::createTimer()
{
    return new SFML::Utils::SFMLTimer();
}

SpaceInvaders::Assets::Audio::AudioLoader* SFMLFactory::createAudioLoader()
{
    return new SFML::Assets::Audio::SFMLAudioLoader();
}
