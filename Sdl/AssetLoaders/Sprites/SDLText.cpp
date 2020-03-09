#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_ttf.h>
#include "SDLText.h"

using namespace SpaceInvaders::Assets::Sprites;

SDLText::SDLText(std::string text, void* font, Color textColor, int x, int y) : Text(text, font, textColor, x, y)
{
    SDL_Color col = {textColor.getR(), textColor.getG(), textColor.getB()};
    this->surface = TTF_RenderText_Solid(reinterpret_cast<TTF_Font*>(font), text.c_str(), col);

    this->size[0] = this->surface->w;
    this->size[1] = this->surface->h;
}

void* SDLText::getTextTexture()
{
    return this->surface;
}

void SDLText::unload()
{
    SDL_FreeSurface(this->surface);
}
