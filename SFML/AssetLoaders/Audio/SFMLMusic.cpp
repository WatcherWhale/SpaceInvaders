#include "SFMLMusic.h"

#include "../../../GameConstants.h"

using namespace SpaceInvaders;

SFML::Assets::Audio::SFMLMusic::SFMLMusic(std::string path)
{
    this->music = new sf::Music();
    this->music->openFromFile(path);
    this->music->setVolume((float) GameConstants::CLIP_VOLUME);
}

SFML::Assets::Audio::SFMLMusic::~SFMLMusic()
{
    delete this->music;
}

void SFML::Assets::Audio::SFMLMusic::play(bool loop)
{
    this->music->setLoop(true);
    this->music->play();
}

void SFML::Assets::Audio::SFMLMusic::pause()
{
    this->music->pause();
}

void SFML::Assets::Audio::SFMLMusic::resume()
{
    this->music->play();
}
