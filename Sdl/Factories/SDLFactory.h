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
        Windows::Window* createWindow(void* game, std::string title, int width, int height) override;
        Assets::Sprites::SpriteLoader* createSpriteLoader() override;
        Assets::FontLoader* createFontLoader() override;
        UI::Text* createText(std::string text, void* font, Color color, int x, int y) override;
    };
}
#endif // !SDLFACTORY_H
