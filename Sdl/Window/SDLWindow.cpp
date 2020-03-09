#include "SDLWindow.h"
#include "../../Game.h"
#include "../AssetLoaders/Sprites/SDLSprite.h"

#include <cmath>

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

        SDL_SetWindowFullscreen(this->window, 1);

        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, 0);
        this->surface = SDL_GetWindowSurface(this->window);

        this->clear();
        SDL_UpdateWindowSurface(this->window);

        //Start background music
        //this->backgroundMusic = Mix_LoadMUS(this->backgroundMusicPath.c_str());
        //Mix_PlayMusic(this->backgroundMusic, -1 );

        return true;
    }
}

void SDLWindow::destroy()
{
    Mix_FreeMusic(this->backgroundMusic);

    SDL_DestroyWindow(this->window);

    TTF_Quit();
    IMG_Quit();
    Mix_Quit();
    SDL_Quit();
}

void SDLWindow::pollEvents()
{
    SDL_Event e;
    Game* game = reinterpret_cast<Game*>(this->game);

    while( SDL_PollEvent(&e) != 0 )
    {
        switch (e.type)
        {
            case SDL_QUIT:
                game->stop();
                break;
            case SDL_KEYUP:
                this->HandleKeyEvent(false, e.key.keysym.sym);
                break;
            case SDL_KEYDOWN:
                this->HandleKeyEvent(true, e.key.keysym.sym);
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
    Uint32 ticks = SDL_GetTicks();

    if(startime == 0) startime = ticks;

    if(this->background != nullptr)
    {
        auto* backgroundSprite = dynamic_cast<Assets::Sprites::SDLSprite*>(this->background);
        if(!backgroundSprite->hasTexture()) backgroundSprite->texturize(this->renderer);

        SDL_Rect backRect;
        backRect.x = 0;
        backRect.y = 0;
        backRect.w = this->width;
        backRect.h = this->height;

        SDL_RenderCopy(this->renderer, reinterpret_cast<SDL_Texture*>(backgroundSprite->display()), nullptr, &backRect);
    }

    while (!spriteQueue.empty())
    {
        auto container = spriteQueue.front();

        auto* sprite = dynamic_cast<Assets::Sprites::SDLSprite*>(container->sprite);

        if(!sprite->hasTexture()) sprite->texturize(this->renderer);

        SDL_Texture* texture = reinterpret_cast<SDL_Texture*>(sprite->display());
        SDL_Rect stretchRect;

        double offsetX = container->bounds[2] * container->bounds[0] * sprite->getWidth();
        double offsetY = container->bounds[3] * container->bounds[1] * sprite->getHeight();

        stretchRect.x = container->position[0] + std::lround(offsetX);
        stretchRect.y = container->position[1] + std::lround(offsetY);
        stretchRect.w = std::lround(container->bounds[2] * sprite->getWidth());
        stretchRect.h = std::lround(container->bounds[3] * sprite->getHeight());

        SDL_RenderCopy(this->renderer, texture, nullptr, &stretchRect);

        spriteQueue.pop();
    }

    while(!this->textQueue.empty())
    {
        auto* txt = textQueue.front();

        auto* txtSurface = reinterpret_cast<SDL_Surface*>(txt->getTextTexture());
        auto* txtTexture = SDL_CreateTextureFromSurface( this->renderer, txtSurface );

        SDL_Rect stretchRect;
        stretchRect.x = txt->getPosition()[0];
        stretchRect.y = txt->getPosition()[1];
        stretchRect.w = std::lround(SCALE_X * txt->getSize()[0]);
        stretchRect.h = std::lround(SCALE_Y * txt->getSize()[1]);

        SDL_RenderCopy(this->renderer, txtTexture, nullptr, &stretchRect);

        textQueue.pop();
    }

    SDL_RenderPresent(this->renderer);

    Uint32 frameTicks = SDL_GetTicks() - ticks;
    if( frameTicks < TIME_120FPS )
    {
        SDL_Delay( TIME_120FPS - frameTicks );
    }

    this->deltaTime = SDL_GetTicks() - ticks;
}

void SDLWindow::HandleKeyEvent(bool down, SDL_Keycode keycode)
{
    Game* game = reinterpret_cast<Game*>(this->game);

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
            game->stop();
            break;

        default:
            key = Key::NONE;
        break;
    }

    if(down)
    {
        game->getEventHandler()->onKeyDown(key);
    }
    else
    {
        game->getEventHandler()->onKeyUp(key);
    }
}

uint32_t SDLWindow::getDeltaTime()
{
    return this->deltaTime;
}

void SDLWindow::setIcon(SpaceInvaders::Assets::Sprites::Sprite* sprite)
{
    Window::setIcon(sprite);
    SDL_SetWindowIcon(this->window, reinterpret_cast<SDL_Surface*>(this->icon->display()));
}
