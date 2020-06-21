#include "SFMLAudioLoader.h"
#include "SFMLAudioClip.h"
#include "SFMLMusic.h"

SpaceInvaders::Assets::Audio::AudioClip* SFML::Assets::Audio::SFMLAudioLoader::loadAudioClip(std::string path)
{
    auto* loadedClip = AudioLoader::loadAudioClip(path);

    if(loadedClip != nullptr)
    {
        return loadedClip;
    }

    auto* clip = new SFMLAudioClip(path);
    this->audioClips[path] = clip;

    return clip;
}

SpaceInvaders::Assets::Audio::Music* SFML::Assets::Audio::SFMLAudioLoader::loadMusic(std::string path)
{
    auto* loadedMusic = AudioLoader::loadMusic(path);

    if(loadedMusic != nullptr)
    {
        return loadedMusic;
    }

    auto* mus = new SFMLMusic(path);
    this->music[path] = mus;

    return mus;
}

SFML::Assets::Audio::SFMLAudioLoader::~SFMLAudioLoader()
{
    for (auto music : audioClips)
    {
        delete music.second;
    }

    for (auto music : music)
    {
        delete music.second;
    }
}
