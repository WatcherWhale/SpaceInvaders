#ifndef GAME_FACTORY_H
#define GAME_FACTORY_H

#include <string>

#include "../Windows/Window.h"
#include "../AssetLoaders/Sprites/SpriteLoader.h"
#include "../AssetLoaders/FontLoader.h"
#include "../GameObjects/Player.h"
#include "../GameObjects/Alien.h"
#include "../GameObjects/Bullet.h"
#include "UIFactory.h"
#include "../Utils/Timer.h"
#include "../GameObjects/Bonus.h"

namespace SpaceInvaders::Factories
{
    class GameFactory
    {
    public:
        UIFactory* getUiFactory();

        virtual Windows::Window* createWindow(void* game, std::string title, int width, int height, bool isMaximized) = 0;
        virtual Assets::Sprites::SpriteLoader* createSpriteLoader() = 0;
        virtual Assets::FontLoader* createFontLoader() = 0;
        virtual Utils::Timer* createTimer() = 0;

        GameObjects::Player* createPlayer(int lives);
        GameObjects::Alien* createAlien(int x, int y, int row, int column, int type);
        GameObjects::Bullet* createBullet(int position[], int type);
        GameObjects::Bonus* createBonus(double xPos, double direction);

    protected:
        UIFactory* uiFactory;
    };
}

#endif