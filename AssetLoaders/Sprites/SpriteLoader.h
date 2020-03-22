#ifndef GAME_SPRITELOADER_H
#define GAME_SPRITELOADER_H

#include "Sprite.h"
#include <string>
#include <map>

namespace SpaceInvaders::Assets::Sprites
{
    class SpriteLoader
    {
    public:
        virtual Sprite* loadSprite(std::string path, bool opimize);
        std::map<std::string, Sprite*>* getSpriteMap();


    protected:
        std::map<std::string, Sprite*> sprites;
    };
}



#endif //GAME_SPRITELOADER_H
