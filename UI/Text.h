#ifndef GAME_TEXT_H
#define GAME_TEXT_H

#include <string>
#include "../Color.h"
#include "UIComponent.h"

namespace SpaceInvaders::UI
{
    class Text: public UIComponent
    {
    public:
        Text(std::string text, void* font, Color color, int x, int y);
        Text(std::string text, void* font, Color color, int x, int y, double w, double h);
        void setText(std::string text);

    protected:
        virtual void generateTexture() = 0;

        double textSize[2];
        std::string text;
        void* font;
        Color* color;
    };
}

#endif //GAME_TEXT_H
