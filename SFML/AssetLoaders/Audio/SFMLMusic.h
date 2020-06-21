#ifndef SPACEINVADERS_SFMLMUSIC_H
#define SPACEINVADERS_SFMLMUSIC_H


#include <string>
#include "../../../AssetLoaders/Audio/Music.h"
#include <SFML/Audio.hpp>

using namespace SpaceInvaders::Assets::Audio;

namespace SFML::Assets::Audio
{
    class SFMLMusic : public Music
    {
    public:
        SFMLMusic(std::string path);
        ~SFMLMusic() override;
        void play(bool loop) override;
        void pause() override;
        void resume() override;
    private:
        sf::Music* music;
    };
}

#endif
