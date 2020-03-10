#ifndef GAME_GAMECONTROLLER_H
#define GAME_GAMECONTROLLER_H

#include "../Events/EventHandler.h"
#include "../Scenes/Scene.h"

namespace SpaceInvaders::Controllers
{
    enum SceneEnum {MENU, GAME};

    class GameController
    {
    public:
        GameController(Factories::GameFactory* factory);
        ~GameController();

        void loadScene(SceneEnum scene);
        Scenes::Scene* getCurrentScene();
        Events::EventHandler* getEventHandler();

    private:
        Events::EventHandler* eventHandler;
        Scenes::Scene* currentScene = nullptr;
        Factories::GameFactory* factory;
        Assets::Sprites::SpriteLoader* spriteLoader;
        int currentLevel = 0;
    };
}
#endif
