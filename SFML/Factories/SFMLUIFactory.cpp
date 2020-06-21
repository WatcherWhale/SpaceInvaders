#include "SFMLUIFactory.h"

using namespace SFML::Factories;

SpaceInvaders::UI::Text* SFMLUIFactory::createText(std::string text, void* font, Color color, int x, int y)
{
    return new SFML::UI::SFMLText(text, font, color, x, y);
}

SpaceInvaders::UI::Text* SFMLUIFactory::createText(std::string text, void* font, Color color, int x, int y, int w, int h)
{
    return new SFML::UI::SFMLText(text, font, color, x, y, w, h);
}