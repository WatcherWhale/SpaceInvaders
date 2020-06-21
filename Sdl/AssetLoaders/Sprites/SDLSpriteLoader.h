#ifndef GAME_SDLSPRITELOADER_H
#define GAME_SDLSPRITELOADER_H

#include "../../../AssetLoaders/Sprites/SpriteLoader.h"

namespace SDL::Assets::Sprites
{
    class SDLSpriteLoader : public SpaceInvaders::Assets::Sprites::SpriteLoader
    {
    public:
        ~SDLSpriteLoader();
        SpaceInvaders::Assets::Sprites::Sprite* loadSprite(std::string path, bool optimize) override;
    };
}

#endif //GAME_SDLSPRITELOADER_H
