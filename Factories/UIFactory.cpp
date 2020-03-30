#include "UIFactory.h"

SpaceInvaders::UI::Button* SpaceInvaders::Factories::UIFactory::createButton(int x, int y, double w, double h)
{
    return new UI::Button(x, y, w, h);
}
