#ifndef SPACEINVADERS_SFMLSPRITE_H
#define SPACEINVADERS_SFMLSPRITE_H

#include <string>
#include "../../../AssetLoaders/Sprites/Sprite.h"
#include <SFML/Graphics.hpp>

using namespace SpaceInvaders::Assets::Sprites;

namespace SFML::Assets::Sprites
{
    class SFMLSprite : public Sprite
    {
    public:
        SFMLSprite(std::string path, bool optimize) : Sprite(path, optimize) {};
        virtual ~SFMLSprite();
        void load() override;
        void* display() override;

    private:
        sf::Sprite* sprite;
        sf::Image* image;

    };
}

#endif
