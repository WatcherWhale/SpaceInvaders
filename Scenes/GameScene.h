#ifndef GAME_GAMESCENE_H
#define GAME_GAMESCENE_H

#include "Scene.h"
#include "../Controllers/LevelController.h"

namespace SpaceInvaders::Scenes
{
    class GameScene : public Scene
    {
    public:
        GameScene();
        ~GameScene() override;
        void update(double deltaTime) override;
        void lateUpdate() override;
        void load() override;

        void startLevel(int level, Factories::GameFactory* factory, Assets::Sprites::SpriteLoader* spriteLoader);

        Controllers::LevelController* getLvlController();

    private:
        Controllers::LevelController lvlController;
        UI::Text* ptsText;
        UI::Text* livesText;
        UI::Text* levelText;
    };
}
#endif
