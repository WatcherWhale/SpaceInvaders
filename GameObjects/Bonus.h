#ifndef SPACEINVADERS_BONUS_H
#define SPACEINVADERS_BONUS_H

#include "GameObject.h"

namespace SpaceInvaders::GameObjects
{
    class Bonus : public GameObject
    {
    public:
        Bonus(double xPos, double direction);
        void update(double deltaTime) override;
        void onCollision(GameObject* collided) override;
        void loadSprites(Assets::Sprites::SpriteLoader* loader) override;
    private:
        double direction;
    };
}

#endif
