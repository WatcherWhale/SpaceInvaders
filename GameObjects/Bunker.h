#ifndef SPACEINVADERS_BUNKER_H
#define SPACEINVADERS_BUNKER_H

#include "GameObject.h"

namespace SpaceInvaders::GameObjects
{
    class Bunker : public GameObject
    {
    public:
        Bunker(int pos);
        Bunker(int pos, int health);

        void update(double deltaTime) override;

        void onCollision(GameObject* collided) override ;
        void loadSprites(Assets::Sprites::SpriteLoader* loader) override;
    private:
        int pos;
    };
}

#endif
