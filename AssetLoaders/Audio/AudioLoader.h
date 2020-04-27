#ifndef SPACEINVADERS_AUDIOLOADER_H
#define SPACEINVADERS_AUDIOLOADER_H

#include <map>
#include <string>
#include "AudioClip.h"
#include "Music.h"

namespace SpaceInvaders::Assets::Audio
{
    class AudioLoader
    {
    public:
        virtual ~AudioLoader() = default;
        virtual AudioClip* loadAudioClip(std::string path);
        virtual Music* loadMusic(std::string path);

    protected:
        std::map<std::string, AudioClip*> audioClips;
        std::map<std::string, Music*> music;
    };
}
#endif
