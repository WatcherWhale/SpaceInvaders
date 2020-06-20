#ifndef GAME_SDLTEXT_H
#define GAME_SDLTEXT_H

#include <SDL2/SDL.h>
#include "../../UI/Text.h"

namespace SDL::UI
{
class SDLText : public SpaceInvaders::UI::Text
    {
    public:
        SDLText(std::string text, void* font, Color textColor, int x, int y);
        SDLText(std::string text, void* font, Color textColor, int x, int y, double w, double h);
        ~SDLText() override;

    SpaceInvaders::UI::UISpriteContainer display() override;

    private:
        SDL_Texture* texture;

        void generateTexture() override;
    };
}
#endif //GAME_SDLTEXT_H
