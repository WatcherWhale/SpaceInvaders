#ifndef SPACEINVADERS_SFMLSPRITELOADER_H
#define SPACEINVADERS_SFMLSPRITELOADER_H

#include "../../../AssetLoaders/Sprites/SpriteLoader.h"

namespace SFML::Assets::Sprites
{
    class SFMLSpriteLoader : public SpaceInvaders::Assets::Sprites::SpriteLoader
    {
        public:
            ~SFMLSpriteLoader();
            SpaceInvaders::Assets::Sprites::Sprite* loadSprite(std::string path, bool optimize) override;
    };
}

#endif
