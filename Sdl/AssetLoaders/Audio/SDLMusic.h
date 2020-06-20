#ifndef SPACEINVADERS_SDLMUSIC_H
#define SPACEINVADERS_SDLMUSIC_H

#include <SDL2/SDL_mixer.h>
#include <string>
#include "../../../AssetLoaders/Audio/Music.h"

using namespace SpaceInvaders::Assets::Audio;

namespace SDL::Assets::Audio
{
    class SDLMusic : public Music
    {
    public:
        SDLMusic(std::string path);
        ~SDLMusic();
        void play(bool loop) override;
        void pause() override;
        void resume() override;
    private:
        Mix_Music* music_clip;
    };
}
#endif
