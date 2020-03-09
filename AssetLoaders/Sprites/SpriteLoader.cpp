#include "SpriteLoader.h"
using namespace SpaceInvaders::Assets::Sprites;

std::map<std::string, Sprite*>* SpriteLoader::getSpriteMap()
{
    return &this->sprites;
}