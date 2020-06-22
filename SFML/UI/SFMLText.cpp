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
    auto txt = sf::Text(this->text, *reinterpret_cast<sf::Font*>(this->font), 32);
    txt.setFillColor(sf::Color(color->getR(), color->getG(), color->getB()));

    this->renderTexture = new sf::RenderTexture();
    this->renderTexture->create(txt.getGlobalBounds().width, txt.getGlobalBounds().height);
    this->renderTexture->clear(sf::Color::Transparent);
    this->renderTexture->draw(txt);
    this->renderTexture->display();

    this->sprite = new sf::Sprite(this->renderTexture->getTexture());

    this->size[0] = this->sprite->getLocalBounds().width * GameConstants::SCALE_X;
    this->size[1] = this->sprite->getLocalBounds().height * GameConstants::SCALE_Y;
}

UISpriteContainer SFMLText::display()
{
    UISpriteContainer container;
    container.texture = this->sprite;
    container.position = this->position;
    container.size = this->size;
    return container;
}
