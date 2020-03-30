#include "Button.h"
#include "../GameConstants.h"
#include "../Controllers/GameController.h"

SpaceInvaders::UI::Button::Button(int x, int y, double w, double h) : UIComponent(x, y, w, h)
{
    this->position[0] = x * SCALE_X;
    this->position[1] = y * SCALE_Y;

    this->size[0] = w * SCALE_X;
    this->size[1] = h * SCALE_Y;
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

void SpaceInvaders::UI::Button::click(int x, int y)
{
    if(this->position[0] >= x && x <= this->position[0] + this->size[0] &&
       this->position[0] >= x && x <= this->position[0] + this->size[0] )
    {
        for(auto listener : this->clickListeners)
        {
            listener.func(listener.listener);
        }
    }
}

void* SpaceInvaders::UI::Button::display()
{
    if(!this->displayText)
    {
        return this->sprite->display();
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
    this->txt = Controllers::GameController::getInstance().getFactory()->createText(text, font, color, 0, 0);
}

SpaceInvaders::UI::Text* SpaceInvaders::UI::Button::getText()
{
    return this->txt;
}

void SpaceInvaders::UI::Button::setSprite(SpaceInvaders::Assets::Sprites::Sprite* sprite)
{
    this->sprite = sprite;
}