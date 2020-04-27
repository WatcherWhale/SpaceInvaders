#include <iostream>
#include "Button.h"
#include "../GameConstants.h"
#include "../Controllers/GameController.h"

SpaceInvaders::UI::Button::Button(int x, int y, double w, double h) : UIComponent(x, y, w, h)
{
    this->position[0] = x * GameConstants::SCALE_X;
    this->position[1] = y * GameConstants::SCALE_Y;

    this->size[0] = w * GameConstants::SCALE_X;
    this->size[1] = h * GameConstants::SCALE_Y;
}

SpaceInvaders::UI::Button::~Button()
{
    if(this->txt != nullptr) delete this->txt;
}

void SpaceInvaders::UI::Button::addClickListener(void* listener, CallbackFunction action)
{
    CallbackObject cb;
    cb.func = action;
    cb.listener = listener;

    this->clickListeners.push_back(cb);
}

void SpaceInvaders::UI::Button::mouseDown(int x, int y)
{
    if(this->position[0] <= x && x <= this->position[0] + this->size[0] &&
       this->position[1] <= y && y <= this->position[1] + this->size[1] )
    {
        for(auto listener : this->clickListeners)
        {
            listener.func(listener.listener);
        }
    }
}

SpaceInvaders::UI::UISpriteContainer SpaceInvaders::UI::Button::display()
{
    if(!this->displayText)
    {
        UISpriteContainer container;
        container.texture = this->sprite->display();
        container.size = this->size;
        container.position = this->position;
        return container;
    }
    else
        return this->txt->display();
}

bool SpaceInvaders::UI::Button::doneDisplaying()
{
    this->displayText = !this->displayText;
    return !this->displayText;
}

void SpaceInvaders::UI::Button::setText(std::string text, void* font, Color color)
{
    if(this->txt != nullptr) delete this->txt;
    this->txt = Controllers::GameController::getInstance().getFactory()->getUiFactory()
            ->createText(text, font, color, 0, 0);
}

void SpaceInvaders::UI::Button::setText(SpaceInvaders::UI::Text* text)
{
    this->txt = text;
}


SpaceInvaders::UI::Text* SpaceInvaders::UI::Button::getText()
{
    return this->txt;
}

void SpaceInvaders::UI::Button::setSprite(SpaceInvaders::Assets::Sprites::Sprite* sprite)
{
    this->sprite = sprite;
}