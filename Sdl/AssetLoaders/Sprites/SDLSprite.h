#ifndef GAME_SDLSPRITE_H
#define GAME_SDLSPRITE_H

#include <SDL2/SDL_image.h>
#include <string>
#include "../../../AssetLoaders/Sprites/Sprite.h"

namespace SpaceInvaders::Assets::Sprites
{
    class SDLSprite : public Sprite
    {
    public:
        SDLSprite(std::string path, bool optimize) : Sprite(path, optimize) {};
        virtual ~SDLSprite();
        void load() override;
        void* display() override;

    private:
        SDL_Surface* surface = nullptr;
        SDL_Texture* texture = nullptr;
    };
}
#endif //GAME_SDLSPRITE_H
