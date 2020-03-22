#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include "GameObject.h"
#include "../Events/EventListener.h"
#include "../GameConstants.h"

namespace SpaceInvaders::GameObjects
{
    class Player : public GameObject, public SpaceInvaders::Events::EventListener
    {
    public:
        Player();
        void update(double deltaTime) override;
        void onKeyUp(Events::Key key) override;
        void onKeyDown(Events::Key key) override;

        void onCollision(GameObject* collided) override ;


        void loadSprites(Assets::Sprites::SpriteLoader* loader) override;

    private:
        void shoot();
        void endShoot();

        bool spaceDown = false;
        bool shooting = false;
        int bulletSpawn[2] = {0, 0};

        int moveDirection = 0;
        double speed = PLAYER_SPEED;
    };
}

#endif
