#include "Text.h"

using namespace SpaceInvaders::Assets::Sprites;

Text::Text(std::string text, void* font, Color textColor, int x, int y)
{
    this->text = text;
    this->font = font;
    this->color = new Color(textColor.getR(), textColor.getG(), textColor.getB());

    this->position[0] = x;
    this->position[1] = y;
}

int* Text::getPosition()
{
    return this->position;
}

void Text::setPosition(int x, int y)
{
    this->position[0] = x;
    this->position[1] = y;
}

int* Text::getSize()
{
    return this->size;
}
