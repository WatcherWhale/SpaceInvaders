#ifndef SPACEINVADERS_SFMLWINDOW_H
#define SPACEINVADERS_SFMLWINDOW_H

#include "../../Windows/Window.h"

#include <SFML/Graphics.hpp>

#include "../../Game.h"
#include "../../GameConstants.h"

using namespace SpaceInvaders::Windows;

namespace SFML::Windows
{
    class SFMLWindow : public Window
    {
    public:
        SFMLWindow(void* game, std::string title, int width, int height, bool isMaximized) :
                Window(game, title, width, height, isMaximized){};

        bool create() override;
        void destroy() override {};
        void pollEvents() override;
        void draw() override;
        void clear() override;

        void setIcon(SpaceInvaders::Assets::Sprites::Sprite* sprite) override;

    private:
        sf::RenderWindow* window;
        void HandleKeyEvent(bool down, sf::Keyboard::Key keycode);
    };
}
#endif
