#include <SFML/Graphics/Font.hpp>
#include "SFMLFontLoader.h"

SFML::Assets::SFMLFontLoader::~SFMLFontLoader()
{
    for(auto font : this->fonts)
    {
        delete font.second;
    }

    this->fonts.clear();
}

void SFML::Assets::SFMLFontLoader::loadFont(std::string fontName, std::string path)
{
    sf::Font* font = new sf::Font();
    font->loadFromFile(path);

    this->fonts[fontName] = font;
}

void SFML::Assets::SFMLFontLoader::unload()
{
    for(auto font : this->fonts)
    {
        delete font.second;
    }

    this->fonts.clear();
}
