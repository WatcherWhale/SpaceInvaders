#include "SFMLMusic.h"

#include "../../../GameConstants.h"

using namespace SpaceInvaders;

SFML::Assets::Audio::SFMLMusic::SFMLMusic(std::string path)
{
    this->music = new sf::Music();
    this->music->openFromFile(path);
    this->music->setVolume((float) GameConstants::CLIP_VOLUME);
    this->music->setLoop(true);
}

SFML::Assets::Audio::SFMLMusic::~SFMLMusic()
{
    delete this->music;
}

void SFML::Assets::Audio::SFMLMusic::play()
{
    this->music->play();
}
