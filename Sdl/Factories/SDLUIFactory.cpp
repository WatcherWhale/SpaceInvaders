#include "SDLUIFactory.h"

SpaceInvaders::UI::Text* SDLUIFactory::createText(std::string text, void* font, Color color, int x, int y)
{
    return new SpaceInvaders::UI::SDLText(text, font, color, x, y);
}

SpaceInvaders::UI::Text* SDLUIFactory::createText(std::string text, void* font, Color color, int x, int y, int w, int h)
{
    return new SpaceInvaders::UI::SDLText(text, font, color, x, y, w, h);
}