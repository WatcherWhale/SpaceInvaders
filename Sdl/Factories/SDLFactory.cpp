#include "SDLFactory.h"

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

SpaceInvaders::Assets::Sprites::Text* SDLFactory::createText(std::string text, void* font, Color color, int x, int y)
{
    return new SpaceInvaders::Assets::Sprites::SDLText(text, font, color, x, y);
}
