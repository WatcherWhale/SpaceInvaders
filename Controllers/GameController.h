#ifndef GAME_GAMECONTROLLER_H
#define GAME_GAMECONTROLLER_H

#include "../Events/EventHandler.h"
#include "../Scenes/Scene.h"
#include "../Utils/Timer.h"

namespace SpaceInvaders::Controllers
{
    enum SceneEnum {LOAD, MENU, GAME, GAMEOVER};

    class GameController
    {
    public:
        GameController();

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

        void addPoints(int points);
        int getPoints();
        void clearPoints();
        void resetLevel();
        int getLevel();
        int getLives();
        void setLives(int lives);

        Events::EventHandler* getEventHandler();

        void setFactory(Factories::GameFactory* factory);
        void setWindow(Windows::Window* window);
        Factories::GameFactory* getFactory();
        Windows::Window* getWindow();
        Assets::Sprites::SpriteLoader* getSpriteLoader();
        Assets::FontLoader* getFontLoader();
        Assets::Audio::AudioLoader* getAudioLoader();
        Utils::Timer* getTimer();

        void stopGame();
        bool isRunning();
        void unload();

    private:
        Events::EventHandler* eventHandler = nullptr;

        Factories::GameFactory* factory = nullptr;
        Assets::Sprites::SpriteLoader* spriteLoader = nullptr;
        Assets::Audio::AudioLoader* audioLoader = nullptr;
        Assets::FontLoader* fontLoader = nullptr;
        Utils::Timer* timer = nullptr;

        Windows::Window* window = nullptr;
        Scenes::Scene* currentScene = nullptr;

        int currentLevel = 0;
        int lives = 3;
        int points = 0;
        bool running = true;
    };
}
#endif
