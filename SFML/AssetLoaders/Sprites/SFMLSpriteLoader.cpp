#include "SFMLSpriteLoader.h"
#include "SFMLSprite.h"

using namespace SpaceInvaders::Assets::Sprites;
using namespace SFML::Assets::Sprites;

SFMLSpriteLoader::~SFMLSpriteLoader()
{
    for(auto sprite : this->sprites)
    {
        delete sprite.second;
    }
}

Sprite* SFMLSpriteLoader::loadSprite(std::string path, bool optimize)
{
    auto* loadedSprite = SpriteLoader::loadSprite(path, optimize);

    if(loadedSprite != nullptr)
    {
        return loadedSprite;
    }

    Sprite* sprite = new SFMLSprite(path, optimize);
    sprite->load();

    this->sprites[path] = sprite;

    return sprite;
}

