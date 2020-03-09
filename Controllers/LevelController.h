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

        void startLevel(Factories::GameFactory* factory, Assets::Sprites::SpriteLoader* loader);
        bool isLevelStarted();

    private:
        GameObjects::Player* player;
        EnemyController enemyController;
        bool levelStarted = false;
        int currentLevel = 0;
        int currentScene = 0;
    };
}

#endif //GAME_LEVELCONTROLLER_H
