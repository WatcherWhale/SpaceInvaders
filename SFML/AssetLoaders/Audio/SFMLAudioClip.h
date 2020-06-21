#ifndef SPACEINVADERS_SFMLAUDIOCLIP_H
#define SPACEINVADERS_SFMLAUDIOCLIP_H

#include <string>
#include "../../../AssetLoaders/Audio/AudioClip.h"
#include <SFML/Audio.hpp>

using namespace SpaceInvaders::Assets::Audio;

namespace SFML::Assets::Audio
{
    class SFMLAudioClip : public AudioClip
    {
    public:
        SFMLAudioClip(std::string path);
        ~SFMLAudioClip() override;
        void play() override;
    private:
        sf::Music* music;
    };
}

#endif
