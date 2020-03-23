#include "Text.h"

using namespace SpaceInvaders::UI;

Text::Text(std::string text, void* font, Color textColor, int x, int y) : UIComponent(x, y)
{
    this->text = text;
    this->font = font;
    this->color = new Color(textColor.getR(), textColor.getG(), textColor.getB());
}

Text::Text(std::string text, void* font, Color textColor, int x, int y, double w, double h) : UIComponent(x, y, w, h)
{
    this->text = text;
    this->font = font;
    this->color = new Color(textColor.getR(), textColor.getG(), textColor.getB());
}