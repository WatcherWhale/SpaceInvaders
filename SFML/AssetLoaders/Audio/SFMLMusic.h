#ifndef SPACEINVADERS_SFMLMUSIC_H
#define SPACEINVADERS_SFMLMUSIC_H


#include <string>
#include "../../../AssetLoaders/Audio/AudioClip.h"
#include <SFML/Audio.hpp>

using namespace SpaceInvaders::Assets::Audio;

namespace SFML::Assets::Audio
{
    class SFMLMusic : public AudioClip
    {
    public:
        SFMLMusic(std::string path);
        ~SFMLMusic() override;
        void play() override;
    private:
        sf::Music* music;
    };
}

#endif
