#ifndef GAME_ALIEN_H
#define GAME_ALIEN_H

#include "GameObject.h"

namespace SpaceInvaders::GameObjects
{
    class Alien : public GameObject
    {
    public:
        Alien(int x, int y, int row, int column, int type);
        void update(double deltaTime) override;
        void loadSprites(Assets::Sprites::SpriteLoader* loader) override;
        bool isDead();
        bool isTouchingWall();
        void movePosition(int direction, bool down);
        void onCollision(GameObject* collided) override;
        void updateMult(double mult);

        int getRow();
        int getColumn();

    private:
        int type;
        bool dead = false;
        bool down = false;
        int moveDirection = 0;
        double speedMult = 1;

        int row = 0;
        int column = 0;
    };
}

#endif //GAME_ALIEN_H
