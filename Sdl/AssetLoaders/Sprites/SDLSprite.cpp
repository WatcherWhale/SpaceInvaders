#include "SDLSprite.h"

#include <iostream>

using namespace SpaceInvaders::Assets::Sprites;

SDLSprite::~SDLSprite()
{
    SDL_FreeSurface(this->surface);
    SDL_DestroyTexture(this->texture);
}

void SDLSprite::load()
{
    this->isTexture = false;
    this->surface = IMG_Load(this->path.c_str());

    this->width = this->surface->w;
    this->height = this->surface->h;
}

void SDLSprite::texturize(SDL_Renderer* renderer)
{
    this->texture = SDL_CreateTextureFromSurface(renderer, this->surface);
    SDL_FreeSurface(this->surface);
    this->surface = nullptr;

    this->isTexture = true;
}

void SDLSprite::unload()
{
    if(this->surface != nullptr) SDL_FreeSurface(this->surface);
    if(this->texture != nullptr) SDL_DestroyTexture( this->texture );
}

void* SDLSprite::display()
{
    if(this->isTexture)
    {
        return reinterpret_cast<void*>(this->texture);
    }
    else
    {
        return reinterpret_cast<void*>(this->surface);
    }
}

bool SDLSprite::hasTexture()
{
    return this->isTexture;
}

int SDLSprite::getWidth()
{
    return this->width;
}

int SDLSprite::getHeight()
{
    return this->height;
}
