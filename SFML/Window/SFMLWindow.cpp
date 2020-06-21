#include "SFMLWindow.h"

using namespace SpaceInvaders::Controllers;

bool SFML::Windows::SFMLWindow::create()
{
    sf::Uint32 style = sf::Style::Titlebar | sf::Style::Close;
    sf::VideoMode mode = sf::VideoMode(this->width, this->height);

    if(this->isMaximized)
    {
        style = sf::Style::Fullscreen;
        mode = sf::VideoMode::getDesktopMode();
    }

    this->window = new sf::RenderWindow(mode, this->title, style);

    this->window->setFramerateLimit(1000/SpaceInvaders::GameConstants::FPS_TIME);
    this->clear();

    return true;
}

void SFML::Windows::SFMLWindow::setIcon(SpaceInvaders::Assets::Sprites::Sprite* sprite)
{
    Window::setIcon(sprite);
    this->window->setIcon(sprite->getWidth(), sprite->getHeight(), static_cast<const sf::Uint8*>(sprite->display()));
}

void SFML::Windows::SFMLWindow::pollEvents()
{
    sf::Event event;
    while(this->window->pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                GameController::getInstance().stopGame();
                break;

            case sf::Event::KeyPressed:
                this->HandleKeyEvent(true, event.key.code);
                break;

            case sf::Event::KeyReleased:
                this->HandleKeyEvent(false, event.key.code);
                break;

            case sf::Event::MouseMoved:
                GameController::getInstance().getEventHandler()->mouseMove(event.mouseMove.x, event.mouseMove.y);
                break;

            case sf::Event::MouseButtonPressed:
                GameController::getInstance().getEventHandler()->mouseUp(event.mouseButton.x, event.mouseButton.y);
                break;

            case sf::Event::MouseButtonReleased:
                GameController::getInstance().getEventHandler()->mouseUp(event.mouseButton.x, event.mouseButton.y);
                break;
        }
    }
}

void SFML::Windows::SFMLWindow::clear()
{
    this->window->clear();
}

void SFML::Windows::SFMLWindow::draw()
{
    this->clear();

    if(this->background != nullptr)
    {

    }

    while (!spriteQueue.empty())
    {
        auto* container = spriteQueue.front();

        spriteQueue.pop();
    }

    while(!this->uiQueue.empty())
    {
        auto* component = uiQueue.front();

        uiQueue.pop();
    }
}

void SFML::Windows::SFMLWindow::HandleKeyEvent(bool down, sf::Keyboard::Key keycode)
{
    Key key = Key::NONE;

    switch (keycode)
    {
        case sf::Keyboard::Up:
            key = Key::UP;
            break;

        case sf::Keyboard::Down:
            key = Key::DOWN;
            break;

        case sf::Keyboard::Left:
            key = Key::LEFT;
            break;

        case sf::Keyboard::Right:
            key = Key::RIGHT;
            break;

        case sf::Keyboard::Space:
            key = Key::SPACE;
            break;

        case sf::Keyboard::Escape:
            GameController::getInstance().stopGame();
            break;

        default:
            key = Key::NONE;
            break;
    }

    if(down)
    {
        GameController::getInstance().getEventHandler()->onKeyDown(key);
    }
    else
    {
        GameController::getInstance().getEventHandler()->onKeyUp(key);
    }
}
