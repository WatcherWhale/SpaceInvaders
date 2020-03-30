#ifndef SPACEINVADERS_BUTTON_H
#define SPACEINVADERS_BUTTON_H

#include <vector>
#include <string>
#include "UIComponent.h"
#include "../Utils/FunctionDefinitions.h"
#include "../AssetLoaders/Sprites/Sprite.h"
#include "../Color.h"
#include "Text.h"

namespace SpaceInvaders::UI
{

    class Button : public UIComponent
    {
    public:
        Button(int x, int y, double w, double h);
        ~Button() override;

        void setText(std::string text, void* font, Color color);
        Text* getText();

        void* display() override;
        bool doneDisplaying() override;

        void setSprite(Assets::Sprites::Sprite* sprite);

        void click(int x, int y);
        void addClickListener(void* listener, CallbackFunction action);

    private:
        std::vector<CallbackObject> clickListeners;
        Assets::Sprites::Sprite* sprite;
        Text* txt = nullptr;
        bool displayText = false;
    };
}
#endif