#include "SDLMusic.h"
#include "../../../GameConstants.h"

SDL::Assets::Audio::SDLMusic::SDLMusic(std::string path)
{
    this->music_clip = Mix_LoadMUS(path.c_str());
    Mix_VolumeMusic(GameConstants::MUSIC_VOLUME);
}

void SDL::Assets::Audio::SDLMusic::play(bool loop)
{
    Mix_PlayMusic(this->music_clip, loop);
}

void SDL::Assets::Audio::SDLMusic::pause()
{
    Mix_PauseMusic();
}

void SDL::Assets::Audio::SDLMusic::resume()
{
    Mix_ResumeMusic();
}

SDL::Assets::Audio::SDLMusic::~SDLMusic()
{
    Mix_FreeMusic(music_clip);
}
