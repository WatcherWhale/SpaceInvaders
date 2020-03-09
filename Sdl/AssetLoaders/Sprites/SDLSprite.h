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
        SDLSprite(std::string path) : Sprite(path) {};
        virtual ~SDLSprite();
        void load() override;
        void* display() override;

        void texturize(SDL_Renderer* renderer);
        bool hasTexture();

        int getWidth() override;
        int getHeight() override;

    private:
        bool isTexture = false;
        SDL_Surface* surface = nullptr;
        SDL_Texture* texture = nullptr;
    };
}
#endif //GAME_SDLSPRITE_H
