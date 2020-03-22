#include "Sprite.h"
using namespace SpaceInvaders::Assets::Sprites;

Sprite::Sprite(std::string path, bool optimize)
{
    this->path = path;
    this->optimized = optimize;
}

bool Sprite::isOptimized()
{
    return this->optimized;
}

int Sprite::getWidth()
{
    return this->width;
}

int Sprite::getHeight()
{
    return this->height;
}
