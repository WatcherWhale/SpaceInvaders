#include "UIComponent.h"
#include "../GameConstants.h"

SpaceInvaders::UI::UIComponent::UIComponent(int x, int y)
{
    this->position[0] = x;
    this->position[1] = y;

    this->size[0] = 1;
    this->size[1] = 1;
}

SpaceInvaders::UI::UIComponent::UIComponent(int x, int y, double w, double h)
{
    this->position[0] = x;
    this->position[1] = y;

    this->size[0] = w * SCALE_X;
    this->size[1] = h * SCALE_Y;
}

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

double* SpaceInvaders::UI::UIComponent::getSize()
{
    return this->size;
}

void SpaceInvaders::UI::UIComponent::scale(double f)
{
    this->size[0] *= f;
    this->size[1] *= f;
}

void SpaceInvaders::UI::UIComponent::scale(double x, double y)
{
    this->size[0] *= x;
    this->size[1] *= y;
}
