#ifndef SPACEINVADERS_SFMLUIFACTORY_H
#define SPACEINVADERS_SFMLUIFACTORY_H


#include "../../Factories/UIFactory.h"
#include "../UI/SFMLText.h"

using namespace SpaceInvaders::Factories;

namespace SFML::Factories
{
    class SFMLUIFactory : public UIFactory
    {
    public:
        SpaceInvaders::UI::Text* createText(std::string text, void* font, Color color, int x, int y) override;
        SpaceInvaders::UI::Text* createText(std::string text, void* font, Color color, int x, int y, int w, int h) override;
    };
}


#endif
