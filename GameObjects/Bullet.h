
#ifndef SPACEINVADERS_BULLET_H
#define SPACEINVADERS_BULLET_H

#include "GameObject.h"
#include "../Events/EventListener.h"

namespace SpaceInvaders::GameObjects
{
    class Bullet : public GameObject
    {
    public:
        Bullet(int position[], int type);
        void update(double deltaTime) override;
        void loadSprites(Assets::Sprites::SpriteLoader* loader) override;

        bool isPlayerBullet();

        GameObject* getKilled();

        void onCollision(GameObject* collided) override ;

    private:
        int type;
        GameObject* killed;
    };
}
#endif
