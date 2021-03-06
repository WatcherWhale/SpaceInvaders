#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <queue>
#include "../AssetLoaders/Sprites/Sprite.h"
#include "../Color.h"
#include "../UI/Text.h"

namespace SpaceInvaders::Windows
{
    struct SpriteContainer
    {
        Assets::Sprites::Sprite* sprite;
        int* position;
        double* bounds;
    };

    class Window
    {
    public:
        Window(void* game, std::string title, int width, int height, bool isMaximized);
        void setClearColor(Color col);
        void setClearColor(uint8_t r, uint8_t g, uint8_t b);
        Color getClearColor();

        virtual bool create() = 0;
        virtual void destroy() = 0;

        virtual void pollEvents() = 0;

        void queueSprite(Assets::Sprites::Sprite* sprite, int* position, double* bounds);
        void queueUI(UI::UIComponent* component);

        virtual void draw() = 0;
        virtual void clear() = 0;
        void setBackground(Assets::Sprites::Sprite* sprite);
        virtual void setIcon(Assets::Sprites::Sprite* sprite);
        void setBackgroundMusic(std::string path);

    protected:
        std::string title;
        int width, height;
        void* game;
        std::queue<SpriteContainer*> spriteQueue;
        std::queue<UI::UIComponent*> uiQueue;
        Color clearColor = Color(0xFF, 0xFF, 0xFF);
        Assets::Sprites::Sprite* background = nullptr;
        Assets::Sprites::Sprite* icon = nullptr;
        bool isMaximized;
        std::string backgroundMusicPath;
    };
}

#endif // !WINDOW_H
