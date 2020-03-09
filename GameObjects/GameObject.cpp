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

int* GameObject::getCollider()
{
    this->calculateCollider();
    return this->collider;
}

void GameObject::calculateCollider()
{
    collider[0] = std::lround(this->position[0] - this->bounds[2] * this->bounds[0]);
    collider[1] = std::lround(this->position[1] - this->bounds[3] * this->bounds[1]);
    collider[2] = std::lround(this->position[0] - this->bounds[2] * this->bounds[0]);
    collider[3] = std::lround(this->position[1] - this->bounds[3] * this->bounds[1]);
}

bool GameObject::checkCollison(GameObject* go1, GameObject* go2)
{
    return ((go1->collider[0] >= go2->collider[0] && go1->collider[0] >= go2->collider[2]) ||
            (go1->collider[2] >= go2->collider[0] && go1->collider[2] >= go2->collider[2])) &&
            ((go1->collider[1] >= go2->collider[1] && go1->collider[1] >= go2->collider[3]) ||
            (go1->collider[3] >= go2->collider[1] && go1->collider[3] >= go2->collider[3]));
}

void GameObject::move(double dx, double dy)
{
    this->dPosition[0] += dx;
    this->dPosition[1] += dy;

    this->position[0] = std::lround(this->dPosition[0]);
    this->position[1] = std::lround(this->dPosition[1]);
}

GameObject::~GameObject()
{
    for(auto* sprite : this->sprites)
    {
        delete sprite;
    }
}
