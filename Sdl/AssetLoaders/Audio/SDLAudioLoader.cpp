#include "SDLAudioLoader.h"
#include "SDLMusic.h"
#include "SDLAudioClip.h"

SpaceInvaders::Assets::Audio::AudioClip* SpaceInvaders::Assets::Audio::SDLAudioLoader::loadAudioClip(std::string path)
{
    auto* loadedClip = AudioLoader::loadAudioClip(path);

    if(loadedClip != nullptr)
    {
        return loadedClip;
    }

    auto* clip = new SDLAudioClip(path);
    this->audioClips[path] = clip;

    return clip;
}

SpaceInvaders::Assets::Audio::Music* SpaceInvaders::Assets::Audio::SDLAudioLoader::loadMusic(std::string path)
{
    auto* loadedMusic = AudioLoader::loadMusic(path);

    if(loadedMusic != nullptr)
    {
        return loadedMusic;
    }

    auto* mus = new SDLMusic(path);
    this->music[path] = mus;

    return mus;
}

SpaceInvaders::Assets::Audio::SDLAudioLoader::~SDLAudioLoader()
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
