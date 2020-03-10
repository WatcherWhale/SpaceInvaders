#ifndef GAME_GAMECONTROLLER_H
#define GAME_GAMECONTROLLER_H

#include "../Events/EventHandler.h"
#include "../Scenes/Scene.h"

namespace SpaceInvaders::Controllers
{
    enum SceneEnum {LOAD, MENU, GAME};

    class GameController
    {
    public:
        GameController();
        ~GameController();

        // Define a singleton
        static GameController& getInstance()
        {
            static GameController instance;
            return instance;
        }

        GameController(GameController const&) = delete;
        void operator=(GameController const&) = delete;

        void loadScene(SceneEnum scene);
        Scenes::Scene* getCurrentScene();
        Events::EventHandler* getEventHandler();

        void setFactory(Factories::GameFactory* factory);
        Factories::GameFactory* getFactory();
        Assets::Sprites::SpriteLoader* getSpriteLoader();
        Assets::FontLoader* getFontLoader();

    private:
        Events::EventHandler* eventHandler;
        Scenes::Scene* currentScene = nullptr;
        Factories::GameFactory* factory;
        Assets::Sprites::SpriteLoader* spriteLoader;
        Assets::FontLoader* fontLoader;
        int currentLevel = 0;
    };
}
#endif
