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
        Player(int lives);
        void update(double deltaTime) override;
        void onKeyUp(Events::Key key) override;
        void onKeyDown(Events::Key key) override;

        void onCollision(GameObject* collided) override ;

        void loadSprites(Assets::Sprites::SpriteLoader* loader) override;

        int getLives();
        void setLives(int lives);

    private:
        void shoot();
        void endShoot();

        bool spaceDown = false;
        bool shooting = false;

        int moveDirection = 0;
        int lives = 3;
        double speed = GameConstants::PLAYER_SPEED * GameConstants::SCALE_X;
    };
}

#endif
