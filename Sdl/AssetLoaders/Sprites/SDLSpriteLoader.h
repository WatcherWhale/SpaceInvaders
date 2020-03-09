#ifndef GAME_SDLSPRITELOADER_H
#define GAME_SDLSPRITELOADER_H

#include "../../../AssetLoaders/Sprites/SpriteLoader.h"

namespace SpaceInvaders::Assets::Sprites
{
class SDLSpriteLoader : public SpaceInvaders::Assets::Sprites::SpriteLoader
    {
    public:
        ~SDLSpriteLoader();
        Sprite* loadSprite(std::string path) override;
    };
}

#endif //GAME_SDLSPRITELOADER_H
