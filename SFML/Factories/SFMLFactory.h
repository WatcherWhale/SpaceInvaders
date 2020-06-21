#ifndef SPACEINVADERS_SFMLFACTORY_H
#define SPACEINVADERS_SFMLFACTORY_H

#include "../../Factories/Factory.h"

#include "../Window/SFMLWindow.h"
#include "../AssetLoaders/SFMLFontLoader.h"
#include "../AssetLoaders/Sprites/SFMLSpriteLoader.h"
#include "../UI/SFMLText.h"

using namespace SpaceInvaders::Factories;

namespace SFML::Factories
{
    class SFMLFactory : public GameFactory
    {
    public:
        SFMLFactory();

        SpaceInvaders::Windows::Window* createWindow(void* game, std::string title, int width, int height, bool isMaximized) override;
        SpaceInvaders::Assets::Sprites::SpriteLoader* createSpriteLoader() override;
        SpaceInvaders::Assets::FontLoader* createFontLoader() override;
        SpaceInvaders::Utils::Timer* createTimer() override;
        SpaceInvaders::Assets::Audio::AudioLoader* createAudioLoader() override;
    };
}

#endif
