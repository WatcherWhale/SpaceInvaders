#include "SDLAudioClip.h"
#include "../../../GameConstants.h"

using namespace SpaceInvaders;

SDL::Assets::Audio::SDLAudioClip::SDLAudioClip(std::string path)
{
    Mix_Volume(-1, GameConstants::CLIP_VOLUME);
    this->chunk = Mix_LoadWAV(path.c_str());
}

void SDL::Assets::Audio::SDLAudioClip::play()
{
    Mix_PlayChannel(-1, chunk, 0);
}

SDL::Assets::Audio::SDLAudioClip::~SDLAudioClip()
{
    Mix_FreeChunk(chunk);
}
