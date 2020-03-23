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

SpaceInvaders::UI::Text* SDLFactory::createText(std::string text, void* font, Color color, int x, int y)
{
    return new SpaceInvaders::UI::SDLText(text, font, color, x, y);
}

SpaceInvaders::UI::Text* SDLFactory::createText(std::string text, void* font, Color color, int x, int y, int w, int h)
{
    return new SpaceInvaders::UI::SDLText(text, font, color, x, y, w, h);
}
