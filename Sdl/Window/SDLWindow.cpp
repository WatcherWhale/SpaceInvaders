#include "SDLWindow.h"
#include "../AssetLoaders/Sprites/SDLSprite.h"

#include <cmath>

using namespace SpaceInvaders;
using namespace SDL::Windows;

bool SDLWindow::create()
{
    if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0)
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return false;
    }
    else
    {
        if(!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
        {
            return false;
        }

        if(TTF_Init() == -1)
        {
            return false;
        }

        if(Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
        {
            printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
            return false;
        }

        this->window = SDL_CreateWindow(this->title.c_str(),
                SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                this->width, this->height, SDL_WINDOW_SHOWN);

        if(this->window == nullptr)
        {
            return false;
        }

        this->renderer = SDL_CreateRenderer( this->window, -1, SDL_RENDERER_ACCELERATED );

        if(this->isMaximized) SDL_SetWindowFullscreen(this->window, 1);

        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, 0);
        this->surface = SDL_GetWindowSurface(this->window);

        this->clear();
        SDL_UpdateWindowSurface(this->window);

        return true;
    }
}

void SDLWindow::destroy()
{
    if(this->backgroundMusic != nullptr) Mix_FreeMusic(this->backgroundMusic);

    SDL_SetWindowFullscreen(this->window, 0);
    SDL_DestroyWindow(this->window);

    TTF_Quit();
    IMG_Quit();
    Mix_Quit();
    SDL_Quit();
}

void SDLWindow::pollEvents()
{
    SDL_Event e;

    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);

    while( SDL_PollEvent(&e) != 0 )
    {
        switch (e.type)
        {
            case SDL_QUIT:
                Controllers::GameController::getInstance().stopGame();
                break;
            case SDL_KEYUP:
                this->HandleKeyEvent(false, e.key.keysym.sym);
                break;
            case SDL_KEYDOWN:
                this->HandleKeyEvent(true, e.key.keysym.sym);
                break;


            case SDL_MOUSEMOTION:
                Controllers::GameController::getInstance().getEventHandler()->mouseMove(mouseX, mouseY);
                break;
            case SDL_MOUSEBUTTONDOWN:
                Controllers::GameController::getInstance().getEventHandler()->mouseDown(mouseX, mouseY);
                break;
            case SDL_MOUSEBUTTONUP:
                Controllers::GameController::getInstance().getEventHandler()->mouseUp(mouseX, mouseY);
                break;
        }
    }
}

void SDLWindow::clear()
{
    SDL_RenderClear(this->renderer);
}

void SDLWindow::draw()
{
    this->clear();

    // Draw Background

    if(this->background != nullptr)
    {
        auto* backgroundSprite = dynamic_cast<Assets::Sprites::SDLSprite*>(this->background);

        SDL_Rect backRect;
        backRect.x = 0;
        backRect.y = 0;
        backRect.w = this->width;
        backRect.h = this->height;

        SDL_RenderCopy(this->renderer, reinterpret_cast<SDL_Texture*>(backgroundSprite->display()), nullptr, &backRect);
    }

    // DrawSprites

    while (!spriteQueue.empty())
    {
        auto container = spriteQueue.front();

        auto* sprite = container->sprite;
        auto* texture = reinterpret_cast<SDL_Texture*>(sprite->display());

        double offsetX = container->bounds[2] * container->bounds[0] * sprite->getWidth();
        double offsetY = container->bounds[3] * container->bounds[1] * sprite->getHeight();

        SDL_Rect stretchRect;
        stretchRect.x = container->position[0] + std::lround(offsetX);
        stretchRect.y = container->position[1] + std::lround(offsetY);
        stretchRect.w = std::lround(container->bounds[2] * sprite->getWidth());
        stretchRect.h = std::lround(container->bounds[3] * sprite->getHeight());

        SDL_RenderCopy(this->renderer, texture, nullptr, &stretchRect);

        spriteQueue.pop();
    }

    // Draw UI
    while(!this->uiQueue.empty())
    {
        auto* component = uiQueue.front();

        SDL_Texture* uiTexture = nullptr;
        do
        {
            auto container = component->display();
            uiTexture = static_cast<SDL_Texture*>(container.texture);
            SDL_Rect stretchRect;
            stretchRect.x = container.position[0];
            stretchRect.y = container.position[1];
            stretchRect.w = std::lround(container.size[0]);
            stretchRect.h = std::lround(container.size[1]);

            SDL_RenderCopy(this->renderer, uiTexture, nullptr, &stretchRect);
        } while(!component->doneDisplaying());

        uiQueue.pop();
    }

    // Update frame
    SDL_RenderPresent(this->renderer);

    // Wait for end of frame
    auto deltaTime = Controllers::GameController::getInstance().getTimer()->interval();

    if(deltaTime < GameConstants::FPS_TIME )
    {
        SDL_Delay(GameConstants::FPS_TIME - deltaTime );
    }
}

void SDLWindow::HandleKeyEvent(bool down, SDL_Keycode keycode)
{
    Key key = Key::NONE;

    switch (keycode)
    {
        case SDLK_UP:
            key = Key::UP;
        break;

        case SDLK_DOWN:
            key = Key::DOWN;
            break;

        case SDLK_LEFT:
            key = Key::LEFT;
            break;

        case SDLK_RIGHT:
            key = Key::RIGHT;
            break;

        case SDLK_SPACE:
            key = Key::SPACE;
            break;

        case SDLK_ESCAPE:
            Controllers::GameController::getInstance().stopGame();
            break;

        default:
            key = Key::NONE;
        break;
    }

    if(down)
    {
        Controllers::GameController::getInstance().getEventHandler()->onKeyDown(key);
    }
    else
    {
        Controllers::GameController::getInstance().getEventHandler()->onKeyUp(key);
    }
}

void SDLWindow::setIcon(SpaceInvaders::Assets::Sprites::Sprite* sprite)
{
    Window::setIcon(sprite);
    SDL_SetWindowIcon(this->window, reinterpret_cast<SDL_Surface*>(this->icon->display()));
}

SDL_Renderer* SDLWindow::getRenderer()
{
    return this->renderer;
}

