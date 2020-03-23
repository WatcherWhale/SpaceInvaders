#ifndef GAME_FACTORY_H
#define GAME_FACTORY_H

#include <string>

#include "../Windows/Window.h"
#include "../AssetLoaders/Sprites/SpriteLoader.h"
#include "../AssetLoaders/FontLoader.h"
#include "../GameObjects/Player.h"
#include "../GameObjects/Alien.h"
#include "../UI/Text.h"
#include "../GameObjects/Bullet.h"

namespace SpaceInvaders::Factories
{
    class GameFactory
    {
    public:
        virtual Windows::Window* createWindow(void* game, std::string title, int width, int height) = 0;
        virtual Assets::Sprites::SpriteLoader* createSpriteLoader() = 0;
        virtual Assets::FontLoader* createFontLoader() = 0;
        virtual UI::Text* createText(std::string text, void* font, Color color, int x, int y) = 0;
        virtual UI::Text* createText(std::string text, void* font, Color color, int x, int y, int w, int h) = 0;

        GameObjects::Player* createPlayer();
        GameObjects::Alien* createAlien(int x, int y, int row, int type);
        GameObjects::Bullet* createBullet(int position[], int type);
    };
}

#endif