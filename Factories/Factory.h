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

namespace SpaceInvaders::Factories
{
    class GameFactory
    {
    public:
        UIFactory* getUiFactory();

        virtual Windows::Window* createWindow(void* game, std::string title, int width, int height) = 0;
        virtual Assets::Sprites::SpriteLoader* createSpriteLoader() = 0;
        virtual Assets::FontLoader* createFontLoader() = 0;

        GameObjects::Player* createPlayer();
        GameObjects::Alien* createAlien(int x, int y, int row, int type);
        GameObjects::Bullet* createBullet(int position[], int type);

    protected:
        UIFactory* uiFactory;
    };
}

#endif