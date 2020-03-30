#ifndef SDLFACTORY_H
#define SDLFACTORY_H

#include "../../Factories/Factory.h"

#include "../Window/SDLWindow.h"
#include "../AssetLoaders/SDLFontLoader.h"
#include "../AssetLoaders/Sprites/SDLSpriteLoader.h"
#include "../UI/SDLText.h"

using namespace SpaceInvaders::Factories;

namespace SpaceInvaders::Factories
{
    class SDLFactory : public GameFactory
    {
    public:
        SDLFactory();

        Windows::Window* createWindow(void* game, std::string title, int width, int height) override;
        Assets::Sprites::SpriteLoader* createSpriteLoader() override;
        Assets::FontLoader* createFontLoader() override;
    };
}
#endif // !SDLFACTORY_H
