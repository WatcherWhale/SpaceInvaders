#include "SDLSpriteLoader.h"
#include "SDLSprite.h"

using namespace SpaceInvaders::Assets::Sprites;

SDLSpriteLoader::~SDLSpriteLoader()
{
    for(auto sprite : this->sprites)
    {
        delete sprite.second;
    }
}


Sprite* SDLSpriteLoader::loadSprite(std::string path)
{
    auto* loadedSprite = SpriteLoader::loadSprite(path);
    
    if(loadedSprite != nullptr)
    {
        return loadedSprite;
    }

    Sprite* sprite = new SDLSprite(path);
    sprite->load();

    this->sprites[path] = sprite;

    return sprite;
}
