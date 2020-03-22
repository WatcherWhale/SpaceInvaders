#include "SDLSprite.h"
#include "../../../Controllers/GameController.h"
#include "../../Window/SDLWindow.h"

using namespace SpaceInvaders::Assets::Sprites;

SDLSprite::~SDLSprite()
{
    if(this->surface != nullptr) SDL_FreeSurface(this->surface);
    if(this->texture != nullptr) SDL_DestroyTexture( this->texture );
}

void SDLSprite::load()
{
    this->surface = IMG_Load(this->path.c_str());

    if(this->optimized)
    {
        auto* win = Controllers::GameController::getInstance().getWindow();
        auto* sdlWin = dynamic_cast<Windows::SDLWindow*>(win);

        this->texture = SDL_CreateTextureFromSurface(sdlWin->getRenderer(), surface);
        SDL_QueryTexture(this->texture, nullptr, nullptr, &this->width, &this->height);

        SDL_FreeSurface(this->surface);
        this->surface = nullptr;
    }
    else
    {
        this->width = this->surface->w;
        this->height = this->surface->h;
    }
}

void* SDLSprite::display()
{
    if(this->optimized)
    {
        return this->texture;
    }
    else
    {
        return this->surface;
    }
}