
#ifndef GAME_SPRITEMAP_H
#define GAME_SPRITEMAP_H

#include "Sprite.h"

namespace SpaceInvaders::Assets::Sprites
{
    class SpriteMap : Sprite
    {
    public:
        SpriteMap(std::string path, int x, int y, int w, int h);
    protected:
        int x, y, w, h;
    };
}


#endif
