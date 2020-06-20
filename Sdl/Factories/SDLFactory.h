#ifndef SDLFACTORY_H
#define SDLFACTORY_H

#include "../../Factories/Factory.h"

#include "../Window/SDLWindow.h"
#include "../AssetLoaders/SDLFontLoader.h"
#include "../AssetLoaders/Sprites/SDLSpriteLoader.h"
#include "../UI/SDLText.h"

using namespace SpaceInvaders::Factories;

namespace SDL::Factories
{
    class SDLFactory : public GameFactory
    {
    public:
        SDLFactory();

        SpaceInvaders::Windows::Window* createWindow(void* game, std::string title, int width, int height, bool isMaximized) override;
        SpaceInvaders::Assets::Sprites::SpriteLoader* createSpriteLoader() override;
        SpaceInvaders::Assets::FontLoader* createFontLoader() override;
        SpaceInvaders::Utils::Timer* createTimer() override;
        SpaceInvaders::Assets::Audio::AudioLoader* createAudioLoader() override;
    };
}
#endif // !SDLFACTORY_H
