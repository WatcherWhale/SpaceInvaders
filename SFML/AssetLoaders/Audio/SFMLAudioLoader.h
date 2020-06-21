#ifndef SPACEINVADERS_SFMLAUDIOLOADER_H
#define SPACEINVADERS_SFMLAUDIOLOADER_H

#include "../../../AssetLoaders/Audio/AudioLoader.h"

using namespace SpaceInvaders::Assets::Audio;

namespace SFML::Assets::Audio
{
    class SFMLAudioLoader : public AudioLoader
    {
    public:
        ~SFMLAudioLoader();
        AudioClip* loadAudioClip(std::string path);
        Music* loadMusic(std::string path);
    };
}

#endif
