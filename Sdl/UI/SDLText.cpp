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
    auto* surface = TTF_RenderUTF8_Solid(reinterpret_cast<TTF_Font*>(font), text.c_str(), col);

    int w,h;
    TTF_SizeUTF8(reinterpret_cast<TTF_Font*>(font), text.c_str(), &w, &h);

    // Get the window
    auto* win = Controllers::GameController::getInstance().getWindow();
    auto* sdlWin = dynamic_cast<Windows::SDLWindow*>(win);

    // Optimize the surface
    this->texture = SDL_CreateTextureFromSurface(sdlWin->getRenderer(), surface);

    this->size[0] = w * SCALE_X;
    this->size[1] = h * SCALE_Y;

    // Free the surface
    SDL_FreeSurface(surface);
}

SDLText::SDLText(std::string text, void* font, Color textColor,
        int x, int y, double w, double h) : Text(text, font, textColor, x, y, w, h)
{
    // Create surface
    SDL_Color col = {textColor.getR(), textColor.getG(), textColor.getB()};
    auto* surface = TTF_RenderUTF8_Solid(reinterpret_cast<TTF_Font*>(font), text.c_str(), col);

    int tW,tH;
    TTF_SizeUTF8(reinterpret_cast<TTF_Font*>(font), text.c_str(), &tW, &tH);

    // Get the window
    auto* win = Controllers::GameController::getInstance().getWindow();
    auto* sdlWin = dynamic_cast<Windows::SDLWindow*>(win);

    // Optimize the surface
    this->texture = SDL_CreateTextureFromSurface(sdlWin->getRenderer(), surface);

    this->size[0] = tW * this->size[0] * SCALE_X;
    this->size[1] = tH * this->size[1] * SCALE_Y;

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