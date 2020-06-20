#include "SDLSpriteLoader.h"
#include "SDLSprite.h"

using namespace SpaceInvaders::Assets::Sprites;
using namespace SDL::Assets::Sprites;

SDLSpriteLoader::~SDLSpriteLoader()
{
    for(auto sprite : this->sprites)
    {
        delete sprite.second;
    }
}


Sprite* SDLSpriteLoader::loadSprite(std::string path, bool optimize)
{
    auto* loadedSprite = SpriteLoader::loadSprite(path, optimize);
    
    if(loadedSprite != nullptr)
    {
        return loadedSprite;
    }

    Sprite* sprite = new SDLSprite(path, optimize);
    sprite->load();

    this->sprites[path] = sprite;

    return sprite;
}
