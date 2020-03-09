#include <cmath>
#include <iostream>
#include "SDLFontLoader.h"

SpaceInvaders::Assets::SDLFontLoader::~SDLFontLoader()
{
    for(auto font : this->fonts)
    {
        TTF_CloseFont(reinterpret_cast<TTF_Font*>(font.second));
    }

    this->fonts.clear();
}

void SpaceInvaders::Assets::SDLFontLoader::loadFont(std::string fontName, std::string path)
{
    TTF_Font* font = TTF_OpenFont(path.c_str(), 16);
    this->fonts[fontName] = reinterpret_cast<void*>(font);
}

void SpaceInvaders::Assets::SDLFontLoader::unload()
{
    for(auto font : this->fonts)
    {
        TTF_CloseFont(reinterpret_cast<TTF_Font*>(font.second));
    }

    this->fonts.clear();
}
