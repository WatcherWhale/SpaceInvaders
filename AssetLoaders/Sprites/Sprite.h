#ifndef GAME_SPRITE_H
#define GAME_SPRITE_H

#include <string>

namespace SpaceInvaders::Assets::Sprites
{
    class Sprite
    {
    public:
        Sprite(std::string path, bool optimize);
        virtual void load() = 0;
        virtual void* display() = 0;

        int getWidth();
        int getHeight();

        bool isOptimized();

    protected:
        std::string path;
        int width, height;
        bool optimized = false;
    };
}

#endif //GAME_SPRITE_H
