#include <cmath>
#include "GameObject.h"
#include "../GameConstants.h"

using namespace SpaceInvaders::GameObjects;

GameObject::GameObject()
{
    this->position[0] = 0;
    this->position[1] = 0;

    this->dPosition[0] = 0;
    this->dPosition[1] = 0;

    this->bounds[0] = -0.5; // Top x coor = x - 1/2 * w
    this->bounds[1] = -0.5; // Top y coor = y - 1/2 * h
    this->bounds[2] = SPRITE_SCALE * SCALE_X; // w
    this->bounds[3] = SPRITE_SCALE * SCALE_Y; // h

    collider[0] = -0.5;
    collider[1] = -0.5;
    collider[2] = 0.5;
    collider[3] = 0.5;
}

int* GameObject::getPosition()
{
    return this->position;
}

double* GameObject::getBounds()
{
    return this->bounds;
}

void GameObject::loadSprites(SpaceInvaders::Assets::Sprites::Sprite* sprite, int amount)
{
    for (int i = 0; i < amount; ++i)
    {
        this->sprites.push_back(sprite + i);
    }
}

SpaceInvaders::Assets::Sprites::Sprite* GameObject::getSprite()
{
    return this->sprites.at(this->currentSprite);
}

double* GameObject::getCollider()
{
    return this->collider;
}

bool GameObject::checkCollison(GameObject* go1, GameObject* go2)
{
    double x11 = go1->dPosition[0] + go1->collider[0] * go1->bounds[2] * IMPORT_SPRITE_SIZE;
    double x12 = go1->dPosition[0] + go1->collider[2] * go1->bounds[2] * IMPORT_SPRITE_SIZE;
    double x21 = go2->dPosition[0] + go2->collider[0] * go2->bounds[2] * IMPORT_SPRITE_SIZE;
    double x22 = go2->dPosition[0] + go2->collider[2] * go2->bounds[2] * IMPORT_SPRITE_SIZE;

    double y11 = go1->dPosition[1] + go1->collider[1] * go1->bounds[3] * IMPORT_SPRITE_SIZE;
    double y12 = go1->dPosition[1] + go1->collider[3] * go1->bounds[3] * IMPORT_SPRITE_SIZE;
    double y21 = go2->dPosition[1] + go2->collider[1] * go2->bounds[3] * IMPORT_SPRITE_SIZE;
    double y22 = go2->dPosition[1] + go2->collider[3] * go2->bounds[3] * IMPORT_SPRITE_SIZE;

    bool x = (x11 >= x21 && x11 <= x22) || (x12 >= x21 && x12 <= x22);
    bool y = (y11 >= y21 && y11 <= y22) || (y12 >= y21 && y12 <= y22);

    return x && y;
}

void GameObject::move(double dx, double dy)
{
    this->dPosition[0] += dx;
    this->dPosition[1] += dy;

    this->position[0] = std::lround(this->dPosition[0]);
    this->position[1] = std::lround(this->dPosition[1]);
}

bool GameObject::isOutOfScreenY()
{
    return this->position[1] < std::lround(this->bounds[3]) || this->position[1] > std::lround(this->bounds[3]) + WINDOW_SIZE_Y;
}

GameObjectTag GameObject::getTag()
{
    return this->tag;
}

bool GameObject::isRemovable()
{
    return this->remove;
}
