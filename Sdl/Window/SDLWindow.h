#ifndef SDL_WINDOW_H
#define SDL_WINDOW_H

#include "../../Windows/Window.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include "../../Game.h"
#include "../../GameConstants.h"

using namespace SpaceInvaders::Windows;

namespace SpaceInvaders::Windows
{
    class SDLWindow : public Window
    {
    public:
        SDLWindow(void* game, std::string title, int width, int height) :
            Window(game, title, width, height, WINDOW_IS_MAXIMIZED){};

        bool create() override;
        void destroy() override;
        void pollEvents() override;
        void draw() override;
        void clear() override;
        uint32_t getDeltaTime() override;
        void setIcon(Assets::Sprites::Sprite* sprite) override;

    private:
        void HandleKeyEvent(bool down, SDL_Keycode keycode);

        SDL_Window* window = nullptr;
        SDL_Surface* surface = nullptr;
        SDL_Renderer* renderer = nullptr;
        Mix_Music* backgroundMusic = nullptr;
        Uint32 startime = 0;
        Uint32 deltaTime = 0;
    };
}

#endif
