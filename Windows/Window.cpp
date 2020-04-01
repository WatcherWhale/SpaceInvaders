#include "Window.h"

using namespace SpaceInvaders::Windows;

Window::Window(void* game, std::string title, int width, int height, bool isMaximized)
{
    this->title = title;
    this->game = game;

    this->width = width;
    this->height = height;

    this->isMaximized = isMaximized;
}

void Window::queueSprite(Assets::Sprites::Sprite* sprite, int* position, double* bounds)
{
    auto* container = new SpriteContainer();
    container->sprite = sprite;
    container->position = position;
    container->bounds = bounds;

    this->spriteQueue.push(container);
}

void Window::queueUI(UI::UIComponent* component)
{
    this->uiQueue.push(component);
}

void Window::setClearColor(Color col)
{
    this->clearColor = col;
}

void Window::setClearColor(uint8_t r, uint8_t g, uint8_t b)
{
    this->clearColor.setR(r);
    this->clearColor.setG(g);
    this->clearColor.setB(b);
}

Color Window::getClearColor()
{
    return this->clearColor;
}

void Window::setBackground(SpaceInvaders::Assets::Sprites::Sprite* sprite)
{
    this->background = sprite;
}

void Window::setIcon(SpaceInvaders::Assets::Sprites::Sprite* sprite)
{
    this->icon = sprite;
}

void Window::setBackgroundMusic(std::string path)
{
    this->backgroundMusicPath = path;
}