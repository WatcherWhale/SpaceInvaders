#ifndef SPACEINVADERS_SDLAUDIOLOADER_H
#define SPACEINVADERS_SDLAUDIOLOADER_H

#include "../../../AssetLoaders/Audio/AudioLoader.h"

namespace  SpaceInvaders::Assets::Audio
{
    class SDLAudioLoader : public AudioLoader
    {
    public:
        ~SDLAudioLoader();
        AudioClip* loadAudioClip(std::string path);
        Music* loadMusic(std::string path);
    };
}

#endif
