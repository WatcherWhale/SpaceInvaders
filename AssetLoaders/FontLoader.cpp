#include "FontLoader.h"

SpaceInvaders::Assets::FontLoader::~FontLoader()
{
    this->fonts.clear();
}

void* SpaceInvaders::Assets::FontLoader::getFont(std::string fontName)
{
    return this->fonts.at(fontName);
}

