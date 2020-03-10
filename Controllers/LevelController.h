#ifndef GAME_LEVELCONTROLLER_H
#define GAME_LEVELCONTROLLER_H

#include "EnemyController.h"
#include "../Scenes/Scene.h"

namespace SpaceInvaders::Controllers
{
    class LevelController
    {
    public:
        LevelController();

        void setPlayer(GameObjects::Player* player);
        GameObjects::Player* getPlayer();
        EnemyController* getEnemyController();

        void startLevel(int level, Factories::GameFactory* factory, Assets::Sprites::SpriteLoader* loader);

    private:
        GameObjects::Player* player = nullptr;
        EnemyController enemyController;
        int currentLevel = 0;
    };
}

#endif //GAME_LEVELCONTROLLER_H
