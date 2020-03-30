#ifndef SPACEINVADERS_UIFACTORY_H
#define SPACEINVADERS_UIFACTORY_H

#include <string>

#include "../UI/Text.h"
#include "../UI/Button.h"

namespace SpaceInvaders::Factories
    {
    class UIFactory
    {
    public:
        virtual UI::Text* createText(std::string text, void* font, Color color, int x, int y) = 0;
        virtual UI::Text* createText(std::string text, void* font, Color color, int x, int y, int w, int h) = 0;

        UI::Button* createButton(int x, int y, double w, double h);

    };
}
#endif
