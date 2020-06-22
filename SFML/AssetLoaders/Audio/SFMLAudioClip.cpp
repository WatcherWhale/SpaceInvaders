#include "SFMLAudioClip.h"
#include "../../../GameConstants.h"

using namespace SpaceInvaders;

SFML::Assets::Audio::SFMLAudioClip::SFMLAudioClip(std::string path)
{
    this->music = new sf::Music();
    this->music->openFromFile(path);
    this->music->setVolume((float) GameConstants::CLIP_VOLUME);
}

SFML::Assets::Audio::SFMLAudioClip::~SFMLAudioClip()
{
    delete this->music;
}

void SFML::Assets::Audio::SFMLAudioClip::play()
{
    this->music->stop();
    this->music->play();
}
