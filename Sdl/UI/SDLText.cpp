#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_ttf.h>
#include "SDLText.h"
#include "../../Controllers/GameController.h"
#include "../Window/SDLWindow.h"

using namespace SpaceInvaders::UI;

SDLText::SDLText(std::string text, void* font, Color textColor, int x, int y) : Text(text, font, textColor, x, y)
{
    this->generateTexture();
    this->size[0] = this->textSize[0];
    this->size[1] = this->textSize[1];
}

SDLText::SDLText(std::string text, void* font, Color textColor,
        int x, int y, double w, double h) : Text(text, font, textColor, x, y, w, h)
{
   this->generateTexture();
}

void SDLText::generateTexture()
{
    SDL_Color col = {this->color->getR(), this->color->getG(), this->color->getB()};
    auto* surface = TTF_RenderUTF8_Solid(reinterpret_cast<TTF_Font*>(font), text.c_str(), col);

    // Get the window
    auto* win = Controllers::GameController::getInstance().getWindow();
    auto* sdlWin = dynamic_cast<Windows::SDLWindow*>(win);

    // Optimize the surface
    this->texture = SDL_CreateTextureFromSurface(sdlWin->getRenderer(), surface);

    this->textSize[0] = surface->w * SCALE_X;
    this->textSize[1] = surface->h * SCALE_Y;

    // Free the surface
    SDL_FreeSurface(surface);
}

SDLText::~SDLText()
{
    SDL_DestroyTexture(this->texture);
}

UISpriteContainer SDLText::display()
{
    UISpriteContainer container;
    container.texture = this->texture;
    container.position = this->position;
    container.size = this->size;
    return container;
}
