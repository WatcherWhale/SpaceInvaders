#ifndef SPACEINVADERS_SFMLTEXT_H
#define SPACEINVADERS_SFMLTEXT_H

#include "../../UI/Text.h"
#include <SFML/Graphics.hpp>

namespace SFML::UI
{
    class SFMLText : public SpaceInvaders::UI::Text
    {
    public:
        SFMLText(std::string text, void* font, Color textColor, int x, int y);
        SFMLText(std::string text, void* font, Color textColor, int x, int y, double w, double h);

        SpaceInvaders::UI::UISpriteContainer display() override;

    private:
        sf::RenderTexture* renderTexture;
        sf::Sprite* sprite;
        void generateTexture() override;
    };
}
#endif
