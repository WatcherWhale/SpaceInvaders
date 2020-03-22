#ifndef GAME_SDLTEXT_H
#define GAME_SDLTEXT_H

#include <SDL2/SDL.h>
#include "../../UI/Text.h"

namespace SpaceInvaders::UI
{
    class SDLText : public Text
    {
    public:
        SDLText(std::string text, void* font, Color textColor, int x, int y);
        virtual ~SDLText();

        void* display() override;

    private:
        SDL_Texture* texture;
    };
}
#endif //GAME_SDLTEXT_H
