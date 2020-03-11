#ifndef GAME_ALIEN_H
#define GAME_ALIEN_H

#include "GameObject.h"

namespace SpaceInvaders::GameObjects
{
    class Alien : public GameObject
    {
    public:
        Alien(int x, int y, int row, int type);
        void update(double deltaTime) override;
        void loadSprites(Assets::Sprites::SpriteLoader* loader) override;
        bool isDead();
        bool isTouchingWall();
        void movePosition(int direction, bool down);
        void onCollision(GameObject* collided) override;
    private:
        int type;
        bool dead = false;
        bool down = false;
        int moveDirection = 0;

        int row = 0;
    };
}

#endif //GAME_ALIEN_H
