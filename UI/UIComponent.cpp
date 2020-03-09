#include "UIComponent.h"

void SpaceInvaders::UI::UIComponent::setPosition(int x, int y)
{
    this->position[0] = x;
    this->position[1] = y;
}

void SpaceInvaders::UI::UIComponent::setSize(int w, int h)
{
    this->size[0] = w;
    this->size[1] = h;
}

int* SpaceInvaders::UI::UIComponent::getPosition()
{
    return this->position;
}

int* SpaceInvaders::UI::UIComponent::getSize()
{
    return this->size;
}
