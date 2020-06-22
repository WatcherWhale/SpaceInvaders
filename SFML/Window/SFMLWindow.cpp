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
    this->window->clear(sf::Color(this->clearColor.getR(),this->clearColor.getG(),this->clearColor.getB()));
}

void SFML::Windows::SFMLWindow::draw()
{
    this->clear();

    if(this->background != nullptr)
    {
        auto* backgroundSprite = static_cast<sf::Sprite*>(this->background->display());
        backgroundSprite->setPosition(0,0);
        backgroundSprite->setScale(1920.f/this->background->getWidth(), 1080.f/this->background->getHeight());

        this->window->draw(*backgroundSprite);
    }

    while (!spriteQueue.empty())
    {
        auto* container = spriteQueue.front();
        auto* sprite = static_cast<sf::Sprite*>(container->sprite->display());

        double offsetX = container->bounds[2] * container->bounds[0] * container->sprite->getWidth();
        double offsetY = container->bounds[3] * container->bounds[1] * container->sprite->getHeight();

        sprite->setPosition(container->position[0] + offsetX, container->position[1] + offsetY);
        sprite->setScale(container->bounds[2], container->bounds[3]);

        this->window->draw(*sprite);

        spriteQueue.pop();
    }

    while(!this->uiQueue.empty())
    {
        auto* component = uiQueue.front();

        do
        {
            auto container = component->display();

            auto* sprite = static_cast<sf::Sprite*>(container.texture);
            sprite->setPosition(container.position[0], container.position[1]);
            sprite->setScale(container.size[0] / sprite->getLocalBounds().width,
                                container.size[1] / sprite->getLocalBounds().height);

            this->window->draw(*sprite);

        } while(!component->doneDisplaying());

        uiQueue.pop();
    }

    this->window->display();
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
