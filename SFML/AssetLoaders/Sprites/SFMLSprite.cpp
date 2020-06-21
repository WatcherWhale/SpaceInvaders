#include "SFMLSprite.h"

using namespace SFML::Assets::Sprites;

SFMLSprite::~SFMLSprite()
{
    delete this->image;
    delete this->sprite;
}

void SFMLSprite::load()
{
    this->image = new sf::Image();
    this->image->loadFromFile(this->path);

    this->width = this->image->getSize().x;
    this->height = this->image->getSize().y;

    if(!this->optimized) return;

    this->texture = new sf::Texture();
    this->texture->loadFromImage(*this->image, sf::IntRect(0, 0, this->image->getSize().x, this->image->getSize().y));
    this->sprite = new sf::Sprite(*this->texture);
}

void* SFMLSprite::display()
{
    if(this->isOptimized())
    {
        return this->sprite;
    }
    else
    {
        return (void*) this->image->getPixelsPtr();
    }
}

