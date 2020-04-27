#include "AudioLoader.h"

SpaceInvaders::Assets::Audio::AudioClip* SpaceInvaders::Assets::Audio::AudioLoader::loadAudioClip(std::string path)
{
    return this->audioClips[path];
}

SpaceInvaders::Assets::Audio::Music* SpaceInvaders::Assets::Audio::AudioLoader::loadMusic(std::string path)
{
    return this->music[path];
}
