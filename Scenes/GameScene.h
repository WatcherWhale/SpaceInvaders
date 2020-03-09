#ifndef GAME_GAMESCENE_H
#define GAME_GAMESCENE_H

#include "Scene.h"
namespace SpaceInvaders::Scenes
{
    class GameScene : public Scene
    {
    public:
        ~GameScene() override;
        void update(double deltaTime) override;
    };
}
#endif
