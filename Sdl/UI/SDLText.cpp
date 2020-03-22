#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_ttf.h>
#include "SDLText.h"
#include "../../Controllers/GameController.h"
#include "../Window/SDLWindow.h"

using namespace SpaceInvaders::UI;

SDLText::SDLText(std::string text, void* font, Color textColor, int x, int y) : Text(text, font, textColor, x, y)
{
    // Create surface
    SDL_Color col = {textColor.getR(), textColor.getG(), textColor.getB()};
    auto* surface = TTF_RenderText_Solid(reinterpret_cast<TTF_Font*>(font), text.c_str(), col);

    // Get the window
    auto* win = Controllers::GameController::getInstance().getWindow();
    auto* sdlWin = dynamic_cast<Windows::SDLWindow*>(win);

    // Optimize the surface
    this->texture = SDL_CreateTextureFromSurface(sdlWin->getRenderer(), surface);
    SDL_QueryTexture(this->texture, nullptr, nullptr, this->size, this->size + 1);

    // Free the surface
    SDL_FreeSurface(surface);
}

SDLText::~SDLText()
{
    SDL_DestroyTexture(this->texture);
}

void* SDLText::display()
{
    return this->texture;
}
