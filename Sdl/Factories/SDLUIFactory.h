#ifndef SPACEINVADERS_SDLUIFACTORY_H
#define SPACEINVADERS_SDLUIFACTORY_H

#include "../../Factories/UIFactory.h"
#include "../UI/SDLText.h"

using namespace SpaceInvaders::Factories;

namespace SDL::Factories
{
    class SDLUIFactory : public UIFactory
    {
    public:
        SpaceInvaders::UI::Text* createText(std::string text, void* font, Color color, int x, int y) override;
        SpaceInvaders::UI::Text* createText(std::string text, void* font, Color color, int x, int y, int w, int h) override;
    };
}
#endif
