#ifndef GAME_TEXT_H
#define GAME_TEXT_H

#include <string>
#include "../Color.h"

namespace SpaceInvaders::Assets::Sprites
{
    class Text
    {
    public:
        Text(std::string text, void* font, Color color, int x, int y);

        virtual void unload() = 0;

        virtual void* getTextTexture() = 0;

        int* getSize();

        int* getPosition();

        void setPosition(int x, int y);


    protected:
        std::string text;
        void* font;
        Color* color;
        int position[2];
        int size[2];
    };
}

#endif //GAME_TEXT_H
