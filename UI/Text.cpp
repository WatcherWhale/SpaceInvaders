#include "Text.h"

using namespace SpaceInvaders::UI;

Text::Text(std::string text, void* font, Color textColor, int x, int y)
{
    this->text = text;
    this->font = font;
    this->color = new Color(textColor.getR(), textColor.getG(), textColor.getB());

    this->position[0] = x;
    this->position[1] = y;
}