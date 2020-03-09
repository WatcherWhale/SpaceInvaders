#include "SDLSpriteLoader.h"
#include "SDLSprite.h"

using namespace SpaceInvaders::Assets::Sprites;

SDLSpriteLoader::~SDLSpriteLoader()
{
    for(auto sprite : this->sprites)
    {
        sprite.second->unload();
    }
}


Sprite* SDLSpriteLoader::loadSprite(std::string path)
{
    if(this->sprites[path] != nullptr)
    {
        return this->sprites[path];
    }

    Sprite* sprite = new SDLSprite(path);
    sprite->load();

    this->sprites[path] = sprite;

    return sprite;
}
