#ifndef GAME_ENEMYCONTROLLER_H
#define GAME_ENEMYCONTROLLER_H

#include <vector>
#include "../Factories/Factory.h"

const unsigned int X_SPACING = 100;
const unsigned int Y_SPACING = 0;

namespace SpaceInvaders::Controllers
{
    class EnemyController
    {
    public:
        void createEnemies(int level, Factories::GameFactory* factory);
        void update(double deltaTime);
        void loadSprites(Assets::Sprites::SpriteLoader* loader);

        std::vector<SpaceInvaders::GameObjects::Alien*>* getEnemies();

        int getCurrentRow();

    private:
        std::vector<SpaceInvaders::GameObjects::Alien*> enemies;
        int direction = -1;
        int currentRow = 0;
        bool handledMovementUpdate = false;
    };
}

#endif //GAME_ENEMYCONTROLLER_H
