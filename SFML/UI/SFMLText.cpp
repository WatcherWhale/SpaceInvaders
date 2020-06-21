#include "SFMLText.h"

#include "../../Controllers/GameController.h"

using namespace SpaceInvaders;
using namespace SpaceInvaders::UI;
using namespace SFML::UI;

SFMLText::SFMLText(std::string text, void* font, Color textColor, int x, int y) : Text(text, font, textColor, x, y)
{
    this->generateTexture();
    this->size[0] = this->textSize[0];
    this->size[1] = this->textSize[1];
}

SFMLText::SFMLText(std::string text, void* font, Color textColor,
                 int x, int y, double w, double h) : Text(text, font, textColor, x, y, w, h)
{
    this->generateTexture();
}

void SFMLText::generateTexture()
{
    this->txt = new sf::Text(this->text, *reinterpret_cast<sf::Font*>(this->font), 32);
    this->txt->setFillColor(sf::Color(color->getR(), color->getG(), color->getB()));
    this->txt->setScale(this->txt->getScale().x * GameConstants::SCALE_X, this->txt->getScale().y * GameConstants::SCALE_Y);

    this->size[0] = this->txt->getLocalBounds().width;
    this->size[1] = this->txt->getLocalBounds().height;
}

UISpriteContainer SFMLText::display()
{
    UISpriteContainer container;
    container.texture = this->txt;
    container.position = this->position;
    container.size = this->size;
    return container;
}
