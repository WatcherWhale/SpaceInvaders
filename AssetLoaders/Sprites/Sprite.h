#ifndef GAME_SPRITE_H
#define GAME_SPRITE_H

#include <string>

namespace SpaceInvaders::Assets::Sprites
{
    class Sprite
    {
    public:
        Sprite(std::string path);
        virtual void load() = 0;
        virtual void* display() = 0;

        virtual int getWidth() = 0;
        virtual int getHeight() = 0;

    protected:
        std::string path;
        int width, height;
    };
}

#endif //GAME_SPRITE_H
