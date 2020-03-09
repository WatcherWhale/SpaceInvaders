#ifndef GAME_SDLTEXT_H
#define GAME_SDLTEXT_H

#include <SDL2/SDL.h>
#include "../../../UI/Text.h"

namespace SpaceInvaders::Assets::Sprites
{
    class SDLText : public Text
    {
    public:
        SDLText(std::string text, void* font, Color textColor, int x, int y);

        void* getTextTexture() override;

        void unload() override;

    private:
        SDL_Surface* surface;
    };
}
#endif //GAME_SDLTEXT_H
