#ifndef SPACEINVADERS_SDLAUDIOCLIP_H
#define SPACEINVADERS_SDLAUDIOCLIP_H

#include <string>
#include <SDL2/SDL_mixer.h>
#include "../../../AssetLoaders/Audio/AudioClip.h"

namespace  SpaceInvaders::Assets::Audio
{
    class SDLAudioClip : public AudioClip
    {
    public:
        SDLAudioClip(std::string path);
        ~SDLAudioClip();
        void play();
    private:
        Mix_Chunk* chunk;
    };
}
#endif
