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
        void load(Factories::GameFactory* factory, Assets::Sprites::SpriteLoader* loader) override;
        void draw(Windows::Window* window) override;

        Controllers::LevelController* getLvlController();

    private:
        Controllers::LevelController* lvlController;
        Assets::Sprites::Sprite* background;
    };
}
#endif
