#include "SpriteLoader.h"
using namespace SpaceInvaders::Assets::Sprites;

std::map<std::string, Sprite*>* SpriteLoader::getSpriteMap()
{
    return &this->sprites;
}

Sprite* SpriteLoader::loadSprite(std::string path)
{
    if(this->sprites[path] != nullptr)
    {
        return this->sprites[path];
    }

    return nullptr;
}
